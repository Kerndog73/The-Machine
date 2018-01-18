//
//  pressure plate component.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef pressure_plate_component_hpp
#define pressure_plate_component_hpp

#include <Simpleton/Data/json.hpp>

struct PressurePlate {
  bool heavy;
  
  static void init(PressurePlate &comp, const json &node) {
    Data::get(comp.heavy, node, "heavy");
  }
};

#endif
