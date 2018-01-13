//
//  delay component.hpp
//  The Machine
//
//  Created by Indi Kernick on 13/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef delay_component_hpp
#define delay_component_hpp

struct Delay {
  enum class State {
    LOW,
    RISE,
    HIGH,
    FALL
  };

  unsigned length;
  unsigned counter = 0;
  State state = State::LOW;
};

#endif
