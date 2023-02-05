/*
 In this example, 
 the AnimalShelter class contains a collection of Animal objects, 
  but instead of inheriting from Animal, 
  it uses composition and contains a collection of Animal objects. 
 
 This allows the AnimalShelter class to have the functionality of an Animal 
 without inheriting its implementation. 
 
 Additionally, it provides a degree of decoupling between the AnimalShelter and Animal classes, 
 making it easier to change the implementation of the Animal class 
 without affecting the AnimalShelter class. 
 
*/

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
