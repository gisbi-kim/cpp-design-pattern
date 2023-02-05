/*
  In this example, 
  the DataUser class uses instances of the DataStorage and DataProcessor classes 
  to store and process data. 
  
  The DataStorage class is responsible for storing data, 
  and the DataProcessor class is responsible for processing data. 
  
  The DataUser class does not need to know how the data is stored or processed, 
  it only needs to know how to add data and get the result. 
  
  This separation of concerns makes the system more flexible and maintainable, 
  as changes to the storage or processing of data can be made without affecting the DataUser class.
*/

#include <iostream>
#include <vector>

class DataStorage {
 private:
  std::vector<int> data_;

 public:
  void addData(int value) {
    data_.push_back(value);
  }

  std::vector<int> getData() const {
    return data_;
  }
};

class DataProcessor {
 public:
  int processData(const std::vector<int>& data) {
    int result = 0;
    for (int value : data) {
      result += value;
    }
    return result;
  }
};

class DataUser {
 private:
  DataStorage storage_;
  DataProcessor processor_;

 public:
  void addData(int value) {
    storage_.addData(value);
  }

  int getResult() {
    return processor_.processData(storage_.getData());
  }
};

int main() {
  DataUser dataUser;
  dataUser.addData(1);
  dataUser.addData(2);
  dataUser.addData(3);
  std::cout << "Result: " << dataUser.getResult() << '\n';
  return 0;
}
