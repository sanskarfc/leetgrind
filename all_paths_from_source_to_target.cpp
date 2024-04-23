#include <vector>

using namespace std;

class Solution {
public:
  void dfs(int node, vector<vector<int>> &adj, vector<vector<int>> &ans,
           int dest, vector<int> tillNow) {
    vector<int> prevTillNow = tillNow;
    for (auto x : adj[node]) {
      tillNow.push_back(x);
      if (x == dest) {
        ans.push_back(tillNow);
        tillNow = prevTillNow;
        continue;
      }
      dfs(x, adj, ans, dest, tillNow);
      tillNow = prevTillNow;
    }
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> ans;
    dfs(0, graph, ans, graph.size() - 1, {0});
    return ans;
  }
};
