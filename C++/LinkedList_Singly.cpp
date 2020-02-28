// Singly Linked List 
//Arpan Man Sainju
//02/27/2020
/*Description:
  Linked list is a linear data structure, in which the elements are not stored at contiguous memory locations.
  The elements in linked list are linked using pointers.
  Why Linked List?
	- Dynamic Size: Size of Array is fixed. But some time we don't know the number of elements in advance. 
	- Ease of Insertion/Deletion: Inserting a new elemement in an arry of elements is expensive because of shifting of all the elements to make the room for new element. 
	
  Drawbacks over Arrays
    - Random access is not allowed. We have to access elements sequentially from the first node. 
	- Accessing the elements in an array is fast, while linked list takes linear time.
	- 
	- Extra memory space for pointer is required with each element of the list 
	- Not cache friendly. Since array elements are contigious locations, there is locality of reference which is not true in case of linked list.
	
	Functions:
		push(linkedlist,v)        : push the new element on top of linked list (similar to stack) O(1)
		append(linkedlist,v)      : append the new element to the end of the list (similar to queue) O(1)
		insertAfter(linkedlist,v) : insert a new node after a given node O(1) 
	
*/
#include <iostream>
#include <assert.h>
class Node{
	public:
		int data;
		Node* next;
	Node(){
		
	}
	Node(int value){
		data = value;
		next = NULL;
	}
};

class SinglyLinkedList{
	public:
		Node* head;
		Node* tail;
		
	SinglyLinkedList(){
		head = NULL;
		tail = NULL;
	}
	
	void append(int value){                 //FIFO
		Node* node = new Node(value);
		if (head==NULL){
			head = node;
			tail = node;
			return;
		}
		tail->next = node;
		tail = node;
	}
	void push(int value){                 //LIFO
		Node* node = new Node(value);
		if(head ==NULL){
			head = node;
			tail = node;
			return;
		}
		node->next = head;
		head = node;
	}
	
	void insertonIndex(int index, int value){
		Node* node = new Node(value);
		int count = 0;
		Node* list = head;
		if(index == 0){
			push(value);
			return;
		}
		while(list!=NULL){
			if(count == index-1){
				node->next = list->next;
				list->next = node;
				return;
			}
			list = list->next;
			count++;
		}
		std::cout << "Index out of range for insertion "<<std::endl;
		assert(0);
	}
	
	void printAllElements(){
		Node* list = head;
		while(list!=NULL){
			std::cout<< list->data<<std::endl;
			list = list->next;
		}
	}
	
	int getNthNode(int n){
		Node* list = head;
		int count =0;
		while(list!=NULL){
			if(count==n){
				return list->data;
			}
			list= list->next;
			count++;
		}
		std::cout << "Index out of range!!"<< std::endl;
		assert(0);
		
	}
	
};

int main(){
	SinglyLinkedList linkedlist1;  //This is queue
	linkedlist1.append(1);
	linkedlist1.append(2);
	linkedlist1.append(3);
	linkedlist1.append(4);
	linkedlist1.append(5);
	linkedlist1.append(6);
	
	SinglyLinkedList linkedlist2;  //This is stack
	linkedlist2.push(1);
	linkedlist2.push(2);
	linkedlist2.push(3);
	linkedlist2.push(4);
	linkedlist2.push(5);
	linkedlist2.push(6);

	//print all the elements in linked list
	std::cout << "Elements in Linked List 1 are " << std::endl;
	linkedlist1.printAllElements();
	
	//print all the elements in linked list
	std::cout << "Elements in Linked List 2 are " << std::endl;
	linkedlist2.printAllElements();
	
	std::cout<< "The 3rd index in linked list 1 is : " <<linkedlist1.getNthNode(3) << std::endl;
	std::cout<< "The 3rd index in linked list 2 is : " <<linkedlist2.getNthNode(3) << std::endl;
	
	linkedlist2.insertonIndex(3,8);
	std::cout <<std::endl<<"Inserting 8 on index 3 on linked list 2 "<<std::endl;
	
	std::cout << std::endl<<"Elements in Linked List 2 are " << std::endl;
	linkedlist2.printAllElements();
	
	std::cout<< "The 3rd index in linked list 2 is : " <<linkedlist2.getNthNode(3) << std::endl;
	return 0;
}