//
//  gate component.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef gate_component_hpp
#define gate_component_hpp

enum class GateFun {
  AND,
  OR,
  XOR,
  NOT,
  NAND,
  NOR,
  XNOR,
  IDENTITY
};

struct Gate {
  GateFun fun;
};

#endif
