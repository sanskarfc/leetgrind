#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int lo = 0;
    int hi = n - 1;
    while (hi - lo > 5) {
      int mid = lo + (hi - lo) / 2;
      if (matrix[mid][0] > target) {
        hi = mid - 1;
      } else {
        lo = mid;
      }
    }
    int x = -1;
    for (x = hi; x >= lo; x--) {
      if (matrix[x][0] <= target) {
        break;
      }
    }
    if (x == -1)
      return false;
    auto it = lower_bound(matrix[x].begin(), matrix[x].end(), target);
    if (it == matrix[x].end())
      return false;
    if (*it == target) {
      return true;
    }
    return false;
  }
};
