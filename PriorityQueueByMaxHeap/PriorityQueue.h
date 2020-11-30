#include "heap.h"

template <typename T> class PriorityQueue {
private:
	T *array;
	T *positionArray;
	int maxSize;

public:
	int n;

	PriorityQueue(int maxSize) {
		n = 0;
		this->maxSize = maxSize;
		array = new T[maxSize];
		positionArray = new T[maxSize];
	}

	void enqueue(int ObjectID, int priority) {
		heap<T, Comp<T> > *h = new heap<T, Comp<T> >(array, n, maxSize);
		T *newT = new T(ObjectID, priority);
		h->insert(*newT);
		positionArray[ObjectID].ObjectID = ObjectID;
		positionArray[ObjectID].priority = priority;
		n += 1;
		cout << "New element: [ObjectID = " << newT->ObjectID << ", Priority = " << newT->priority << "]" << endl;
	}

	T dequeue() {
		heap<T, Comp<T> > *h = new heap<T, Comp<T> >(array, n, maxSize);
		T obj = h->removefirst();
		n -= 1;
		array[n].ObjectID = -1;
		array[n].priority = -1;
		positionArray[obj.ObjectID].ObjectID = -1;
		positionArray[obj.ObjectID].priority = -1;
		return obj;
	}

	void changeweight(int ObjectID, int newPriority) {
		int priority = positionArray[ObjectID].priority;
		heap<T, Comp<T> > *h = new heap<T, Comp<T> >(array, n, maxSize);
		int heapPosition = h->find(priority);
		array[heapPosition].priority = newPriority;
		h->buildHeap();
		positionArray[ObjectID].priority = newPriority;
		cout << "Update ObjectID " << array[heapPosition].ObjectID << "'s priority: " << array[heapPosition].priority << endl;
	}

	bool isExists(int ObjectID) {
		if (positionArray[ObjectID].priority != -1) {
			return true;
		} else {
			return false;
		}
	}

	void print() {
		int isEmpty = true;
		for (int i=0; i<maxSize; i++) {
			if (array[i].ObjectID != -1) {
				isEmpty = false;
				cout << "[" << array[i].ObjectID << "," << array[i].priority << "] ";
			}
		}
		if (isEmpty) {
			cout << "Queue is empty.";
		}
 		cout << endl;
	}
};