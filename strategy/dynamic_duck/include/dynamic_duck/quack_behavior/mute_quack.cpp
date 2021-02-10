//
// Created by cosge on 2021-02-09.
//

#include <iostream>
#include "dynamic_duck/quack_behavior/mute_quack.hpp"

void MuteQuack::quack() const {
  std::cout << "<< Quiet~ >>" << std::endl;
}
