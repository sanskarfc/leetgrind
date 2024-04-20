#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int p1, p2, p3;
    int n = nums.size();
    while (p1 < n && nums[p1] == 0)
      p1++;

    for (int i = p1 + 1; i < n; i++) {
      if (nums[i] == 0) {
        swap(nums[i], nums[p1]);
        p1++;
      }
    }

    while (p1 < n && nums[p1] == 1)
      p1++;

    for (int i = p1 + 1; i < n; i++) {
      if (nums[i] == 1) {
        swap(nums[i], nums[p1]);
        p1++;
      }
    }
  }
};
