class FooBar {
private:
  int n;
  mutex m;
  condition_variable cv;
  int turn;

public:
  FooBar(int n) {
    this->n = n;
    turn = 0;
  }

  void foo(function<void()> printFoo) {
    unique_lock<mutex> lock(m);
    for (int i = 0; i < n; i++) {
      // printFoo() outputs "foo". Do not change or remove this line.
      while (turn != 0) {
        cv.wait(lock);
      }
      printFoo();
      turn = 1;
      cv.notify_all();
    }
  }

  void bar(function<void()> printBar) {
    unique_lock<mutex> lock(m);
    for (int i = 0; i < n; i++) {
      // printBar() outputs "bar". Do not change or remove this line.
      while (turn != 1) {
        cv.wait(lock);
      }
      printBar();
      turn = 0;
      cv.notify_all();
    }
  }
};
