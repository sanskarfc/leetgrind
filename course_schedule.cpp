class Solution {
public:
  // visited[x] = 1 (visited in this cycle)
  // visited[x] = 0 (not visited yet)
  // visited[x] = 2 (visited in previous cycle)

  bool foundCycle = false;

  void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = 1;
    for (auto x : adj[node]) {
      if (visited[x] == 1) {
        foundCycle = true;
        return;
      } else if (visited[x] == 0) {
        dfs(x, adj, visited);
      }
    }
    visited[node] = 2;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    // [a, b] --> must take b before a

    vector<vector<int>> adj(numCourses + 1);
    vector<int> visited(numCourses + 1);

    for (int i = 0; i < prerequisites.size(); i++) {
      adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for (int i = 0; i < numCourses; i++) {
      dfs(i, adj, visited);
      if (foundCycle)
        return false;
    }

    return true;
  }
};
