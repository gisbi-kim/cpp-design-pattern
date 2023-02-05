/*
This example demonstrates how the Factory pattern 
 can be used to create objects of different types, 
  in this case MargheritaPizza and PepperoniPizza. 
  
The PizzaFactory class serves as a factory 
 and creates objects of the appropriate type based on the PizzaType specified. 
 
The client code can use the factory to create Pizza objects, 
 as demonstrated in the main function. 
 
The output of the program will be:
  Margherita Pizza
  Cost: $7
  Pepperoni Pizza
  Cost: $9

*/

#include <iostream>
#include <string>

class Pizza {
 public:
  virtual ~Pizza() = default;

  virtual std::string Description() const = 0;
  virtual double Cost() const = 0;
};

class MargheritaPizza : public Pizza {
 public:
  std::string Description() const override { return "Margherita Pizza"; }
  double Cost() const override { return 7.0; }
};

class PepperoniPizza : public Pizza {
 public:
  std::string Description() const override { return "Pepperoni Pizza"; }
  double Cost() const override { return 9.0; }
};

class PizzaFactory {
 public:
  enum PizzaType { kMargherita, kPepperoni };

  static Pizza* CreatePizza(PizzaType type) {
    switch (type) {
      case kMargherita:
        return new MargheritaPizza();
      case kPepperoni:
        return new PepperoniPizza();
      default:
        return nullptr;
    }
  }
};

int main() {
  Pizza* margherita = PizzaFactory::CreatePizza(PizzaFactory::kMargherita);
  std::cout << margherita->Description() << '\n';
  std::cout << "Cost: $" << margherita->Cost() << '\n';
  
  Pizza* pepperoni = PizzaFactory::CreatePizza(PizzaFactory::kPepperoni);
  std::cout << pepperoni->Description() << '\n';
  std::cout << "Cost: $" << pepperoni->Cost() << '\n';
  
  return 0;
}

