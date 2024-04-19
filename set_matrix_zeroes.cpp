#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> rows, cols;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          rows.push_back(i);
          cols.push_back(j);
        }
      }
    }

    for (int i = 0; i < (int)rows.size(); i++) {
      for (int j = 0; j < m; j++) {
        matrix[rows[i]][j] = 0;
      }
    }

    for (int j = 0; j < (int)cols.size(); j++) {
      for (int i = 0; i < n; i++) {
        matrix[i][cols[j]] = 0;
      }
    }
  }
};
