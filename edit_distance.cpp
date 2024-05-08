#include <string>

using namespace std;

class Solution {
public:
  string word1, word2;
  int n, m;
  vector<vector<int>> dp;

  int getAns(int ind1, int ind2) {
    if (ind2 == m) {
      return n - ind1;
    }
    if (ind1 == n) {
      return m - ind2;
    }
    if (dp[ind1][ind2] != -1) {
      return dp[ind1][ind2];
    }

    if (word1[ind1] == word2[ind2]) {
      return dp[ind1][ind2] = getAns(ind1 + 1, ind2 + 1);
    } else { // replace, delete char, insert char
      return dp[ind1][ind2] =
                 min({1 + getAns(ind1 + 1, ind2 + 1),
                      1 + getAns(ind1 + 1, ind2), 1 + getAns(ind1, ind2 + 1)});
    }
  }

  int minDistance(string w1, string w2) {
    n = w1.size();
    m = w2.size();
    dp.resize(n + 1, vector<int>(m + 1, -1));
    word1 = w1;
    word2 = w2;
    return getAns(0, 0);
  }
};
