class Solution {
public:
  string reverseWords(string s) {
    int n = s.length();
    string word = "";
    string ans = "";
    bool check = true;
    vector<string> v1;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == ' ') {
            if(word[0] == ' ' || word.empty()) continue;
            if(word[word.size() - 1] == ' ') continue;
            reverse(word.begin(), word.end());
            v1.push_back(word);
            word = "";
        }
        else {
            word += s[i];
        }
    }
    if(!word.empty() && word[0] != ' ' && word[word.size() - 1] != ' ') {
        reverse(word.begin(), word.end());
        v1.push_back(word);
    }
    for(int i = 0; i < v1.size() - 1; i++) {
        ans += v1[i];
        ans += " ";
    }
    ans += v1[v1.size() - 1];
    return ans;
  }
};
