#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> give_perm(vector<int> &nums) {
    vector<int> temp;
    int n = nums.size();
    if (n == 1) {
      vector<vector<int>> toReturn;
      toReturn.push_back(nums);
      return toReturn;
    }

    for (int i = 0; i < n - 1; i++) {
      temp.push_back(nums[i]);
    }
    vector<vector<int>> mid = give_perm(temp);
    vector<vector<int>> toReturn;
    for (auto v : mid) {
      int siz = v.size();
      for (int i = 0; i < siz; i++) {
        vector<int> vv;
        vv = v;
        v.insert(v.begin() + i, nums[n - 1]);
        toReturn.push_back(v);
        v = vv;
      }
      v.push_back(nums[n - 1]);
      toReturn.push_back(v);
    }
    return toReturn;
  }
  vector<vector<int>> permute(vector<int> &nums) { return give_perm(nums); }
};
