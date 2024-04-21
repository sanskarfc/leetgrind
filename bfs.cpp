#include <map>
#include <vector>

using namespace std;

vector<vector<int>> adj;
map<int, bool> visited;

void dfs(int node, int parent) {
  visited[node] = true;
  for (auto x : adj[node]) {
    if (!visited[x]) {
      dfs(x, node);
    }
  }
}
