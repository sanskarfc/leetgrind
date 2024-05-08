#include <string>
#include <sys/wait.h>

using namespace std;

class Solution {
public:
  bool check_palin(string s, int siz) {
    for (int i = 0; i <= s.size() - siz; i++) {
      string a = s.substr(i, siz);
      string b = a;
      reverse(b.begin(), b.end());
      if (a == b) {
        return true;
      }
    }
    return false;
  }

  string getString(string s, int siz) {
    for (int i = 0; i <= s.size() - siz; i++) {
      string a = s.substr(i, siz);
      string b = a;
      reverse(b.begin(), b.end());
      if (a == b) {
        return a;
      }
    }
    return "";
  }

  string longestPalindrome(string s) {
    int n = s.size();
    int lo = 1;
    int hi = n;
    while (hi - lo > 5) {
      int mid = lo + (hi - lo) / 2;
      bool check1 = check_palin(s, mid);
      bool check2 = check_palin(s, mid + 1);
      bool a = (check1 || check2);
      if (a) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
    int siz;
    for (siz = hi; siz >= lo; siz--) {
      if (check_palin(s, siz)) {
        return getString(s, siz);
      }
    }
    return "";
  }
};
