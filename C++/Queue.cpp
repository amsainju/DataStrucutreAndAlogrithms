//Queue Using LinkedList
//Arpan Man Sainju
// 02/27/2020
/* Functions
	empty() -> checks if the quque is empty O(1)
	size()  -> returns the size of quque O(1)
	front()   -> returns element in front of stack O(1)
	push(v) -> push a value v in back of queue O(1)
	pop()   -> removes front element from queue O(1)
*/

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
	Node* qrear;
	Node* qfront;
	int queue_size;
	Queue() {
		qfront = qrear = NULL;
		queue_size = 0;
	}

	void push(int value) {
		Node* temp = new Node(value);
		if (qrear == NULL) {
			qfront = temp;
			qrear = temp;
			queue_size =1;
			return;
		}
		else {
			qrear->next = temp;
			qrear = temp;
			queue_size++;
		}
	}

	void pop() {
		if (qfront == NULL) {
			std::cout << "Empty queue!!"<< std::endl;
		}
		qfront = qfront->next;
		queue_size--;
		if (queue_size==0) {
			qrear = NULL;
			qfront = NULL;
		}
	}
	
	int front(){
		if (qfront == NULL) {
			std::cout << "Error: empty queue!!"<< std::endl;
			exit(0);
		}
		return qfront->data;
	}
	
	int size(){
		return queue_size;		
	}
	
	bool empty(){
		if (queue_size == 0) return true;
		return false;
	}
};

void printElementsinQueue(Queue queue){
	while(!queue.empty()){
		std::cout << queue.front() << std::endl;
		queue.pop();		
	}
}

int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	
	
	//print size of queue
	std::cout << "Size of Queue is " << q.size() << std::endl;
	//print elements in queue
	std::cout << "Elements in queue are: " << std::endl;
	printElementsinQueue(q);
	
	cout<<"Queue Empty?";
	q.empty() ? std::cout<<" True"<<std::endl : std::cout<<" False"<<std::endl ;
	std::cout <<std::endl;
	
	std::cout << "Before first pop operation front is " << q.front() <<std::endl;
	q.pop();
	std::cout << "After first pop operation front  is " <<q.front() <<std::endl;
	q.pop();
	std::cout << "After second pop operation front is " <<q.front() << std::endl;
	q.pop();
	std::cout <<std::endl;
	cout<<"Queue Empty?";
	q.empty() ? std::cout<<" True"<<std::endl : std::cout<<" False"<<std::endl ;

	return 0;
}