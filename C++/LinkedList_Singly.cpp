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
	push(v)   				: push element on head of linked list (similar to stack)
	append(v)				: append element on tail of linked list (similar to queue)
	pop()					: pop element on top/head of linked list
	remove(i)				: remove element from given index
	insertonIndex(i)		: insert element on given index
	getNthNode(n)			: get data on nth node
	size()					: get number of elements on linked list
	printAllElements()		: print all the elements on linked list
	search(v)				: search for value v in linked list returns true if found else returns false
	removeDuplicates()		: removes duplicate data elements on linked list
	swap()					: swaps two nodes
	segregateOddEven()		: Segregate even and odd nodes in a LinkedList keeping the order of even and odd number same.
	reverse					: reverse all the nodes in the linkedlist
	
	Note: if you add any more function remember to check the tail pointer is correct or not.
*/
#include <iostream>
#include <unordered_set>
#include <assert.h>
#include <stack>

class Node {
public:
	int data;
	Node* next;
	Node() {

	}
	Node(int value) {
		data = value;
		next = NULL;
	}
};

class SinglyLinkedList {
public:
	Node* head;
	Node* tail;
	int list_size;

	SinglyLinkedList() {
		head = NULL;
		tail = NULL;
		list_size = 0;
	}

	void append(int value) {                 //FIFO
		Node* node = new Node(value);
		if (head == NULL) {
			head = node;
			tail = node;
			list_size = 1;
			return;
		}
		tail->next = node;
		tail = node;
		list_size++;
	}
	void push(int value) {                 //LIFO
		Node* node = new Node(value);
		if (head == NULL) {
			head = node;
			tail = node;
			list_size = 1;
			return;
		}
		node->next = head;
		head = node;
		list_size++;
	}

	void insertonIndex(int index, int value) {
		Node* node = new Node(value);
		int count = 0;
		Node* list = head;
		if (index == 0) {
			push(value);
			return;
		}
		while (list != NULL) {
			if (count == index - 1) {
				node->next = list->next;
				list->next = node;
				list_size++;
				return;
			}
			list = list->next;
			count++;
		}
		std::cout << "Index out of range for insertion " << std::endl;
		assert(0);
	}

	void printAllElements() {
		Node* list = head;
		while (list != NULL) {
			std::cout << list->data << " ";
			list = list->next;
		}
		std::cout << std::endl;
	}

	int getNthNode(int n) {
		Node* list = head;
		int count = 0;
		while (list != NULL) {
			if (count == n) {
				return list->data;
			}
			list = list->next;
			count++;
		}
		std::cout << "Index out of range!!" << std::endl;
		assert(0);
	}

	void pop() {
		if (list_size > 0) {
			head = head->next;
			list_size--;
		}
		else {
			head = NULL;
			tail = NULL;
			list_size = 0;
		}
	}

	void remove(int index) {
		Node* list = head;
		int counter = 0;
		if (index == 0) {
			pop();
			return;
		}
		while (list != NULL) {
			if (counter == index - 1) {
				if (list->next != NULL) {
					list->next = list->next->next;
				}
				else {
					break;
				}
				list_size--;

				return;
			}
			list = list->next;
			counter++;
		}
		std::cout << "Index out of range!!" << std::endl;
		assert(0);
	}

	int size() {
		return list_size;
	}

	bool search(int value) {
		Node* list = head;
		while (list != NULL) {
			if (list->data == value) {
				return true;
			}
			list = list->next;
		}
		return false;
	}

	void removeDuplicates() {
		std::unordered_set<int> unique_set; // using hash table
		Node* list = head;
		Node* prev = NULL;
		while (list != NULL) {
			if (unique_set.find(list->data) == unique_set.end()) {
				unique_set.insert(list->data);
				prev = list;
				list = list->next;
			}
			else {
				prev->next = list->next;
				list = list->next;
				list_size--;
			}
		}
		tail = prev;
	}

	void swap(int x, int y) {
		if (x == y) {
			return;
		}
		Node* prevX = NULL, * currX = head;
		Node* prevY = NULL, * currY = head;
		while (currX != NULL && currX->data != x) {
			prevX = currX;
			currX = currX->next;
		}
		while (currY != NULL && currY->data != y) {
			prevY = currY;
			currY = currY->next;
		}
		//condition
		// if x or y is not present
		if (currX == NULL || currY == NULL) {
			return;
		}
		// x is first node i.e prevX = NULL
		if (prevX == NULL) {
			head = currY;
		}
		else {
			prevX->next = currY;
		}

		// y is first node i.e. prevY == NULL
		if (prevY == NULL) {
			head = currX;
		}
		else {
			prevY->next = currX;
		}

		Node* temp = currY->next;
		currY->next = currX->next;
		currX->next = temp;
	}

