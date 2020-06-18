#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/lexical_cast.hpp>
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
int CountNodes(const BTNode<T>* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return CountNodes(root->left) + CountNodes(root->right) + 1;
}
template <class T>
int Height(const BTNode<T>* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return std::max(Height(root->left), Height(root->right)) + 1;
}
template <class T>
T Maximum(const BTNode<T>* root)
{
	if (root->right == nullptr)
	{
		return root->data;
	}
	return Maximum(root->right);
}
template <class T>
void Pre_order_Traversal(const BTNode<T>* root)
{
	if (root == nullptr)
	{
		return;
	}
	std::cout << root->data << " ";
	Pre_order_Traversal(root->left);
	Pre_order_Traversal(root->right);
}
template <class T>
void In_order_Traversal(const BTNode<T>* root)
{

	if (root == nullptr)
	{
		return;
	}
	Pre_order_Traversal(root->left);
	std::cout << root->data << " ";
	Pre_order_Traversal(root->right);
}
template <class T>
void Post_order_Traversal(const BTNode<T>* root)
{
	if (root == nullptr)
	{
		return;
	}
	Pre_order_Traversal(root->left);
	Pre_order_Traversal(root->right);
	std::cout << root->data << " ";
}
template <class T>
bool FindInBst(const BTNode<T>* root, const T value)
{
	if (root == nullptr)
	{
		return false;
	}
	if (root->data == value)
	{
		return true;
	}
	if (root->data <= value)
	{
		return FindInBst(root->right, value);
	}
	if (root->data > value)
	{
		return FindInBst(root->left, value);
	}
}

template <class T>
void XmlSerialize(BTNode<T>* root, std::ostream& out = std::cout)
{
	if (root == nullptr)
	{
		return;
	}
	out << "<node data=\"";
	out << root->data;
	out << "\">\n";
	out << "<left>\n";
	XmlSerialize(root->left,out);
	out << "</left>\n";
	out << "<right>\n";
	XmlSerialize(root->right,out);
	out << "</right>\n";
	out << "</node>\n";
}
template <class T>
void WriteTree(const BTNode<T>* root, std::ostream& out = std::cout)
{
	if (root == nullptr)
	{
		out << "()";
		return;
	}

	out << "(";
	out << root->data << ";";
	WriteTree(root->left, out);
	out << ";";
	WriteTree(root->right, out);
	out << ")";
}


template <class T>
bool isBSTHelper(const BTNode<T>* root, bool hasMin = false, const T& min = T(), bool hasMax = false, const T& max = T())
{
	if (root == nullptr)
		return true;

	if (hasMin && root->data <= min || hasMax && root->data > max)
		return false;

	bool isLeftOK = isBSTHelper(root->left, hasMin, min, true, root->data);
	bool isRightOK = isBSTHelper(root->right, true, root->data, hasMax, max);

	return isLeftOK && isRightOK;
}

template <class T>
bool isBST(const BTNode<T>* root)
{
	return isBSTHelper(root, false, T(), false, T());
}


template<class T>
BTNode<T>* ReadTree(std::istream& in = std::cin)
{
	char open_br;
	in >> open_br;

	char x;
	in >> x;
	if (x == ')')
	{
		return nullptr;
	}
	in.putback(x);
	BTNode<T>* root = new BTNode<T>;
	in >> root->data;
	in >> x; //;
	root->left = ReadTree<T>(in);
	in >> x; //;
	root->right = ReadTree<T>(in);
	in >> x; // )
	return root;
}


template <class T>
void XmlSerialize(const BTNode<T>* root, std::ostream& out = std::cout)
{
	if (!root)
		return;

	out << "<node data=\"" << root->data << "\">\n";
	out << "<left>\n";
	XmlSerialize(root->left, out);
	out << "</left>\n";
	out << "<right>\n";
	XmlSerialize(root->right, out);
	out << "</right>\n";
	out << "</node>";
}

/*template<class T>
BTNode<T>* XMLDeserialize(std::istream& in = std::cin)
{
	char x;
	if (!(in >> x)) //<
		return nullptr;

	in >> x; // /
	if (x != 'n')
	{
		return nullptr;
	}
	std::string temp;
	//	in >> temp; //ode
	getline(in, temp, '"'); //ode data="
	std::string value;
	getline(in, value, '"');
	BTNode<T>* root = new BTNode<T>;
	//root->data = boost::lexical_cast<T>(value);
	in >> x; //>
	getline(in, temp, '>'); //<left>
	root->left = XMLDeserialize<T>(in);
	getline(in, temp, '>'); //left>

	getline(in, temp, '>'); //<right>
	root->right = XMLDeserialize<T>(in);
	getline(in, temp, '>'); //right>
	getline(in, temp, '>'); //</node>
	return root;

}
*/
int main()
{
	auto a = build_sample_tree();
	std::cout << Height(a) << "\n";
	std::cout << Maximum(a) << "\n";
	Pre_order_Traversal(a);
	std::cout << "\n";
	In_order_Traversal(a);
	std::cout << "\n";
	Post_order_Traversal(a);
	std::cout << "\n";
	std::cout << FindInBst(a, 6) << "\n";
	std::cout << FindInBst(a, 9) << "\n";
	XmlSerialize(a);
}