//
//  main.cpp
//  The Machine
//
//  Created by Indi Kernick on 3/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "app.hpp"

#include <Simpleton/Utils/profiler.hpp>

int main(int, char **) {
  App app;
  app.mainloop();
  PROFILER_INFO(stdout);
  return 0;
}
