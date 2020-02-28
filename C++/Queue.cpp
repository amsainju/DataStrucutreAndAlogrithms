#include <iostream>

class Node {
public:
	int data;
	Node* next;

	Node(int value) {
		data = value;
	}
};
class Queue {
public:
	Node* rear;
	Node* front;

	Queue() {
		front = rear = NULL;
	}

	void enQueue(int value) {
		Node* temp = new Node(value);
		if (rear == NULL) {
			front = temp;
			rear = temp;
			return;
		}
		else {
			rear->next = temp;
			rear = temp;
		}
	}

	int deQueue() {
		if (front == NULL) {
			return -1;
		}
		int value = front->data;
		front = front->next;
		if (front == NULL) {
			rear = NULL;
		}
		return value;
	}
};
int main() {
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	int first = q.deQueue();
	int second = q.deQueue();
	int third = q.deQueue();
	std::cout << first << " " << second << " " << third << std::endl;
	return 0;
}