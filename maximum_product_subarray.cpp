#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    // dp[i] = max product of subarray ending at ith index (including i)
    int n = nums.size();
    vector<int> dp(n + 1);
    vector<int> dpn(n + 1);
    dp[0] = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
      dp[i] = max({dp[i - 1] * nums[i], nums[i], dpn[i - 1] * nums[i]});
      dpn[i] = min({dpn[i - 1] * nums[i], nums[i], nums[i] * dp[i - 1]});
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
