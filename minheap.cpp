#include <functional> // For std::greater
#include <iostream>
#include <queue>
#include <vector>

int main() {
  // Min heap
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  // Adding elements to the heap
  minHeap.push(10);
  minHeap.push(30);
  minHeap.push(20);
  minHeap.push(5);
  minHeap.push(1);

  // Display elements
  std::cout << "Min Heap: ";
  while (!minHeap.empty()) {
    std::cout << minHeap.top() << " ";
    minHeap.pop();
  }
  std::cout << std::endl;

  return 0;
}
