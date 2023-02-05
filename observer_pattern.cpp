#include <iostream>
#include <algorithm>
#include <vector>

class Observer {
 public:
  virtual void update() = 0;
};

class Subject {
 private:
  std::vector<Observer*> observers_;

 public:
  void attach(Observer* observer) {
    observers_.push_back(observer);
  }

  void detach(Observer* observer) {
    auto it = std::find(observers_.begin(), observers_.end(), observer);
    if (it != observers_.end()) {
      observers_.erase(it);
    }
  }

  void notify() {
    for (Observer* observer : observers_) {
      observer->update();
    }
  }
};

class ConcreteObserverA : public Observer {
 public:
  void update() {
    std::cout << "ConcreteObserverA received update\n";
  }
};

class ConcreteObserverB : public Observer {
 public:
  void update() {
    std::cout << "ConcreteObserverB received update\n";
  }
};

int main() {
  ConcreteObserverA observerA;
  ConcreteObserverB observerB;
  Subject subject;

  subject.attach(&observerA);
  subject.attach(&observerB);

  subject.notify();

  subject.detach(&observerB);

  subject.notify();

  return 0;
}

/* The expected results are:
  ConcreteObserverA received update
  ConcreteObserverB received update
  ConcreteObserverA received update
*/
