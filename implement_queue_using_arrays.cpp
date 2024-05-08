#include <vector>

using namespace std;

class Queue {

	int front, back;
	vector<int> arr;

public:
	Queue()
	{
		front = 0;
		back = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		arr[back] = e;
		back++;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if(front == back) {
			return -1;
		}
		front++;
		return arr[front - 1];
	}
};
