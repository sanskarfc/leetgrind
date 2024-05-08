#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> dp;
  long returnAns(vector<int> &coin, long target, long sum, int ind) {
    if (sum > target) {
      return (long)100000;
    }
    if (sum == target) {
      return (long)0;
    }
    if (ind == coin.size()) {
      return (long)100000;
    }
    if (dp[sum][ind] != -1) {
      return dp[sum][ind];
    }
    return dp[sum][ind] =
               min((long)1 + returnAns(coin, target, sum + coin[ind], ind),
                   returnAns(coin, target, sum, ind + 1));
  }

  int coinChange(vector<int> &coins, int amount) {
    dp.resize(10001, vector<int>(13, -1));
    int ans = returnAns(coins, amount, 0, 0);
    // sum, ind
    // 10^4, 12
    if (ans >= 100000) {
      return -1;
    }
    return ans;
  }
};
