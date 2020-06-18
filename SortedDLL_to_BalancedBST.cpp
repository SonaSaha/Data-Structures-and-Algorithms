#include "pch.h"
#include <iostream>
//In-place conversion of sorted DLL to Balanced BST
// The idea is to insert nodes in BST in the same order as the appear in Doubly Linked List,
//so that the tree can be constructed in O(n) time complexity.
//We first count the number of nodes in the given Linked List
//After counting nodes, we take left n/2 nodes and recursively construct the left subtree.
//After left subtree is constructed, we assign middle node to root and link the left subtree with root. 
//The  same do for the right subtree

//Double linked list node that will also be used as a tree node
template <class T>
struct Node
{
	Node(const T& value = new T(), Node* left = nullptr, Node* right = nullptr) :left_(left), value_(value), right_(right) {}
	T value_;
	Node<T>* left_;
	Node<T>* right_;
};
//adds an element at the end of the list
template <class T>
void push_back(Node<T>** head, T value)
{
	Node<T>* newNode = new Node<T>(value);
	if (*head == nullptr)
	{
		*head = newNode;
		return;
	}
	Node<T>* last = *head;
	while (last->right_ != nullptr)
		last = last->right_;
	last->right_ = newNode;
	newNode->left_ = last;
	return;
}
//displays current list's nodes values
template <class T>
void display(Node<T>* head)
{
	Node<T>* cur = head;
	while (cur != nullptr)
	{
		std::cout << cur->value_ << " ";
		cur = cur->right_;
	}
}
//counts the nodes in the given list and return the number of nodes
template <class T>
int countsNode(Node<T>* head)
{
	Node<T>* cur = head;
	int n = 0;
	while (cur != nullptr)
	{
		++n;
		cur = cur->right_;
	}
	return n;
}
//constructor for tree
template <class T>
Node<T>* SortedListToBSTRecursive(Node<T>** head, int n)
{
	//base case
	if (n <= 0)
		return nullptr;
	//recursively construct left subtree
	Node<T>* left = SortedListToBSTRecursive(head, n / 2);
	//whet the last recursive call will return head will refer to middle node 
	//make middle node as root of BST
	//when the last recursive call will return the root at that time would point to the first elemet in the list
	Node<T>* root = *head;
	root->left_ = left;
	//takes next element in the list 
	*head = (*head)->right_;
	//the same do for the right subtree
	root->right_ = SortedListToBSTRecursive(head, n - n / 2 - 1);
	return root;
}
//counts nodes in the list and constructs tree
template <class T>
Node<T>* SortedDLLtoBalancedBST(Node<T>* head)
{
	int n = countsNode(head);
	return SortedListToBSTRecursive(&head, n);
}
//preorder tree traversal
template <class T>
void preorderTraversal(Node<T>* root)
{
	if (root)
	{
		std::cout << root->value_ << " ";
		preorderTraversal(root->left_);
		preorderTraversal(root->right_);
	}
}
int main()
{
	//here we construct list 
	Node<int>* list = new Node<int>(1); 
	push_back(&list, 2);
	push_back(&list, 5);
	push_back(&list, 7);
	push_back(&list, 12);
	push_back(&list, 15);
	push_back(&list, 20);
	std::cout << "list\n";
	display(list);
	std::cout << "\ntree:\n";
	//we build the tree and take the root
	Node<int>* tree = SortedDLLtoBalancedBST(list);
	preorderTraversal(tree);
}