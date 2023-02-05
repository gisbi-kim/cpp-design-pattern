#include <iostream>
#include <vector>

class Animal {
 public:
  virtual void MakeSound() const { std::cout << "Animal sound\n"; }
};

class Dog : public Animal {
 public:
  void MakeSound() const override { std::cout << "Bark\n"; }
};

class Cat : public Animal {
 public:
  void MakeSound() const override { std::cout << "Meow\n"; }
};

class AnimalShelter {
 public:
  void AddAnimal(std::unique_ptr<Animal> animal) {
    animals_.push_back(std::move(animal));
  }

  void MakeAllSounds() const {
    for (const auto& animal : animals_) {
      animal->MakeSound();
    }
  }

 private:
  std::vector<std::unique_ptr<Animal>> animals_;
};

int main() {
  AnimalShelter shelter;
  shelter.AddAnimal(std::make_unique<Dog>());
  shelter.AddAnimal(std::make_unique<Cat>());
  shelter.MakeAllSounds();
  return 0;
}
