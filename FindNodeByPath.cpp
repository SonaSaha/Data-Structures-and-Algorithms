#include "pch.h"
#include <iostream>
#include <string>

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
void In_order_Traversal(const BTNode<T>* root)
{

	if (root == nullptr)
	{
		return;
	}
	In_order_Traversal(root->left);
	std::cout << root->data << " ";
	In_order_Traversal(root->right);
}
template <class T>
BTNode<T>* FindNodeByPath(BTNode<T>* root, const std::string& path)
{
	if (root == nullptr)
		return nullptr;
	if (path.empty())
		return root;
	if (path.size() == 1)
	{
		if (path == "l")
		{
			if (root->left)
				return root->left;
			else return nullptr;
		}
		if (path == "r")
		{
			if (root->right)
				return root->right;
			else nullptr;
		}
	}
	if (*path.begin() == 'l')
		return FindNodeByPath(root->left, path.substr(1, path.size() - 1));
	else if (*path.begin() == 'r')
		return FindNodeByPath(root->right, path.substr(1, path.size() - 1));
}

int main()
{
	auto a = build_sample_tree();
	In_order_Traversal(a);
	std::cout << "\n";
	auto node = FindNodeByPath(a, "rrr");
	std::cout << "path:rrr " << node->data;

}