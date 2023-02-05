/*
 In this example, 
 Car objects have an Engine, 
  but instead of inheriting from Engine, 
  Car objects use composition and contain an Engine object. 
  
 This allows Car objects to have the functionality of an Engine 
  without inheriting its implementation. 
  
 Additionally, it provides a degree of decoupling between the Car and Engine classes, 
  making it easier to change the implementation of the Engine class 
  without affecting the Car class. 
*/

#include <iostream>
#include <string>

class Engine {
 public:
  virtual void Start() const { std::cout << "Engine started\n"; }
  virtual void Stop() const { std::cout << "Engine stopped\n"; }
};

class Car {
 public:
  Car() : engine_(std::make_unique<Engine>()) {}

  void StartEngine() const { engine_->Start(); }
  void StopEngine() const { engine_->Stop(); }

 private:
  std::unique_ptr<Engine> engine_;
};

int main() {
  Car car;
  car.StartEngine();
  car.StopEngine();
  return 0;
}
