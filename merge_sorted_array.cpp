#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    swap(n, m);
    int ind1 = n - 1;
    int ind2 = m - 1;
    int backPtr = n + m - 1;
    while (ind1 >= 0 && ind2 >= 0) {
      if (nums1[ind1] >= nums2[ind2]) {
        swap(nums1[ind1], nums1[backPtr]);
        backPtr--;
        ind1--;
      } else {
        swap(nums2[ind2], nums1[backPtr]);
        backPtr--;
        ind2--;
      }
    }
    while (ind2 >= 0) {
      swap(nums2[ind2], nums1[backPtr]);
      backPtr--;
      ind2--;
    }
  }
};
