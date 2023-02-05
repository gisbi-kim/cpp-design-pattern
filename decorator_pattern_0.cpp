/*
 This example demonstrates how the Decorator pattern 
  can be used to dynamically add new options to a coffee order. 
  
  The Espresso class represents the base component of the pattern. 
  The BeverageOption class serves as the abstract decorator, 
  and the Milk and WhippedCream classes are concrete decorators 
   that add new functionality to the coffee order. 
   
  The client code can dynamically create a coffee order and add options to it, 
   as demonstrated in the main function. 
    
  The output of the program will be:
   Espresso, milk, whipped cream
   Cost: $3.5
*/

#include <iostream>
#include <string>

class Beverage {
 public:
  virtual ~Beverage() = default;

  virtual std::string Description() const = 0;
  virtual double Cost() const = 0;
};

class Espresso : public Beverage {
 public:
  std::string Description() const override { return "Espresso"; }
  double Cost() const override { return 2.0; }
};

class BeverageOption : public Beverage {
 public:
  explicit BeverageOption(Beverage* beverage) : beverage_(beverage) {}

  std::string Description() const override { return beverage_->Description(); }
  double Cost() const override { return beverage_->Cost(); }

 public:
  Beverage* beverage_;
};

class Milk : public BeverageOption {
 public:
  explicit Milk(Beverage* beverage) : BeverageOption(beverage) {}

  std::string Description() const override { return beverage_->Description() + ", milk"; }
  double Cost() const override { return beverage_->Cost() + 0.5; }
};

class WhippedCream : public BeverageOption {
 public:
  explicit WhippedCream(Beverage* beverage) : BeverageOption(beverage) {}

  std::string Description() const override {
    return beverage_->Description() + ", whipped cream";
  }
  double Cost() const override { return beverage_->Cost() + 1.0; }
};

int main() {
  Beverage* beverage = new Espresso();
  beverage = new Milk(beverage);
  beverage = new WhippedCream(beverage);
  std::cout << beverage->Description() << '\n';
  std::cout << "Cost: $" << beverage->Cost() << '\n';
  return 0;
}
