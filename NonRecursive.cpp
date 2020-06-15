#include "pch.h"
#include <iostream>
#include <stack>
#include <queue>

template <class T>
struct BTNode
{
	BTNode(const T& data = new T(), BTNode* left = nullptr, BTNode* right = nullptr) :
		data(data),
		left(left),
		right(right)
	{

	}
	T data;
	BTNode<T>* left;
	BTNode<T>* right;
};

BTNode<int>* build_sample_tree()
{
	BTNode<int>* root = new BTNode<int>(2);
	BTNode<int>* n1 = new BTNode<int>(1);
	BTNode<int>* n2 = new BTNode<int>(3);
	BTNode<int>* n3 = new BTNode<int>(4);
	BTNode<int>* n4 = new BTNode<int>(6);
	root->left = n1;
	root->right = n2;
	n2->right = n3;
	n3->right = n4;
	return root;
}
template <class T>
int CountNodesNonRecursive(const BTNode<T>* root)
{
	int count = 0;
	std::stack<BTNode<T>*> s;
	BTNode<T>* cur_root = const_cast<BTNode<T>*>(root);
	while (cur_root || !s.empty())
	{
		while (cur_root)
		{
			s.push(cur_root);
			cur_root = cur_root->left;
		}
		cur_root = s.top();
		s.pop();
		++count;
		cur_root = cur_root->right;
	}
	return count;
}
template <class T>
int Height(const BTNode<T>* root)
{
	int height = 0;
	if (root = nullptr)
		return 0;
	std::queue<BTNode<T>*> q;
	q.push(const_cast<BTNode<T>*>(root));
	while (!q.empty())
	{
		int size = q.size();
		++height;
		while (size > 0)
		{
			BTNode<T>* cur = q.front();
			q.pop();
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
			--size;
		}
	}
	return height;
}
template <class T>
bool FindinBST(const BTNode<T>* root, const T value)
{
	int count = 0;
	std::stack<BTNode<T>*> s;
	BTNode<T>* cur_root = const_cast<BTNode<T>*>(root);
	while (cur_root || !s.empty())
	{
		while (cur_root)
		{
			s.push(cur_root);
			cur_root = cur_root->left;
		}
		cur_root = s.top();
		if (cur_root->data == value)
			return true;
		s.pop();
		++count;
		cur_root = cur_root->right;
	}
	return false;
}

int main()
{
	auto a = build_sample_tree();
	std::cout << CountNodesNonRecursive(a) << "\n";
	//std::cout << Height(a) << "\n";
	if (FindinBST(a, 6))
	{
		std::cout << "Value exists in the tree \n";
	}
	else
	{
		std::cout << "Value does not exist in the tree \n";
	}

}