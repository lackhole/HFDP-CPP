//
// Created by cosge on 2021-02-25.
//
#include "static_duck/quack_behavior/mute_quack.h"

#include <iostream>

namespace strategy {
namespace static_duck{

void MuteQuack::quack() const {
  std::cout << "<< Quiet~ >>" << std::endl;
}

} // namespace static_duck
} // namespace strategy