#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < edges.size(); i++) {
      indeg[edges[i][1]]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (!indeg[i])
        ans.push_back(i);
    }
    return ans;
  }
};
