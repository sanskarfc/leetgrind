#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) {
      if (a[1] < b[1]) {
        return true;
      } else if (a[1] == b[1]) {
        if (a[0] < b[0]) {
          return true;
        } else {
          return false;
        }
      } else {
        return false;
      }
    });
    int n = intervals.size();
    int curStart = intervals[0][0];
    int curEnd = intervals[0][1];
    for (int i = 0; i < n; i++) {
      if (intervals[i][0] < curEnd) {
        curStart = min(curStart, intervals[i][0]);
      } else {
        ans.push_back({curStart, curEnd});
        curStart = intervals[i][0];
        curEnd = intervals[i][1];
      }
    }
    ans.push_back({curStart, curEnd});
    return ans;
  }
};
