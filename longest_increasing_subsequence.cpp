#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.size();
    // dp[i] --> length of the longest common subsequence ending at i
    // (including)
    vector<int> dp(n + 1, 1);
    int ans = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
          ans = max(ans, dp[i]);
        }
      }
    }
    return ans;
  }
};
