class Solution {
public:
  bool splitArraySameAverage(vector<int> &nums) {
    // dp[ind][sum] = 100010101
    // i-th bit is 1 when we can make sum with ind as last index and i number of
    // elements
    int n = nums.size();
    int tot = 0;
    for (auto x : nums)
      tot += x;
    vector<int> dp(300000, 0);
    for (int i = 0; i < n; i++) {
      for (int sum = tot; sum >= 0; sum--) {
        if (sum - nums[i] >= 0) {
          if (dp[sum - nums[i]]) {
            dp[sum] = dp[sum] | (dp[sum - nums[i]] << 1);
          }
        }
      }
      dp[nums[i]] |= 2;
    }
    for (int len = 1; len < n; len++) {
      if ((tot * len) % n == 0 && ((1 << len) & dp[(tot * len) / n])) {
        return true;
      }
    }
    return false;
  }
};
