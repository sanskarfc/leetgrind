#include <vector>

using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int count = (nums[0] == 1);
    int maxm = max(0, count);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == 1) {
        if (nums[i - 1] == 1) {
          count++;
        } else {
          count = 1;
        }
      }
      maxm = max(maxm, count);
    }
    return maxm;
  }
};
