#include <vector>

using namespace std;

class Solution {
public:
  // quicksort
  int paritioner(vector<int> &arr, int start, int end) {
    int pivot = arr[start];
    // count: contains the number of elements smaller than first element in
    // array
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
      if (arr[i] <= pivot) {
        count++;
      }
    }

    // chose our pivotIndex
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // keep smaller than pivot to left and greater than pivot to right
    int i = start;
    int j = end;
    while (i < pivotIndex && j > pivotIndex) {
      while (arr[i] <= pivot) {
        i++;
      }
      while (arr[j] > pivot) {
        j--;
      }
      if (i < pivotIndex && j > pivotIndex) {
        swap(arr[i], arr[j]);
        i++;
        j--;
      }
    }
    return pivotIndex;
  }

  void quickSort(vector<int> &arr, int start, int end) {
    if (start >= end)
      return;
    int p = paritioner(arr, start, end); // find pivot
    quickSort(arr, start, p - 1);        // sort before pivot
    quickSort(arr, p + 1, end);          // sort after pivot
  }

  vector<int> sortArray(vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }
};
