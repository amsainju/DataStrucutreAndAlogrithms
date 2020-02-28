// STL Stack (LIFO)
//Arpan Man Sainju
//02/27/2020
/* Functions associated with stacks are:
	empty() -> checks if the stack is empty O(1)
	size()  -> returns the size of stack O(1)
	top()   -> returns element in top of stack O(1)
	push(v) -> push a value v in stack O(1)
	pop()   -> removes top element from stack O(1)

*/

#include <iostream>
#include<stack>

void printElementsinStack(stack<int> stack){
	while(!stack.empty()){
		std::cout<< stack.top()<<std::endl;
		stack.pop();
	}
}

int main(){
	stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	std::cout<<"The stack is:"<<std::endl;
	printElementsinStack(stack);
	
	//print size of stack
	std::cout << "Size of stack is " << stack.size() << std::endl;
	
	//print top of stack
	std::cout << "Element in the top of stack is " << stack.top() << std::endl;
	
	//pop operation
	stack.pop();
	
	//print elements after pop
	std::cout << "Elements in stack after first pop operation: " << std::endl;
	printElementsinStack(stack);
	
	return 0;
}
