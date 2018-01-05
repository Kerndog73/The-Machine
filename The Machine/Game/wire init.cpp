//
//  wire init.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "wire init.hpp"

void WireInit::init(Wire &wire, const json &node) {
  wire.sides = static_cast<Math::DirBits>(node.at("sides").get<Math::DirType>());
  wire.cross = node.at("cross").get<bool>();
}