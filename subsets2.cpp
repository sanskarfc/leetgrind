#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  set<vector<int>> ans;
  void subset(vector<int> &nums, int ind, vector<int> v1) {
    if (ind == nums.size()) {
      sort(v1.begin(), v1.end());
      ans.insert(v1);
    } else {
      v1.push_back(nums[ind]);
      subset(nums, ind + 1, v1);
      v1.pop_back();
      subset(nums, ind + 1, v1);
    }
  }
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> v1 = {};
    vector<vector<int>> toReturn;
    subset(nums, 0, v1);
    for (auto v : ans) {
      toReturn.push_back(v);
    }
    return toReturn;
  }
};
