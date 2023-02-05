/* The expected result:

  Basic car
  Cost: 10000

  Basic car, navigation
  Cost: 12500

  Basic car, sunroof, navigation
  Cost: 14500

*/

#include <iostream>
#include <string>

class Car {
 public:
  virtual ~Car() = default;

  virtual std::string Description() const = 0;
  virtual double Cost() const = 0;
};

class BasicCar : public Car {
 public:
  std::string Description() const override { return "Basic car"; }
  double Cost() const override { return 10000; }
};

class CarWithOption : public Car {
 public:
  explicit CarWithOption(Car* car) : car_(car) {}

  std::string Description() const override { return car_->Description(); }
  double Cost() const override { return car_->Cost(); }

 public:
  Car* car_;
};

class Sunroof : public CarWithOption {
 public:
  explicit Sunroof(Car* car) : CarWithOption(car) {}

  std::string Description() const override {
    return car_->Description() + ", sunroof";
  }
  double Cost() const override { return car_->Cost() + 2000; }
};

class Navigation : public CarWithOption {
 public:
  explicit Navigation(Car* car) : CarWithOption(car) {}

  std::string Description() const override {
    return car_->Description() + ", navigation";
  }
  double Cost() const override { return car_->Cost() + 2500; }
};

int main() {
  {
    Car* car = new BasicCar();
    std::cout << car->Description() << '\n';
    std::cout << "Cost: " << car->Cost() << "\n\n";
  }

  {
    Car* car = new BasicCar();
    car = new Navigation(car);
    std::cout << car->Description() << '\n';
    std::cout << "Cost: " << car->Cost() << "\n\n";
  }
  
  {
    Car* car = new BasicCar();
    car = new Sunroof(car);
    car = new Navigation(car);
    std::cout << car->Description() << '\n';
    std::cout << "Cost: " << car->Cost() << "\n\n";
  }
  
  return 0;
}
