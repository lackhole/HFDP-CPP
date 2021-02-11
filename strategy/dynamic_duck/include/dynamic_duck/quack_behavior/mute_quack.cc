//
// Created by cosge on 2021-02-09.
//

#include "dynamic_duck/quack_behavior/mute_quack.h"

#include <iostream>

void MuteQuack::quack() const {
  std::cout << "<< Quiet~ >>" << std::endl;
}
