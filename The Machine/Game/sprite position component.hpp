//
//  sprite position component.hpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef sprite_position_component_hpp
#define sprite_position_component_hpp

#include <Simpleton/Math/dir.hpp>
#include <Simpleton/Data/json.hpp>

struct SpritePosition {
  glm::vec2 pos = {0.0f, 0.0f};
  float depth;
  Math::Dir orient = Math::Dir::UP;
  
  static void init(SpritePosition &comp, const json &node) {
    Data::get(comp.depth, node, "depth");
    if (JSON_OPTIONAL(orient, node, "dir")) {
      comp.orient = static_cast<Math::Dir>(orient->get<Math::DirType>());
    }
  }
};

#endif
