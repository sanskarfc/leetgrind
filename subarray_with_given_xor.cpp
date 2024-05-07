#include <vector>

using namespace std;

int Solution::solve(vector<int> &A, int B) {
  // we count prefix xor in hashmaps
  map<int, int> m1;
  int x = 0;
  int ans = 0;
  for (int i = 0; i < A.size(); i++) {
    m1[x]++;
    x = (x ^ A[i]);
    int needed = (x ^ B);
    ans += (m1[needed]);
  }
  return ans;
}
