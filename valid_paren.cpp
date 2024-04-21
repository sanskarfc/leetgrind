#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<int> s1;
    for (int i = 0; i < s.length(); i++) {
      if (s1.empty()) {
        if (s[i] == '(') {
          s1.push(1);
        } else if (s[i] == ')') {
          return false;
        } else if (s[i] == '{') {
          s1.push(2);
        } else if (s[i] == '}') {
          return false;
        } else if (s[i] == '[') {
          s1.push(3);
        } else { // s[i] == ']'
          return false;
        }
      } else if (s1.top() == 1) {
        if (s[i] == '(') {
          s1.push(1);
        } else if (s[i] == ')') {
          s1.pop();
        } else if (s[i] == '[') {
          s1.push(3);
        } else if (s[i] == '{') {
          s1.push(2);
        } else {
          return false;
        }
      } else if (s1.top() == 2) {
        if (s[i] == '{') {
          s1.push(2);
        } else if (s[i] == '}') {
          s1.pop();
        } else if (s[i] == '(') {
          s1.push(1);
        } else if (s[i] == '[') {
          s1.push(3);
        } else {
          return false;
        }
      } else if (s1.top() == 3) {
        if (s[i] == '[') {
          s1.push(3);
        } else if (s[i] == ']') {
          s1.pop();
        } else if (s[i] == '(') {
          s1.push(1);
        } else if (s[i] == '{') {
          s1.push(2);
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
    return s1.empty();
  }
};
