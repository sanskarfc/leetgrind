#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int lo = 0;
    int hi = nums.size() - 1;
    int mid;
    while (hi - lo > 5) {
      mid = (hi - lo) / 2 + lo;
      if (nums[lo] < nums[hi]) {
        return nums[lo];
      }
      if (nums[lo] < nums[mid]) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    int minm = INT_MAX;
    for (int i = lo; i <= hi; i++) {
      minm = min(minm, nums[i]);
    }
    return minm;
  }
};
