//
//  shift radioactivity system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "shift radioactivity system.hpp"

#include "radioactivity component.hpp"

void shiftRadioactivitySystem(entt::registry &registry) {
  auto view = registry.view<Radioactivity>();
  for (const entt::entity entity : view) {
    Radioactivity &radioactivity = view.get(entity);
    radioactivity.prev = radioactivity.curr;
  }
}
