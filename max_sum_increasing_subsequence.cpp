//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	  vector<int> v1;
	  vector<vector<int>> dp;
	  int nn;
      
      int getAns(int ind, int lastInd) {
          if(ind == nn) {
              return 0;
          }
          
          if(lastInd == -1) {
              return max(v1[ind] + getAns(ind + 1, ind), getAns(ind + 1, -1));
          }
          
          if(dp[ind][lastInd] != -1) {
              return dp[ind][lastInd];
          }
          
          if (v1[ind] > v1[lastInd]) {
            return dp[ind][lastInd] = max(v1[ind] + getAns(ind + 1, ind), getAns(ind + 1, lastInd));
          } 
          else {
            return dp[ind][lastInd] = getAns(ind + 1, lastInd);
          }
      }
    
      int maxSumIS(int arr[], int n) {
          nn = n;
        for (int i = 0; i < n; i++) {
          v1.push_back(arr[i]);
        }
        dp.resize(n + 1, vector<int>(n + 1, -1));
        return getAns(0,-1);
      }

};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
