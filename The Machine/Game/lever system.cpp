//
//  lever system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "lever system.hpp"

#include "power component.hpp"
#include "lever component.hpp"
#include "position component.hpp"
#include "player action component.hpp"

void leverSystem(entt::registry &registry, const EntityGrid &grid) {
  auto posView = registry.view<Lever, Position>();
  for (const entt::entity entity : posView) {
    const Pos pos = posView.get<Position>(entity).pos;
    const entt::entity targetID = grid[pos].dynamicID;
    
    if (targetID == entt::null) {
      continue;
    }
    
    if (!registry.has<PlayerAction>(targetID)) {
      continue;
    }
    
    const PlayerAction action = registry.get<PlayerAction>(targetID);
    //rising edge
    if (!action.prev && action.curr) {
      bool &enabled = posView.get<Lever>(entity).enabled;
      enabled = !enabled;
    }
  }
  
  auto powerView = registry.view<Power, Lever>();
  for (const entt::entity entity : powerView) {
    powerView.get<Power>(entity).curr = powerView.get<Lever>(entity).enabled;
  }
}
