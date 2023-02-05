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
