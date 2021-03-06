//
//  static sprite component.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef static_sprite_component_hpp
#define static_sprite_component_hpp

#include "frame type.hpp"
#include <Simpleton/Data/json.hpp>
#include <Simpleton/Sprite/types.hpp>

struct StaticSprite {
  Frame frame = 0;
  Frame repeats = 0;
  Frame ticks;
  Sprite::ID sprite;
  
  static void init(StaticSprite &comp, const json &node) {
    Data::get(comp.sprite, node, "sprite");
    Data::get(comp.ticks, node, "ticks");
  }
};

#endif
