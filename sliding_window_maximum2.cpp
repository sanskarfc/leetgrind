class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<pair<int, int>> dq;
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (!dq.empty() && dq.front().second <= i - k) {
        dq.pop_front();
      }
      if (dq.size() == k) { // pop the front wala
        while (!dq.empty()) {
          if (dq.back().first <= nums[i]) {
            dq.pop_back();
          } else {
            dq.push_back(make_pair(nums[i], i));
            break;
          }
        }
        if (dq.empty()) {
          dq.push_back(make_pair(nums[i], i));
        }
      } else {
        while (!dq.empty()) {
          if (dq.back().first <= nums[i]) {
            dq.pop_back();
          } else {
            dq.push_back(make_pair(nums[i], i));
            break;
          }
        }
        if (dq.empty()) {
          dq.push_back(make_pair(nums[i], i));
        }
      }
      if (i >= k - 1) {
        ans.push_back(dq.front().first);
      }
    }
    return ans;
  }
};
