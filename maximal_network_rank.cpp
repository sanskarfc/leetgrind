#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<int> deg(n + 1, 0);
    set<pair<int, int>> s1;
    for (int i = 0; i < roads.size(); i++) {
      deg[roads[i][0]]++;
      deg[roads[i][1]]++;
      s1.insert(make_pair(min(roads[i][0], roads[i][1]),
                          max(roads[i][0], roads[i][1])));
    }
    int maxm = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        pair<int, int> p = make_pair(min(i, j), max(i, j));
        maxm = max(maxm, deg[i] + deg[j] - (s1.find(p) != s1.end()));
      }
    }

    return maxm;
  }
};
