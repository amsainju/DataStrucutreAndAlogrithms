// Doubly Linked List 
//Arpan Man Sainju
//03/02/2020
/* 
Description:
	A doubly linked list contains an extra pointer, typically 
	called previous pointer, together with next pointer and 
	data.
	Fucntions 
	push(v)   				: push element on head of linked list
	append(v)				: append element on tail of linked list
	pop()					: pop element on top/left/head of linked list
	popleft()				: pop element on top/left/head of linked list
	popright()				: pop element on end/right/tail of linked list
	remove(i)				: remove element from given index
	insertonIndex(i)		: insert element on given index
	getNthNode(n)			: get data on nth node
	size()					: get number of elements on linked list
	printAllElements		: print all the elements on linked list
	search(v)				: search for value v in linked list returns true if found else returns false
	
	
	use append and pop for queue
	use push and pop for stack
*/
#include <iostream>
#include <string>
class Node{
	public:
		int data;
		Node* next;
		Node* prev;
	Node(int value){
		data = value;
		next = NULL;
		prev = NULL;
	}
};

class DoubleLinkedList{
	public:
		Node* head;
		Node* rear;
		int list_size;
		
	DoubleLinkedList(){
		head = NULL;
		rear = NULL;
		list_size = 0;
	}
	
	void push(int value){
		Node* node = new Node(value);
		if(head == NULL){
			head = node;
			rear = node;
			list_size =1 ;
			return;
		}
		node->next = head;
		head->prev = node;
		head = node;
		list_size++;
	}
	
	void append(int value){
		Node* node = new Node(value);
		if(head==NULL){
			head = node;
			rear = node;
			list_size=1;
			return;
		}
		rear->next = node;
		node->prev = rear;
		rear = node;	
		list_size++;
	}
	
	void insertOnIndex(int index,int value){
		Node* node = new Node(value);
		int counter = 0;
		Node *list = head;
		if(index == 0){
			push(value);
			return;
		}
		while(list!=NULL){
			if(counter == index){
				Node* prevNode = list->prev;
				prevNode->next = node;
				node->prev = prevNode;
				node->next= list;
				list->prev = node;
				list_size++;
				return;
			}
			list = list->next;
			counter++;
		}
		std::cout<<"Index out of range"<<std::endl;
		assert(0);
	}
		
	void printAllElements(){
		Node*list = head;
		while(list!=NULL){
			std::cout<<list->data<< " ";
			list = list->next;
		}
		std::cout<<std::endl;	
	}
	
	void pop(){
		if(head!=NULL){
			head = head->next;
			head->prev = NULL;
			list_size--;
		}
		else{
			head=NULL;
			rear = NULL;
			list_size=0;
		}
	}
	
	void popleft(){
		pop();
	}
	
	void popright(){
		if(rear!=NULL){
			//std::cout<<"read->prev->data"<<rear->prev->data<<std::endl;
			rear = rear->prev;
			if(rear!=NULL){
				rear->next= NULL;
				list_size--;
			}
			else{
				rear= NULL;
				head = NULL;
				list_size=0;
			}
		}
		else{
			rear = NULL;
			head = NULL;
			list_size=0;
		}

	}
	
	int top(){
		if(head!=NULL)
			return head->data;
		else{
			std::cout<<"No elements"<<std::endl;
			exit(0);
		}
	}
	
	int getNthNode(int n){
		int counter = 0;
		Node* list = head;
		while(list!=NULL){
			if(counter == n){
				return list->data;				
			}
			list = list->next;
			counter++;
		}
		std::cout<<"Index out of range!!"<<std::endl;
		assert(0);		
	}	
	
	void remove(int index){
		int counter = 0;
		Node* list = head;
		if(index ==0){
			pop();
			return;
		}
		while(list!=NULL){
			if(counter == index-1){
				if(list->next!=NULL){
					list->next = list->next->next;
				}
				else{
					break;
				}
				if(list->next!=NULL){
					list->next->prev = list;
				}
				list_size--;
				return;
			}
			list = list->next;
			counter++;
		}
		std::cout<<"Index out of range!!"<<std::endl;
		assert(0);		
	}
	int size(){
		return list_size;
	}
	
	bool search(int value){
		Node* list = head;
		while(list!=NULL){
			if(list->data == value){
				return true;
			}
			list = list->next;
		}
		return false;
	}
};

int main(){
	DoubleLinkedList stack = DoubleLinkedList();
	stack.push(5);
	stack.push(7);
	stack.push(8);
	stack.push(10);
	stack.push(11);
	stack.push(12);
	stack.push(18);
	stack.push(20);
	
	std::cout<<"\nPrinting all the elements in stack :"<<std::endl;
	stack.printAllElements();
	
	std::cout<<"\nAdding 3 in 3rd position"<<std::endl;
	stack.insertOnIndex(3,6);
	
	std::cout<<"\nPrinting all the elements:"<<std::endl;
	stack.printAllElements();
	
	DoubleLinkedList queue;
	queue.append(1);
	queue.append(2);
	queue.append(3);
	queue.append(4);
	queue.append(5);
	
	std::cout<<"\nPrinting all the elements in queue:"<<std::endl;
	queue.printAllElements();
	
	std::cout<<"Top of stack: "<<stack.top()<<std::endl;
	std::cout<<"Top of queue: "<<queue.top()<<std::endl;
	
	std::cout<<"2nd node in stack:"<<stack.getNthNode(1)<<std::endl;
	std::cout<<"2nd node in queue:"<<queue.getNthNode(1)<<std::endl;
	
	std::cout<<"Applying pop operation to stack"<<std::endl;
	stack.pop();
	stack.printAllElements();
	
	std::cout<<"Applying popright operation to stack"<<std::endl;
	stack.popright();
	stack.printAllElements();
	
	std::cout<<"Applying popleft operation to stack"<<std::endl;
	stack.popleft();
	stack.printAllElements();
	
	std::cout<<"Applying pop operation to queue"<<std::endl;
	queue.pop();
	queue.printAllElements();
	
	std::cout<<"Applying popleft operation to queue"<<std::endl;
	queue.popleft();
	queue.printAllElements();
	
	std::cout<<"Applying popright operation to queue"<<std::endl;
	queue.popright();
	queue.printAllElements();
	
	std::cout<<"Applying popright operation to queue"<<std::endl;
	queue.popright();
	queue.printAllElements();
	
	std::cout<<"Applying popright operation to queue"<<std::endl;
	queue.popright();
	queue.printAllElements();
	
	std::cout<<"\n size of stack is "<<stack.size()<<std::endl;
	std::cout<<"\nRemoving element in index 4 of stack "<<std::endl;
	stack.remove(4);
	stack.printAllElements();
	std::cout<<"\n size of stack is "<<stack.size()<<std::endl;
	
	return 0;
	
}