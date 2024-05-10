#include <vector>

using namespace std;

class Solution {
public:
  vector<int> selectionSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      int curIndex = i;
      while (curIndex - 1 >= 0 && nums[curIndex] < nums[curIndex - 1]) {
        swap(nums[curIndex], nums[curIndex - 1]);
        curIndex--;
      }
    }
    return nums;
  }
};
