//
// Created by cosge on 2021-02-25.
//

#ifndef STRATEGY_STATIC_DUCK_ABSTRACT_DUCK_H
#define STRATEGY_STATIC_DUCK_ABSTRACT_DUCK_H

#include <memory>
#include <type_traits>

namespace strategy {
namespace static_duck {

template<typename Derived>
class AbstractDuck {
 public:

  template<typename FlyBehaviorType, typename QuackBehaviorType>
  AbstractDuck(FlyBehaviorType&& flyBehavior, QuackBehaviorType&& quackBehavior)
    : flyBehavior(std::make_shared<FlyBehavior<std::remove_reference_t<FlyBehaviorType>>>(std::forward<FlyBehaviorType>(flyBehavior))),
      quackBehavior(std::make_shared<QuackBehavior<std::remove_reference_t<QuackBehaviorType>>>(std::forward<QuackBehaviorType>(quackBehavior)))
  {}

  inline void display() const { return static_cast<const Derived&>(*this).display(); }
  inline void performFly() const { return flyBehavior->fly(); }
  inline void performQuack() const { return quackBehavior->quack(); }
  inline void swim() const {
    std::cout << "Every duck float on water. Even decoy duck floats." << std::endl;
  }

  template<typename FlyBehaviorType>
  inline void setFlyBehavior(FlyBehaviorType&& behavior) {
    flyBehavior = std::make_shared<FlyBehavior<std::remove_reference_t<FlyBehaviorType>>>(
      std::forward<FlyBehaviorType>(behavior)); }

  template<typename QuackBehaviorType>
  inline void setQuackBehavior(QuackBehaviorType&& behavior) {
    quackBehavior = std::make_shared<QuackBehavior<std::remove_reference_t<QuackBehaviorType>>>(
      std::forward<QuackBehaviorType>(behavior)); }

 private:
  struct FlyBehaviorBase {
    virtual ~FlyBehaviorBase() = default;
    virtual void fly() const = 0;
  };
  template<typename FlyBehaviorType>
  struct FlyBehavior : public FlyBehaviorBase {
    explicit FlyBehavior(FlyBehaviorType&& flyBehavior)
      : flyBehavior(std::forward<FlyBehaviorType>(flyBehavior)) {}

    inline void fly() const override { flyBehavior.fly(); }
   private:
    FlyBehaviorType flyBehavior;
  };

  struct QuackBehaviorBase {
    virtual ~QuackBehaviorBase() = default;
    virtual void quack() const = 0;
  };
  template<typename QuackBehaviorType>
  struct QuackBehavior : public QuackBehaviorBase {
    explicit QuackBehavior(QuackBehaviorType&& quackBehavior)
      : quackBehavior(std::forward<QuackBehaviorType>(quackBehavior)) {}

    inline void quack() const override { quackBehavior.quack(); }
   private:
    QuackBehaviorType quackBehavior;
  };

  std::shared_ptr<FlyBehaviorBase> flyBehavior;
  std::shared_ptr<QuackBehaviorBase> quackBehavior;
};

} // namespace static_duck
} // namespace strategy

#endif //STRATEGY_STATIC_DUCK_ABSTRACT_DUCK_H
