#include <iostream>
#include <vector>

class Collection {
 public:
  class Iterator {
   public:
    Iterator(const Collection& collection, int index)
        : collection_(collection), index_(index) {}

    bool HasNext() const { return index_ < collection_.Size(); }

    int Next() { return collection_.Get(index_++); }

   private:
    const Collection& collection_;
    int index_;
  };

  Collection() {}

  void Add(int value) { values_.push_back(value); }

  int Size() const { return values_.size(); }

  int Get(int index) const { return values_[index]; }

  Iterator CreateIterator() const { return Iterator(*this, 0); }

 private:
  std::vector<int> values_;
};

int main() {
  Collection collection;
  collection.Add(1);
  collection.Add(2);
  collection.Add(3);

  Collection::Iterator iterator = collection.CreateIterator();
  while (iterator.HasNext()) {
    std::cout << iterator.Next() << "\n";
  }

  return 0;
}
