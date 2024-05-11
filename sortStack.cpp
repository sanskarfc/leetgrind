#include <bits/stdc++.h>
void sortStack(stack<int> &s1) {
  // sort stack in DESC integer
  priority_queue<int, vector<int>, greater<int>> minHeap;
  while (!s1.empty()) {
    minHeap.push(s1.top());
    s1.pop();
  }
  while (!minHeap.empty()) {
    s1.push(minHeap.top());
    minHeap.pop();
  }
}
