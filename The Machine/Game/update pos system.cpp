//
//  update pos system.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "update pos system.hpp"

#include "dir to vec.hpp"
#include "movement component.hpp"
#include "position component.hpp"

void updatePosSystem(entt::registry &registry, EntityGrid &grid) {
  const size_t length = grid.length();
  for (size_t i = 0; i != length; ++i) {
    grid[i].dynamicID = entt::null;
  }
  
  auto view = registry.view<Movement, Position>();
  for (const entt::entity entity : view) {
    const Pos dirVec = toVec(view.get<Movement>(entity).realDir);
    Pos &pos = view.get<Position>(entity).pos;
    pos += dirVec;
    grid[pos].dynamicID = entity;
  }
}
