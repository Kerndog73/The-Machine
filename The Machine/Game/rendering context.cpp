//
//  rendering context.cpp
//  Catastrophe
//
//  Created by Indi Kernick on 4/9/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "rendering context.hpp"

#include <SDL2/SDL.h>
#include <Simpleton/SDL/error.hpp>
#include <Simpleton/OpenGL/opengl.hpp>

void RenderingContext::init(SDL_Window *newWindow) {
  initImpl(newWindow, false);
  minFrameTime = 0;
}

void RenderingContext::initLimitFPS(SDL_Window *newWindow, const uint32_t fps) {
  SDL_DisplayMode mode;
  CHECK_SDL_ERROR(SDL_GetWindowDisplayMode(newWindow, &mode));
  if (mode.refresh_rate == static_cast<int>(fps)) {
    minFrameTime = 1000 / (fps + 10);
    initImpl(newWindow, true);
  } else {
    minFrameTime = 1000 / fps;
    initImpl(newWindow, false);
  }
}

void RenderingContext::initVSync(SDL_Window *newWindow) {
  SDL_DisplayMode mode;
  CHECK_SDL_ERROR(SDL_GetWindowDisplayMode(newWindow, &mode));
  if (mode.refresh_rate == 0) {
    minFrameTime = 1000 / 70;
  } else {
    minFrameTime = 1000 / (mode.refresh_rate + 10);
  }
  initImpl(newWindow, true);
}

void RenderingContext::quit() {
  context = nullptr;
  window = nullptr;
}

void RenderingContext::preRender() {
  glm::ivec2 size;
  SDL_GetWindowSize(window, &size.x, &size.y);
  glViewport(0, 0, size.x, size.y);
  CHECK_OPENGL_ERROR();

#ifdef EMSCRIPTEN
  SDL_SetRenderDrawColor(context, 0, 0, 0, 0);
  SDL_RenderClear(context);
#else
  GL::clearFrame();
#endif
}

void RenderingContext::postRender() {
  if (minFrameTime == 0) {
#ifdef EMSCRIPTEN
    SDL_RenderPresent(context);
#else
    SDL_GL_SwapWindow(window);
#endif
  } else {
    const Uint32 start = SDL_GetTicks();
#ifdef EMSCRIPTEN
    SDL_RenderPresent(context);
#else
    SDL_GL_SwapWindow(window);
#endif
    const Uint32 end = SDL_GetTicks();
    
    const Uint32 swapTime = end - start;
    if (swapTime < minFrameTime) {
      SDL_Delay(minFrameTime - swapTime);
    }
  }
}

glm::ivec2 RenderingContext::getFrameSize() const {
  glm::ivec2 size;
  SDL_GL_GetDrawableSize(window, &size.x, &size.y);
  return size;
}

SDL_Window *RenderingContext::getWindow() const {
  return window;
}

void RenderingContext::initImpl(SDL_Window *const newWindow, const bool vsync) {
  window = newWindow;

  #ifdef EMSCRIPTEN
  context = CHECK_SDL_NULL(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
  #else
  GL::ContextParams params;
  params.vsync = vsync;
  params.majorVersion = 4;
  params.minorVersion = 1;
  context = GL::makeContext(window, params);
  #endif

  glEnable(GL_DEPTH_TEST);
}
