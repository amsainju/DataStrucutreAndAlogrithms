// STL queue (FIFO)
// Arpan Man Sainju
//02/27/2020

#include <iostream>
#include <queue>

void printElementsinQueue(queue<int> que){
	while(!que.empty()){
		std::cout<< que.front() << std::endl;
		que.pop();
	}
}

int main(){
	queue<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	
	//show elemets in que
	std::cout << "Elements in queue are: " << std::endl;
	printElementsinQueue(que);
	
	std::cout << "Queue size is " << que.size() << std::endl;
	std::cout << "Front of queue is " << que.front() << std::endl;
	
	//pop a element from queue
	que.pop();
	
	//show elements after frist pop
	std::cout<< "Elements in Queue after first pop are " << std::endl;
	printElementsinQueue(que);	
	
	return 0;
}