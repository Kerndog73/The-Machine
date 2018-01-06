//
//  signal receiver init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "signal receiver init.hpp"

void SignalReceiverInit::init(SignalReceiver &comp, const json &node) {
  comp.channel = node.at("channel").get<uint8_t>();
}
