#include <iostream>

using namespace std;

class Printable {
public:
  virtual string getClassName() = 0; // pure virtual function
};

class Entity : public Printable {
public:
  string getClassName() override {
    return "Entity";
  } // override of the virtual function

  string virtual getName() { return "entityyyyy"; }
};

class Player : public Entity {
public:
  string getClassName() override { return "Player"; }

  string getName() override { return "playerrrr"; }
};

void func(Entity *e) { cout << e->getName() << endl; }

int main() {
  Entity *e = new Entity();
  Player *p = new Player();
  //   cout << e->getClassName() << endl;
  //   cout << p->getClassName() << endl;
  Entity *e2 = p;
  func(e2);
}
