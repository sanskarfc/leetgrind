vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  set<pair<int,int>> s;
  priority_queue<pair<int,pair<int,int>>> pq;
  int n1 = A.size();
  int n2 = B.size();
  pq.push(make_pair(A[n1 - 1] + B[n2 - 1], make_pair(n1 - 1, n2 - 1)));
  s.insert(make_pair(n1 - 1, n2 - 1));
  vector<int> ans;
  for(int i = 0; i < C; i++) {
    pair<int,pair<int,int>> p = pq.top();
    pq.pop();
    
    int sum = p.first;
    int ind1 = p.second.first;
    int ind2 = p.second.second;
    ans.push_back(sum);

    if(s.find(make_pair(ind1 - 1, ind2)) == s.end()) {
        pq.push(make_pair(A[ind1 - 1] + B[ind2], make_pair(ind1 - 1, ind2)));   
        s.insert(make_pair(ind1 - 1, ind2)); 
    }
    if(s.find(make_pair(ind1, ind2 - 1)) == s.end()) {
        pq.push(make_pair(A[ind1] + B[ind2 - 1], make_pair(ind1, ind2 - 1)));   
        s.insert(make_pair(ind1, ind2 - 1));
    }
  }
  return ans;

}
