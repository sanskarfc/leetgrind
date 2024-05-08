
// Stack class.
class Stack {
private:
  vector<int> arr;
  int ind = 0;
  int cap;

public:
  Stack(int capacity) { cap = capacity; }

  void push(int num) {
    if (ind + 1 <= cap) {
      arr.push_back(num);
      ind++;
    }
  }

  int pop() {
    if (ind == 0) {
      return -1;
    }
    int num = arr[ind - 1];
    arr.pop_back();
    ind--;
    return num;
  }

  int top() {
    if (ind == 0) {
      return -1;
    }
    return arr[ind - 1];
  }

  int isEmpty() { return ind == 0; }

  int isFull() { return ind == cap; }
};
