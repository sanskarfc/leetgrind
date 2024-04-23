#include <vector>

using namespace std;

class Solution {
public:
  void dfs(int node, vector<vector<int>> &rooms, vector<int> &visited) {
    visited[node] = true;
    for (auto x : rooms[node]) {
      if (!visited[x]) {
        dfs(x, rooms, visited);
      }
    }
  }

  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    vector<int> visited(n + 1);
    dfs(0, rooms, visited);
    for (int i = 0; i < n; i++) {
      if (!visited[i])
        return false;
    }
    return true;
  }
};
