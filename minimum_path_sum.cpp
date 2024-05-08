#include <vector>

using namespace std;

class Solution {
public:
  int n, m;
  vector<vector<int>> v1;
  vector<vector<int>> dp;

  int getAns(int i, int j) {
    if (i == n - 1 && j == m - 1) {
      return v1[i][j];
    }
    if (i == n) {
      return 50000;
    }
    if (j == m) {
      return 50000;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    return dp[i][j] = v1[i][j] + min(getAns(i + 1, j), getAns(i, j + 1));
  }

  int minPathSum(vector<vector<int>> &grid) {
    n = grid.size();
    m = grid[0].size();
    dp.resize(n + 1, vector<int>(m + 1, -1));
    v1 = grid;
    return getAns(0, 0);
  }
};
