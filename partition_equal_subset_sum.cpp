#include <vector>

using namespace std;

class Solution {
public:
  int halfSum;
  vector<vector<int>> dp;
  bool isPossible(int ind, vector<int> &nums, int sum) {
    if (ind == nums.size()) {
      return false;
    }
    if (sum > halfSum) {
      return false;
    }
    if (sum == halfSum) {
      return true;
    }
    if (dp[ind][sum] != -1) {
      return dp[ind][sum];
    }
    return dp[ind][sum] = (isPossible(ind + 1, nums, sum + nums[ind]) ||
                           isPossible(ind + 1, nums, sum));
  }

  bool canPartition(vector<int> &nums) {
    int sum = 0;
    int n = nums.size();
    dp.resize(n + 1, vector<int>(20001, -1));
    for (int i = 0; i < n; i++) {
      sum += nums[i];
    }
    if (sum % 2 == 1) {
      return false;
    }
    halfSum = sum / 2;
    return isPossible(0, nums, 0);
  }
};
