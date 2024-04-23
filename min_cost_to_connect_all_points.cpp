#include <vector>

using namespace std;

class Solution {
public:
  struct DSU {
    int connected;
    vector<int> par, sz;

    void init(int n) {
      par = sz = vector<int>(n + 1, 0);
      for (int i = 1; i <= n; i++)
        par[i] = i, sz[i] = 1;
      connected = n;
    }

    int getPar(int u) {
      while (u != par[u]) {
        par[u] = par[par[u]];
        u = par[u];
      }
      return u;
    }

    int getSize(int u) { return sz[getPar(u)]; }

    bool unite(int u, int v) {
      int par1 = getPar(u), par2 = getPar(v);

      if (par1 == par2)
        return false;

      connected--;

      if (sz[par1] > sz[par2])
        swap(par1, par2);

      sz[par2] += sz[par1];
      sz[par1] = 0;
      par[par1] = par[par2];
      return true;
    }
  };

  int manhat(int i, int j, vector<vector<int>> &points) {
    int numx = points[i][0] - points[j][0];
    int numy = points[i][1] - points[j][1];
    if (numx < 0)
      numx = -numx;
    if (numy < 0)
      numy = -numy;
    return (numx + numy);
  }

  int minCostConnectPoints(vector<vector<int>> &points) {
    // we want to create the minimum spanning tree (tree from graph such that
    // all nodes are connected and total cost is the lowest)
    vector<vector<int>> edges;
    int n = points.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        edges.push_back({manhat(i, j, points), i, j});
      }
    }

    sort(edges.begin(), edges.end());

    DSU dsu;
    dsu.init(n + 1);

    int ans = 0;

    for (int i = 0; i < edges.size(); i++) {
      if (dsu.unite(edges[i][1], edges[i][2])) {
        ans += edges[i][0];
        dsu.unite(edges[i][1], edges[i][2]);
      }
    }

    return ans;
  }
};
