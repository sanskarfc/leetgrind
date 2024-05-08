#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> leftSmall = prevSmaller(heights);
    reverse(heights.begin(), heights.end());
    vector<int> rightSmall = prevSmaller(heights);
    reverse(rightSmall.begin(), rightSmall.end());
    reverse(heights.begin(), heights.end());
    int maxm = 0;
    for (int i = 0; i < n; i++) {
      int ans = 0;
      ans += (leftSmall[i] * heights[i]);
      ans += (rightSmall[i] * heights[i]);
      ans += heights[i];
      maxm = max(maxm, ans);
    }
    return maxm;
  }

  vector<int> prevSmaller(vector<int> &A) {
    stack<pair<int, int>> s1;
    int n = A.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      if (s1.empty()) {
        ans[i] = i;
        s1.push(make_pair(A[i], i));
        continue;
      }

      while (s1.top().first >= A[i]) {
        s1.pop();
        if (s1.empty())
          break;
      }

      if (s1.empty()) {
        ans[i] = i;
      } else {
        ans[i] = i - s1.top().second - 1;
      }

      s1.push(make_pair(A[i], i));
    }
    return ans;
  }
};
