#include <vector>

using namespace std;

struct DSU {
  int connected;
  vector<int> sz, par;

  void init(int n) {
    for (int i = 0; i <= n; i++) {
      sz[i] = 1;
      par[i] = i;
    }
  }

  int getPar(int u) {
    while (u != par[u]) {
      par[u] = par[par[u]];
      u = par[u];
    }
    return u;
  }

  int getSize(int u) { return sz[getPar(u)]; }

  void unite(int u, int v) {
    int par1 = getPar(u);
    int par2 = getPar(v);
    if (par1 == par2) {
      return;
    }
    int siz1 = getSize(par1);
    int siz2 = getSize(par2);
    if (siz1 > siz2) {
      swap(par1, par2);
    }
    sz[par2] += sz[par1];
    sz[par1] = 0;
    par[par1] = par[par2];
  }
};
