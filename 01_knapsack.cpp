#include <vector>

using namespace std;

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
  vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
  dp[0][weights[0]] = values[0];
  for (int i = 1; i < n; i++) {
    for (int weight = 0; weight <= w; weight++) {
      dp[i][weight] = max(dp[i][weight], dp[i - 1][weight]);
      if (weight - weights[i] >= 0) {
        dp[i][weight] =
            max(dp[i][weight], dp[i - 1][weight - weights[i]] + values[i]);
      }
    }
  }
  int maxm = 0;
  for (int weight = 0; weight <= w; weight++) {
    maxm = max(maxm, dp[n - 1][weight]);
  }
  return maxm;
}
