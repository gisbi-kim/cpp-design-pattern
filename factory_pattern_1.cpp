#include <iostream>
#include <memory>
#include <vector>

class Animal {
public:
  virtual void MakeSound() const = 0;
  virtual ~Animal() {}
};

class Dog : public Animal {
public:
  void MakeSound() const override { std::cout << "Bark\n"; }
};

class Cat : public Animal {
public:
  void MakeSound() const override { std::cout << "Meow\n"; }
};

class Bird : public Animal {
public:
  void MakeSound() const override { std::cout << "Queuk\n"; }
};

class AnimalFactory {
public:
  static std::unique_ptr<Animal> CreateAnimal(const std::string &animalType) {
    if (animalType == "dog") {
      return std::make_unique<Dog>();
    } else if (animalType == "cat") {
      return std::make_unique<Cat>();
    } else if (animalType == "bird") {
      return std::make_unique<Bird>();
    }

    return nullptr;
  }
};

int main() {

  std::vector<std::string> animals{"dog", "cat", "bird", "dog"};
  for (auto &_animal : animals) {
    std::unique_ptr<Animal> animal = AnimalFactory::CreateAnimal(_animal);
    animal->MakeSound();
  }

  return 0;
}
