#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    bool pos = false;
    for (int i = 0; i < nums.size(); i++)
      pos = ((nums[i] > 0) | pos);
    if (!pos) {
      int max_val = INT_MIN;
      for (int i = 0; i < nums.size(); i++) {
        max_val = max(max_val, nums[i]);
      }
      return max_val;
    }
    int sum = 0;
    int max_sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      max_sum = max(max_sum, sum);
      if (sum + nums[i] > 0) {
        sum += nums[i];
      } else {
        sum = 0;
      }
    }
    max_sum = max(max_sum, sum);
    return max_sum;
  }
};
