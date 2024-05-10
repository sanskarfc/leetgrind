#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int n = nums.size();
    int p0 = 0;
    int p2 = n - 1;
    while (p0 < n && nums[p0] == 0) {
      p0++;
    }
    while (p2 >= 0 && nums[p2] == 2) {
      p2--;
    }
    // p0 points to first non 0 from left
    // p2 points to first non 2 from right
    for (int i = p0; i <= p2; i++) {
      if (nums[i] == 0) {
        swap(nums[p0], nums[i]);
        p0++;
      } else if (nums[i] == 2) {
        swap(nums[p2], nums[i]);
        while (p2 >= 0 && nums[p2] == 2)
          p2--;
        if (nums[i] == 0) {
          swap(nums[p0], nums[i]);
          p0++;
        }
      }
    }
  }
};
