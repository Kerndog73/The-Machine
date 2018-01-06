//
//  radioactivity init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "radioactivity init.hpp"

void RadioactivityInit::init(Radioactivity &comp, const json &node) {
  comp.prev = node.at("enabled").get<bool>();
  comp.curr = comp.prev;
}
