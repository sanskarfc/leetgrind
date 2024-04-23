#include <vector>

using namespace std;

class Solution {
public:
  void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj) {
    for (auto x : adj[node]) {
      if (!visited[x]) {
        visited[x] = true;
        dfs(x, visited, adj);
      }
    }
  }

  bool validPath(int n, vector<vector<int>> &edges, int source,
                 int destination) {
    // we will do this using a dfs
    vector<bool> visited(n + 1, false);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < edges.size(); i++) {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
    }
    visited[source] = true;
    dfs(source, visited, adj);
    return visited[destination];
  }
};
