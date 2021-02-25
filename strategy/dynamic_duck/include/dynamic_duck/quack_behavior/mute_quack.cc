//
// Created by cosge on 2021-02-09.
//

#include "dynamic_duck/quack_behavior/mute_quack.h"

#include <iostream>

namespace strategy {
namespace dynamic_duck{

void MuteQuack::quack() const {
  std::cout << "<< Quiet~ >>" << std::endl;
}

} // namespace dynamic_duck
} // namespace strategy