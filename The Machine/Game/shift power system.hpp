//
//  shift power system.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef shift_power_system_hpp
#define shift_power_system_hpp

#include <entt/entity/registry.hpp>

// set Power::prev to Power::curr and set Power::curr to false
void shiftPowerSystem(entt::registry &);

#endif
