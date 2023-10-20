#include<bits/stdc++.h>
using namespace std;

class Queue {

	int front, rear;
	vector<int> arr;
	int cnt=0;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		// Write your code here.
		if(cnt == arr.size()) return;
		arr[rear%arr.size()] = e;
		cnt++;
		rear++;

	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		// Write your code here.
		if(cnt == 0)
		{
			rear=front=0;
			return -1;
		}
		int num = arr[front%arr.size()];
		front++;
		cnt--;
		return num;
	}
};