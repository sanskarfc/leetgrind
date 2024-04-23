#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    int time = 0;

    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        pair<int, int> node = make_pair(i, j);
        if (grid[i][j] == 2) {
          q.push(node);
        }
      }
    }

    // do bfs here
    int cur_level = 0;
    map<pair<int, int>, int> level;
    while (!q.empty()) {
      pair<int, int> node = q.front();
      q.pop();
      if (level[node] != cur_level) {
        cur_level++;
      }
      for (int i = 0; i < 4; i++) {
        int newX = node.first + x[i];
        int newY = node.second + y[i];
        if (newX < 0 || newX >= n)
          continue;
        if (newY < 0 || newY >= m)
          continue;

        pair<int, int> adjNode = make_pair(newX, newY);
        if (grid[newX][newY] == 1) {
          level[adjNode] = level[node] + 1;
          grid[newX][newY] = 2;
          q.push(adjNode);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }

    return cur_level;
  }
};
