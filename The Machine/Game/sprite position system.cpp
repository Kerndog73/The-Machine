//
//  sprite position system.cpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "sprite position system.hpp"

#include "dir to vec.hpp"
#include "position component.hpp"
#include "movement component.hpp"
#include "sprite position component.hpp"

void spritePositionSystem(entt::registry &registry, const Frame frame) {
  auto view = registry.view<Position, SpritePosition>();
  for (const entt::entity entity : view) {
    glm::vec2 pos = view.get<Position>(entity).pos;
    
    if (registry.has<Movement>(entity)) {
      const Grid::Dir realDir = registry.get<Movement>(entity).realDir;
      const float progress = static_cast<float>(frame) / FRAMES_PER_TICK;
      pos += toFloatVec(realDir) * progress;
    }
    
    view.get<SpritePosition>(entity).pos = pos;
  }
}
