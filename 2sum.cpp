#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> numIndex;
    for (int i = 0; i < (int)nums.size(); i++) {
      if (numIndex[target - nums[i]] != 0) {
        return {i, numIndex[target - nums[i]] - 1};
      }
      numIndex[nums[i]] = i + 1;
    }
    return {};
  }
};
