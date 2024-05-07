#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n == 1) {
      return 0;
    }
    vector<int> suff(n + 1);
    suff[n - 1] = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suff[i] = max(prices[i], suff[i + 1]);
    }
    int maxm = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
      maxm = max(maxm, suff[i] - prices[i]);
    }
    return maxm;
  }
};
