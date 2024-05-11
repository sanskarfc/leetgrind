class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> freq;
    for (int i = 0; i < nums.size(); i++) {
      freq[nums[i]]++;
    }
    map<int, vector<int>> elem;
    for (auto p : freq) {
      elem[-p.second].push_back(p.first);
    }
    int ind = 0;
    vector<int> ans;
    for (auto p : elem) {
      for (auto x : p.second) {
        ans.push_back(x);
        ind++;
        if (ind == k)
          break;
      }
      if (ind == k) {
        break;
      }
    }
    return ans;
  }
};
