//
//  player input response system.hpp
//  The Machine
//
//  Created by Indi Kernick on 9/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef player_input_response_system_hpp
#define player_input_response_system_hpp

#include "player key states.hpp"
#include <Simpleton/ECS/registry.hpp>

//make the player respond to input by moving and activating entities
//like switches and buttons
void playerInputResponseSystem(ECS::Registry &, PlayerKeyStates);

#endif
