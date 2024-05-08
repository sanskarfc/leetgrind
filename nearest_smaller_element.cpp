#include <pthread.h>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  vector<int> prevSmaller(vector<int> &A);
};

vector<int> Solution::prevSmaller(vector<int> &A) {
  stack<pair<int, int>> s1;
  int n = A.size();
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (s1.empty()) {
      ans[i] = -1;
      s1.push(make_pair(A[i], i));
      continue;
    }

    while (s1.top().first >= A[i]) {
      s1.pop();
      if (s1.empty())
        break;
    }

    if (s1.empty()) {
      ans[i] = -1;
    } else {
      ans[i] = s1.top().first;
    }

    s1.push(make_pair(A[i], i));
  }
  return ans;
}
