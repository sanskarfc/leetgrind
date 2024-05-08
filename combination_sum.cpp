#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> cand;
  int tar;
  vector<int> temp;
  vector<vector<int>> ans;
  void subset(int ind, int sum) {
    if (sum == tar) {
      ans.push_back(temp);
      return;
    }
    if (sum > tar) {
      return;
    }
    if (ind == cand.size()) {
      return;
    }
    temp.push_back(cand[ind]);
    subset(ind, sum + cand[ind]);
    temp.pop_back();
    subset(ind + 1, sum);
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    cand = candidates;
    tar = target;
    subset(0, 0);
    return ans;
  }
};
