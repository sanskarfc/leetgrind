//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  vector<string> ans;

  void getAns(vector<vector<int>> &grid, int i, int j, string &s) {
    int n = grid.size();
    if (i == n) {
      return;
    }
    if (j == n) {
      return;
    }
    if (i == n - 1 && j == n - 1) {
      ans.push_back(s);
    }
    if (i + 1 < n && grid[i + 1][j] == 1) {
      grid[i][j] = 0;
      s.append("D");
      getAns(grid, i + 1, j, s);
      s.pop_back();
      grid[i][j] = 1;
    }
    if (j + 1 < n && grid[i][j + 1] == 1) {
      grid[i][j] = 0;
      s.append("R");
      getAns(grid, i, j + 1, s);
      s.pop_back();
      grid[i][j] = 1;
    }
    if (i - 1 >= 0 && grid[i - 1][j] == 1) {
      grid[i][j] = 0;
      s.append("U");
      getAns(grid, i - 1, j, s);
      s.pop_back();
      grid[i][j] = 1;
    }
    if (j - 1 < n && grid[i][j - 1] == 1) {
      grid[i][j] = 0;
      s.append("L");
      getAns(grid, i, j - 1, s);
      s.pop_back();
      grid[i][j] = 1;
    }
  }

  vector<string> findPath(vector<vector<int>> &m, int n) {
    string s = "";
    if (m[0][0] == 0) {
      return {"-1"};
    }
    getAns(m, 0, 0, s);
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> m[i][j];
      }
    }
    Solution obj;
    vector<string> result = obj.findPath(m, n);
    sort(result.begin(), result.end());
    if (result.size() == 0)
      cout << -1;
    else
      for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
