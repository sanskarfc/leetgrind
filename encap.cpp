#include <iostream>

class EncapsulationExample {
private:
  int data;

public:
  void setDate(int value) { data = value; }

  int getData() { return data; }
};

int main() {
  EncapsulationExample obj;
  obj.setDate(4);
  std::cout << "Data: " << obj.getData() << std::endl;
  return 0;
}
