/*
  In this example, 
  the Car class uses an instance of the Engine class to start and stop the car. 
  The Engine class is separated from the Car class and encapsulated, 
  so that changes to the engine do not affect the Car class. 
  
  For example, if you want to change the engine to a different type of engine, 
  you only need to modify the Engine class and **not** the Car class. 
  
  This separation of concerns makes the system more flexible and maintainable.
*/

#include <iostream>

class Engine {
 public:
  void start() {
    std::cout << "Engine started\n";
  }

  void stop() {
    std::cout << "Engine stopped\n";
  }
};

class Car {
 private:
  Engine engine_;

 public:
  void start() {
    engine_.start();
    std::cout << "Car started\n";
  }

  void stop() {
    engine_.stop();
    std::cout << "Car stopped\n";
  }
};

int main() {
  Car car;
  car.start();
  car.stop();
  return 0;
}
