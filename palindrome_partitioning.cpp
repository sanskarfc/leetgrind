class Solution {
public:
  vector<vector<string>> ans;

  bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }

  void getAns(string &s, int start, int end, vector<string> &temp) {
    if (start > end) {
      ans.push_back(temp);
      return;
    }
    if (start == end) { // base case
      temp.push_back(s.substr(end, 1));
      ans.push_back(temp);
      temp.pop_back();
      return;
    }
    for (int len = 1; len <= end - start + 1; len++) {
      string ss = s.substr(start, len);
      if (isPalindrome(ss)) {
        temp.push_back(ss);
        getAns(s, start + len, end, temp);
        temp.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    vector<string> v1;
    getAns(s, 0, s.size() - 1, v1);
    return ans;
  }
};
