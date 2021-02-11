//
// Created by YongGyu Lee on 2021/02/11.
//

#ifndef STRATEGY_DYNAMIC_DUCK_INTERFACE_CLONEABLE_H_
#define STRATEGY_DYNAMIC_DUCK_INTERFACE_CLONEABLE_H_

#include <memory>

template<typename Derived>
class Cloneable {
 public:
  virtual ~Cloneable() = default;

  inline std::unique_ptr<Derived> clone() const {
    return std::unique_ptr<Derived>(clone_impl());
  }
 protected:
  virtual Derived* clone_impl() const = 0;
};

#endif //STRATEGY_DYNAMIC_DUCK_INTERFACE_CLONEABLE_H_
