#include <vector>

using namespace std;

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    vector<int> trustThem(n + 1, 0);
    vector<int> theyTrust(n + 1, 0);
    for (int i = 0; i < trust.size(); i++) {
      trustThem[trust[i][1]]++;
      theyTrust[trust[i][0]]++;
    }
    for (int i = 1; i <= n; i++) {
      if (trustThem[i] == n - 1 && theyTrust[i] == 0) {
        return i;
      }
    }
    return -1;
  }
};
