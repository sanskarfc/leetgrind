//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     vector<int> s1;
     void subset(vector<int> &arr, int ind, int sum) {
        if(ind == arr.size()) {
          s1.push_back(sum);
        }
        else {
          subset(arr, ind + 1, sum);
          subset(arr, ind + 1, sum + arr[ind]);
        }
      } 

    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> ans;
        subset(arr,0,0);
        return s1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
