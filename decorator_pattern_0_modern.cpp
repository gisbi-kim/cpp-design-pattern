/*  
I just asked for ChatGPT as "rewrite the above Decorator pattern example using smart pointer"

The expected result: 
  Espresso $1.99
  Espresso, Milk $2.09
  Espresso, Milk, Sugar $2.24
*/

#include <iostream>
#include <memory>
#include <string>

class Beverage {
 public:
  virtual ~Beverage() = default;

  virtual std::string GetDescription() const = 0;
  virtual double Cost() const = 0;
};

class Espresso : public Beverage {
 public:
  std::string GetDescription() const override { return "Espresso"; }
  double Cost() const override { return 1.99; }
};

class CondimentDecorator : public Beverage {
 public:
  virtual std::string GetDescription() const = 0;
};

class Milk : public CondimentDecorator {
 public:
  Milk(const std::shared_ptr<Beverage>& beverage) : beverage_(beverage) {}

  std::string GetDescription() const override {
    return beverage_->GetDescription() + ", Milk";
  }

  double Cost() const override { return beverage_->Cost() + 0.10; }

 private:
  std::shared_ptr<Beverage> beverage_;
};

class Sugar : public CondimentDecorator {
 public:
  Sugar(const std::shared_ptr<Beverage>& beverage) : beverage_(beverage) {}

  std::string GetDescription() const override {
    return beverage_->GetDescription() + ", Sugar";
  }

  double Cost() const override { return beverage_->Cost() + 0.15; }

 private:
  std::shared_ptr<Beverage> beverage_;
};

int main() {
  std::shared_ptr<Beverage> beverage = std::make_shared<Espresso>();
  std::cout << beverage->GetDescription() << " $" << beverage->Cost() << '\n';

  beverage = std::make_shared<Milk>(beverage);
  std::cout << beverage->GetDescription() << " $" << beverage->Cost() << '\n';

  beverage = std::make_shared<Sugar>(beverage);
  std::cout << beverage->GetDescription() << " $" << beverage->Cost() << '\n';

  return 0;
}
