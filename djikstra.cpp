#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  map<int, int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // init
    set<pair<int, int>> s1;
    map<int, int> d;
    for (int i = 0; i < V; i++) {
      d[i] = INT_MAX;
    }

    // insert source
    d[S] = 0;
    s1.insert(make_pair(0, S));

    while (!s1.empty()) {
      int dTillNow = (*s1.begin()).first;
      int node = (*s1.begin()).second;
      s1.erase(s1.begin());
      for (auto x : adj[node]) {
        int adjNode = x[0];
        int dEdge = x[1];
        if (dTillNow + dEdge < d[adjNode]) {
          if (d[adjNode] == INT_MAX) {
            s1.erase(s1.find(make_pair(d[adjNode], adjNode)));
          }
          d[adjNode] = dTillNow + dEdge;
          s1.insert(make_pair(d[adjNode], adjNode));
        }
      }
    }

    return d;
  }
};
