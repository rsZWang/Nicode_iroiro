#include "PriorityQueue.h"
#include <iostream>

using namespace std;

class Element {
public:
	int ObjectID;
	int priority;

	Element() {
		ObjectID = -1;
		priority = -1;
	}

	Element(int ObjectID, int priority) {
		this->ObjectID = ObjectID;
		this->priority = priority;
	}
};

void enqueue();
void dequeue();
void changeweight();

PriorityQueue<Element> *queue;
int capacity;

int main(int argc, char* argv[]) {
	cout << "\n***Implementation of Priority Queue by MaxHeap***" << endl << endl;

	cout << "Enter the capacity of priority queue: ";
	cin >> capacity;
	queue = new PriorityQueue<Element>(capacity);
	cout << "Queue with " << capacity << " element(s) is created." << endl;

	while (true) {
		cout << endl << "1. Insert element    2. Delete first element" << endl <<  "3. Change weight of sepcific element    4. Print queue" << endl << "9. Exit" << endl << "Enter number to do specific operation\n: ";
		int operation;
		cin >> operation;
		if (operation == 9) {
			break;
		} else if (operation == 1) {
			enqueue();
			queue->print();
		} else if (operation == 2) {
			dequeue();
			queue->print();
		} else if (operation == 3) {
			changeweight();
			queue->print();
		} else if (operation == 4) {
			queue->print();
		} else {
			continue;
		}
	}

	return 0;
}

void enqueue() {
	cout << "Enter ObjectID: ";
	int objectId;
	cin >> objectId;
	if (objectId >= capacity) {
		cout << "Please enter a number between 0 ~ " << capacity-1 << "(capacity - 1)." << endl;
	} else if (queue->isExists(objectId)) {
		cout << "ObjectID " << objectId  << "already exists." << endl << endl;
	} else {
		cout << "Enter Priority: ";
		int priority;
		cin >> priority;
		queue->enqueue(objectId, priority);
	}
}

void dequeue() {
	if (queue->n > 0) {
		Element element = queue->dequeue();
		cout << "Remove element: [ObjectID =" << element.ObjectID << ", Priority = " << element.priority << "]" << endl;
	} else {
		cout << "Queue is empty.";
	}
}

void changeweight() {
	cout << "Enter ObjectID: ";
	int objectId;
	cin >> objectId;
	if (!queue->isExists(objectId)) {
		cout << "Element " << objectId << "doesn't exist." << endl;
		return;
	} else {
		cout << "Enter new prioirty: ";
		int newPriority;
		cin >> newPriority;
		queue->changeweight(objectId, newPriority);
	}
}