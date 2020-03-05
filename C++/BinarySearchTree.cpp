//Binary Search Tree Data Structure
//Arpan Man Sainju
//03/04/2020
/*
Description:
	- Unlike Arrays, Linked Lists, Stack and queues, which are
	linear data structures, trees are hierarchical data structures.
	
	- The topmost node is call root of the tree. 
	- The elements that are directly under an element are called its children.
	- The element directly above something is called its parent.
	
	A tree whose elements have at most 2 children is called a
	binary tree. Since each element in a binary tree can have 
	only 2 children, we typically name them the left and right
	child.
	
	A binary tree node contains following parts.
	1. Data
	2. Pointer to left child
	3. Pointer to right child
	
	Advantages of using Tree:
		- One reason to use tree might be because we want to store
		  information that naturally forms a hierarchy. For example, 
		  the file system on a computer.
		- Trees (with some ordering) provide moderate access/search
		  (quicker than linkedlist and slower than arrays).
		- Trees provide moderate insertion/deletion (quicker than 
		  Arrays and slower than unordered linkedlist)
		- Like Linked lists and unlike arrays, trees don't have an upper 
		  limit on number of nodes as nodes are linked using pointers.
	
	Main Applications of trees include:
		1. Manipulate hierarchical data
		2. Make information easy to search 
		3. Manipuate sorted lists of data 
		4. Router algorithms 
		
	Properties of binary tree are:
		1. The maximum number of nodes at level l of a binary tree is 2^(l-1)
		2. Maximum number of nodes in a binary tree of height h is 2^(h-1)
		3. In a binary tree with N nodes, minimum possible height or minimum 
		   number of level is log(N+1) [Node: log is of base 2]
		4. A binary tree with L leaves has at least log(L+1) levels.
		5. In binary tree where every node has 0 or 2 children, number of leaf nodes is
		   always one more than nodes with two children. 
		   
	Properties of binary Search Tree:
		1. The left subtree of a node contains only nodes with keys lesser than the node's key.
		2. The right subtree of a node contains only nodes with keys greater than the node's key. 
		3. The left and right subtree each much also be a binary search tree. 
		There mush be no duplicate nodes. 
		
	Traversal:
	Inorder: Left Root Right  (sorted order)
	Preorder: Root Left Right
	Postorder: Left Right Root
	Levelorder: level wise
		
		
		
	Class BinarySearchTree
	Functions:
	insert(v)
	search(v)
	delete(v)
	
		
*/
#include <iostream>
class Node{
	public:
		int data;
		Node* left;
		Node* right;
	Node(){
		left = NULL;
		right = NULL;
	}
	
	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree{
	public:
		Node* root;
		
	BinarySearchTree(){
		root = NULL;
	}
	
	void insert(int value){
		std::cout<<"Inserting "<<value<<"..."<<std::endl;
		root = recursiveInsert(root,value);
	}
	
	Node* recursiveInsert(Node* current, int value){
		if(current==NULL){
			Node* node = new Node(value);
			return node;
		}
		if(value > current->data){
			current->right = recursiveInsert(current->right,value);
		}
		else if (value < current->data){
			current->left = recursiveInsert(current->left,value);
		}
		
		return current;
	}
	
	//inorder traversal of BST always results in sorted output
	void inorder(){  // left root right
		Node* current = root;
		InorderHelper(current);
		std::cout<<std::endl;
	}
	
		
	void preorder(){  // root left right
		Node* current = root;
		PreorderHelper(current);
		std::cout<<std::endl;
	}
	
	void postorder(){  //left right root
		Node* current = root;
		PostorderHelper(current);
		std::cout<<std::endl;
	}
	
	void levelorder(){
		//TODO
	}
	
	bool search(int value){
		Node* current = SearchHelper(root,value);
		if(current==NULL){
			return false;
		}
		return true;		
	}
	
	int getMinimum(){
		Node* current = root;
		if(root==NULL){
			std::cout<<"No any element on tree..."<<std::endl;
			assert(0);
		}
		while(current!=NULL&& current->left!=NULL){
			current = current->left;
		}
		return current->data;
	}
	Node* getMinimumNode(Node* current){
		while(current!=NULL&& current->left!=NULL){
			current = current->left;
		}
		return current->data;
	}
	
	bool delete(int value){
		//TODO
		//case 1: delete leaf node (no child)
		
		//case 2: delete node with one child
		
		//case 3: delete node with two child
		
	}
	
	//helper functions for recursion
	void PreorderHelper(Node* current){ //root left right
		if(current!=NULL){
			std::cout << current->data << " ";
			PreorderHelper(current->left);
			PreorderHelper(current->right);
		}
	}
	void InorderHelper(Node* current){ // left root right
		if(current!=NULL){
			InorderHelper(current->left);
			std::cout << current->data << " ";
			InorderHelper(current->right);
		}
	}
	void PostorderHelper(Node* current){ // left right root
		if(current!=NULL){
			PostorderHelper(current->left);
			PostorderHelper(current->right);
			std::cout << current->data << " ";
		}
	}
	
	Node* SearchHelper(Node* current, int value){
		if(current==NULL || current->data == value){
			return current;
		}
		else if(value < current->data){
			return SearchHelper(current->left, value);
		}
		
		return SearchHelper(current->right,value);
	}
	
	
};

int main(){
	BinarySearchTree bst;
	bst.insert(50);
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(70);
	bst.insert(60);
	bst.insert(80);
	
	std::cout<<"Inorder Traversal: ";
	bst.inorder();
	std::cout<<"Preorder Traversal: ";
	bst.preorder();
	std::cout<<"Postorder Traversal: ";
	bst.postorder();
	
	std::cout<<"Searching 40.. "<<std::endl;
	bst.search(40) ? std::cout<<"40 is in the tree.."<<std::endl : std::cout<<"40 is not present in the tree.."<<std::endl;
	
	std::cout<<"Searching 20.. "<<std::endl;
	bst.search(20) ? std::cout<<"20 is in the tree.."<<std::endl : std::cout<<"20 is not present in the tree.."<<std::endl;
	
	std::cout<<"Searching 30.. "<<std::endl;
	bst.search(30) ? std::cout<<"30 is in the tree.."<<std::endl : std::cout<<"30 is not present in the tree.."<<std::endl;
	std::cout<<"Searching 70.. "<<std::endl;
	bst.search(70) ? std::cout<<"70 is in the tree.."<<std::endl : std::cout<<"70 is not present in the tree.."<<std::endl;

	std::cout<<"Searching 90.. "<<std::endl;
	bst.search(90) ? std::cout<<"90 is in the tree.."<<std::endl : std::cout<<"90 is not present in the tree.."<<std::endl;

	return 0;
}