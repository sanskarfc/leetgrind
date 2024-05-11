class KthLargest {
public:
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int k;

  KthLargest(int kk, vector<int> &nums) {
    int ind = 0;
    k = kk;
    for (int i = 0; i < nums.size(); i++) {
      if (minHeap.size() == k) {
        if (nums[i] > minHeap.top()) {
          minHeap.pop();
          minHeap.push(nums[i]);
        }
      } else {
        minHeap.push(nums[i]);
      }
    }
  }

  int add(int val) {
    if (minHeap.empty()) {
      assert(k == 1);
      minHeap.push(val);
      return val;
    }
    if (minHeap.size() == k) {
      if (val > minHeap.top()) {
        minHeap.pop();
        minHeap.push(val);
      }
    } else {
      minHeap.push(val);
    }
    return minHeap.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
