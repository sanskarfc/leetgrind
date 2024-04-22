// wrong answer lol. i did it finally but this will go on github

#include <string>

using namespace std;

class Solution {
public:
  bool giveAns(int i, int j, string s) {
    if (i == j) {
      return true;
    }

    if ((s[i] >= '0' && s[i] <= '9') &&
        (s[j] >= '0' && s[j] <= '9')) { // both are aplhanumeric
      if (s[i] == s[j])
        return giveAns(i + 1, j - 1, s);
      else
        return false;
    }

    if ((s[i] >= '0' && s[i] <= '9') && !(s[j] >= '0' && s[j] <= '9')) {
      return false;
    }

    if (!((s[i] >= 'a' && s[i] <= 'z') ||
          (s[i] >= 'A' && s[i] <= 'Z'))) { // not an alpha
      return giveAns(i + 1, j, s);
    }

    if (!((s[j] >= 'a' && s[j] <= 'z') ||
          (s[j] >= 'A' && s[j] <= 'Z'))) { // not an alpha
      return giveAns(i, j - 1, s);
    }

    char bigI = s[i] ^ 32;
    char bigJ = s[j] ^ 32;

    if (s[i] == s[j] || s[i] == bigJ || s[j] == bigI) {
      return giveAns(i + 1, j - 1, s);
    }
    return false;
  }

  bool isPalindrome(string s) { return giveAns(0, s.size() - 1, s); }
};
