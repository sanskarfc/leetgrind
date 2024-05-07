#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int maxm = INT_MIN;
    set<pair<int, int>> s1;
    for (int i = n - 1; i >= 0; i--) {
      maxm = max(maxm, nums[i]);
      if (nums[i] < maxm) {
        auto it = s1.lower_bound(make_pair(nums[i], 0));
        if (it != s1.end()) {
          while (it != s1.end() && it->first == nums[i]) {
            it++;
          }
          if (it != s1.end()) {
            int val = it->first;
            int ind = it->second;
            swap(nums[i], nums[ind]);
            sort(nums.begin() + i + 1, nums.end());
            return;
          }
        }
      }
      s1.insert(make_pair(nums[i], i));
    }
    sort(nums.begin(), nums.end());
  }
};
