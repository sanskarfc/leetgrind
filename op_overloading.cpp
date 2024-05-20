#include <iostream>

using namespace std;

class Boy {
private:
  int age;
  string name;

public:
  Boy(int a) { age = a; }

  void getDetails() { cout << "age --> " << age << endl; }

  int operator+(Boy b1) { return age + b1.age; }

  int operator*(Boy b1) { return age * b1.age; }
};

int main() {
  Boy *b1 = new Boy(10);
  Boy *b2 = new Boy(20);

  b1->getDetails();
  b2->getDetails();

  cout << "sum of age: " << *b1 + *b2 << endl;
  cout << "mul of age: " << *b1 * *b2 << endl;

  return 0;
}
