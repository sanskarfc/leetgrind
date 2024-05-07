#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int cand = nums[0];
    int count = 0;
    for (auto x : nums) {
      if (count == 0) {
        cand = x;
      }
      if (x == cand) {
        count++;
      } else {
        count--;
      }
    }
    return cand;
  }
};
