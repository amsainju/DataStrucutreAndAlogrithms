//Stack Using LinkedList
//Arpan Man Sainju
// 02/27/2020
/* Functions
	empty() -> checks if the stack is empty O(1)
	size()  -> returns the size of stack O(1)
	top()   -> returns element in top of stack O(1)
	push(v) -> push a value v in stack O(1)
	pop()   -> removes top element from stack O(1)
*/

#include <iostream>

class Node{
	public:
	int data;
	Node* next;
	
	Node(int value){
		data = value;
		next = NULL;
	}
};

class Stack{
	public:
	Node* head;
	int stack_size;
	
	Stack(){
		head = NULL;
		stack_size = 0;
	}
	
	void push(int value){
		Node* temp = new Node(value);
		if (head == NULL){
			head = temp;
			stack_size = 1;
			return;
		}
		temp->next = head;
		head = temp;	
		stack_size++;
	}
	
	void pop(){
		if (head == NULL){
			std::cout <<" Stack is empty!!" << std::endl;
			return;
		}
		head = head->next;
		stack_size--;
	}
	
	int top(){
		if (head == NULL){
			std::cout <<"Error: Stack is empty!!" << std::endl;
			exit(0);
		}
		return head->data;
	}
		
	bool empty(){
		return (head==NULL);
	}
	
	int size(){
		return stack_size;
	}
		
};

void printElementsinStack(Stack stack){
	while(!stack.empty()){
		std::cout << stack.top() << std::endl;
		stack.pop();		
	}
}
int main(){
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	
	//print size of stack
	std::cout << "Size of Stack is " << stack.size() << std::endl;
	//print elements in stack
	std::cout << "Elements in stack are: " << std::endl;
	printElementsinStack(stack);
	
	
	std::cout << "Before first pop operation top is " << stack.top() <<std::endl;
	stack.pop();
	std::cout << "After first pop operation top  is " <<stack.top() <<std::endl;
	stack.pop();
	std::cout << "After second pop operation top is " <<stack.top() << std::endl;
	stack.pop();
	return 0;
}