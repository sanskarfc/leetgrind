#include <iostream>
#include <queue>
#include <vector>

int main() {
  // Max heap
  std::priority_queue<int> maxHeap;

  // Adding elements to the heap
  maxHeap.push(10);
  maxHeap.push(30);
  maxHeap.push(20);
  maxHeap.push(5);
  maxHeap.push(1);

  // Display elements
  std::cout << "Max Heap: ";
  while (!maxHeap.empty()) {
    std::cout << maxHeap.top() << " ";
    maxHeap.pop();
  }
  std::cout << std::endl;

  return 0;
}
