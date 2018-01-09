//
//  player input system.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "player input system.hpp"

#include <SDL2/SDL_events.h>

void playerInputSystem(PlayerKeyStates &states, const SDL_Event &e) {
  const bool keydown = (e.type == SDL_KEYDOWN && e.key.repeat == 0);
  
  if (!keydown && (e.type != SDL_KEYUP)) {
    return;
  }
  
  const SDL_Scancode key = e.key.keysym.scancode;
  
  if (key == SDL_SCANCODE_SPACE) {
    states.action = keydown;
  } else if (key == SDL_SCANCODE_UP || key == SDL_SCANCODE_W) {
    states.dirs[0] = keydown;
  } else if (key == SDL_SCANCODE_RIGHT || key == SDL_SCANCODE_D) {
    states.dirs[1] = keydown;
  } else if (key == SDL_SCANCODE_DOWN || key == SDL_SCANCODE_S) {
    states.dirs[2] = keydown;
  } else if (key == SDL_SCANCODE_LEFT || key == SDL_SCANCODE_A) {
    states.dirs[3] = keydown;
  }
}
