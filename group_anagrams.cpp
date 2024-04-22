#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<int>> v1(strs.size(), vector<int>(26, 0));
    map<vector<int>, vector<string>> m1;
    for (int i = 0; i < strs.size(); i++) {
      for (int j = 0; j < strs[i].length(); j++) {
        v1[i][strs[i][j] - 'a']++;
      }
      m1[v1[i]].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto p : m1) {
      vector<string> tempAns;
      for (auto s : p.second) {
        tempAns.push_back(s);
      }
      ans.push_back(tempAns);
    }
    return ans;
  }
};
