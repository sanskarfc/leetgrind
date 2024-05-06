//{ Driver Code Starts
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// } Driver Code Ends
class Solution {
public:
  int maxMeetings(int start[], int end[], int n) {
    vector<pair<int, int>> v1;
    for (int i = 0; i < n; i++) {
      v1.push_back(make_pair(start[i], end[i]));
    }
    sort(v1.begin(), v1.end(), [&](pair<int, int> p1, pair<int, int> p2) {
      if (p1.second < p2.second) {
        return true;
      } else if (p1.second == p2.second) {
        if (p1.first < p2.first)
          return true;
        else
          return false;
      } else {
        return false;
      }
    });
    int cur_end = -1;
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (cur_end < v1[i].first) {
        cur_end = v1[i].second;
        count++;
      }
    }
    return count;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; i++)
      cin >> start[i];

    for (int i = 0; i < n; i++)
      cin >> end[i];

    Solution ob;
    int ans = ob.maxMeetings(start, end, n);
    cout << ans << endl;
  }
  return 0;
}
// } Driver Code Ends