	void segregateOddEven_usingStack() { // using stack
		Node* list = head;
		Node* prev = NULL;
		std::stack<int> stack;
		//extracting even numbers from linkedlist first
		while (list != NULL) {
			if (list->data % 2 == 0) {
				stack.push(list->data);
				//maintain the pointers
				if (prev != NULL)
					prev->next = list->next;
				list = list->next;
			}
			else {
				prev = list;
				list = list->next;
			}
		}

		//Appending back the even numbers into the linkedlist
		while (!stack.empty()) {
			push(stack.top());
			stack.pop();
		}
	}
	void segregateOddEven() { // moving the odd numbers to tail
		Node* list = head;
		Node* prev = NULL;
		int counter = 0;
		//Node* tail = head;
		//extracting even numbers from linkedlist first
		while (list != NULL && counter < list_size) {
			if (list->data % 2 != 0) {
				tail->next = list;
				if (prev != NULL)
					prev->next = list->next;
				list = list->next;
				tail = tail->next;
				tail->next = NULL;
			}
			else {
				prev = list;
				list = list->next;
			}
			counter++;
		}
	}

	void reverse() {
		Node* prev = NULL, *curr=head;
		while (curr != NULL) {
			Node* nextnode = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextnode;
		}
		tail = head;
		head = prev;
	}

};

int main() {
	SinglyLinkedList linkedlist1;  //This is queue
	linkedlist1.append(1);
	linkedlist1.append(2);
	linkedlist1.append(3);
	linkedlist1.append(4);
	linkedlist1.append(5);
	linkedlist1.append(6);

	SinglyLinkedList linkedlist2;  //This is stack
	linkedlist2.push(11);
	linkedlist2.push(12);
	linkedlist2.push(13);
	linkedlist2.push(14);
	linkedlist2.push(15);
	linkedlist2.push(16);

	//print all the elements in linked list
	std::cout << "Elements in Linked List 1 are " << std::endl;
	linkedlist1.printAllElements();

	//print all the elements in linked list
	std::cout << "Elements in Linked List 2 are " << std::endl;
	linkedlist2.printAllElements();

	std::cout << "The 3rd index in linked list 1 is : " << linkedlist1.getNthNode(3) << std::endl;
	std::cout << "The 3rd index in linked list 2 is : " << linkedlist2.getNthNode(3) << std::endl;

	linkedlist2.insertonIndex(3, 8);
	std::cout << std::endl << "Inserting 8 on index 3 on linked list 2 " << std::endl;

	std::cout << std::endl << "Elements in Linked List 2 are " << std::endl;
	linkedlist2.printAllElements();

	std::cout << "The 3rd index in linked list 2 is : " << linkedlist2.getNthNode(3) << std::endl;

	std::cout << "linked list 1 after pop operation" << std::endl;
	linkedlist1.pop();
	linkedlist1.printAllElements();

	std::cout << "\nSize of linkedlist2 is " << linkedlist2.size() << std::endl;
	std::cout << "linkedlist2 after deleting element on 2nd index" << std::endl;
	linkedlist2.remove(2);
	linkedlist2.printAllElements();

	SinglyLinkedList linkedlist3;
	linkedlist3.push(1);
	linkedlist3.push(3);
	linkedlist3.push(4);
	linkedlist3.push(6);
	linkedlist3.push(1);
	linkedlist3.push(6);
	linkedlist3.push(1);
	linkedlist3.push(1);
	linkedlist3.push(4);
	linkedlist3.push(3);
	linkedlist3.push(5);
	linkedlist3.push(5);
	linkedlist3.push(1);
	linkedlist3.push(5);
	linkedlist3.push(24);
	linkedlist3.push(33);
	linkedlist3.push(16);
	linkedlist3.push(22);
	linkedlist3.push(91);
	linkedlist3.push(25);
	linkedlist3.push(34);

	std::cout << "\nSize of linkedlist3 is " << linkedlist3.size() << std::endl;

	std::cout << "Elements in Linked List 3 are " << std::endl;
	linkedlist3.printAllElements();

	std::cout << "Removing Duplicate Elements in Linked List 3... " << std::endl;
	linkedlist3.removeDuplicates();
	linkedlist3.printAllElements();

	std::cout << "Swapping position of 3 and 5 in linkedlist3" << std::endl;
	linkedlist3.swap(3, 5);
	linkedlist3.printAllElements();

	std::cout << "Segregating Even and odd numbers in linkedlist3" << std::endl;
	linkedlist3.segregateOddEven();
	linkedlist3.printAllElements();

	std::cout << "Reversing linkedlist3" << std::endl;
	linkedlist3.reverse();
	linkedlist3.printAllElements();
	return 0;
}