#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 1) {
      return {{1}};
    } else if (numRows == 2) {
      return {{1}, {1, 1}};
    }

    vector<vector<int>> ans;
    ans.push_back({1});
    ans.push_back({1, 1});

    for (int row = 3; row <= numRows; row++) {
      vector<int> temp;
      temp.push_back(1);
      for (int i = 1; i < ans[row - 2].size(); i++) {
        temp.push_back(ans[row - 2][i] + ans[row - 2][i - 1]);
      }
      temp.push_back(1);
      ans.push_back(temp);
    }

    return ans;
  }
};
