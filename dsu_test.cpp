#include <iostream>
#include <vector>

using namespace std;

struct DSU {
  vector<int> sz, par;
  int connected;

  DSU(int n) {
    sz.resize(n + 1);
    par.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
    connected = n;
  }

  int getPar(int node) {
    while (par[node] != node) {
      node = par[node];
      par[node] = par[par[node]];
    }
    return node;
  }

  int getSiz(int node) { return sz[getPar(node)]; }

  void printThings(int n) {
    for (int i = 1; i <= n; i++) {
      cout << "par[" << i << "]: " << getPar(i) << endl;
      cout << "sz[" << i << "]: " << getSiz(i) << endl;
      cout << endl;
    }
  }

  void unite(int node1, int node2) {
    int par1 = getPar(node1);
    int par2 = getPar(node2);
    if (par1 == par2) {
      return;
    }
    int siz1 = getSiz(par1);
    int siz2 = getSiz(par2);

    if (getSiz(par1) > getSiz(par2)) {
      swap(node1, node2);
      swap(par1, par2);
    }

    sz[par2] += sz[par1];
    sz[par1] = 0;
    par[par1] = par2;
  }
};

int main() {
  DSU dsu(5);
  dsu.printThings(5);
  cout << endl;
  dsu.unite(1, 2);
  dsu.printThings(5);
  cout << endl;
  dsu.unite(4, 5);
  dsu.printThings(5);
  cout << endl;
  dsu.unite(1, 4);
  dsu.printThings(5);
  cout << endl;
}
