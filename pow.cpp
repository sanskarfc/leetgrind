class Solution {
public:
  double getAns(double x, int n) {
    double res = 1;
    double a = x;
    while (n) {
      if (n & 1) {
        res = res * a;
      }
      a = a * a;
      n = n / 2;
    }
    return res;
  }

  double myPow(double x, int n) {
    if (n == 0)
      return (double)1;

    if (n > 0) {
      return getAns(x, n);
    } else {
      return 1.0 / getAns(x, n);
    }
  }
};
