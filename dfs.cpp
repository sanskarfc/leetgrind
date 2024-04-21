#include <map>
#include <queue>

using namespace std;

int main() {
  map<int, bool> visited;
  vector<vector<int>> adj;
  int source;

  queue<int> q;
  q.push(source);
  visited[source] = true;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto x : adj[node]) {
      if (!visited[x]) {
        q.push(x);
        visited[x] = true;
      }
    }
  }
}
