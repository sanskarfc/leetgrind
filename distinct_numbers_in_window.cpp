vector<int> Solution::dNums(vector<int> &A, int B) {
  set<int> s1;
  map<int, int> freq;
  int N = A.size();
  if (B > N) {
    return {};
  }
  for (int i = 0; i < B; i++) {
    s1.insert(A[i]);
    freq[A[i]]++;
  }
  vector<int> ans;
  ans.push_back(s1.size());
  for (int i = 1; i + B - 1 < N; i++) {
    freq[A[i - 1]]--;
    if (freq[A[i - 1]] == 0) {
      s1.erase(A[i - 1]);
    }
    s1.insert(A[i + B - 1]);
    freq[A[i + B - 1]]++;
    ans.push_back(s1.size());
  }
  return ans;
}
