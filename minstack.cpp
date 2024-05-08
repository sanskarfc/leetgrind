class MinStack {
private:
  std::stack<long> s1;
  long minElem;

public:
  MinStack() {}

  void push(int val) {
    if (s1.empty()) {
      s1.push(val);
      minElem = val;
    } else {
      if (val < minElem) {
        s1.push(2 * (long)val - minElem);
        minElem = val;
      } else {
        s1.push(val);
      }
    }
  }

  void pop() {
    if (s1.empty())
      return;

    long top = s1.top();
    s1.pop();
    if (top < minElem) {
      minElem = 2 * minElem - top;
    }
  }

  int top() {
    if (s1.empty())
      throw std::runtime_error("Stack is empty");

    long top = s1.top();
    if (top < minElem) {
      return (int)minElem;
    } else {
      return (int)top;
    }
  }

  int getMin() {
    if (s1.empty())
      throw std::runtime_error("Stack is empty");
    return (int)minElem;
  }
};
