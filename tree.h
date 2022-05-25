#include<iostream>

using namespace std;

template<typename T>
struct node {
	T key;
	node* left, * right;
	node() : left(nullptr), right(nullptr) {}
};

template<typename T>
class tree {
	node<T>* root;
public:
	tree() :root(nullptr) {}
	void push(const T& val);
	void show();
private:
	void push(node<T>* ptr, const T& val);
	void show(node<T>* ptr);
};

template<typename T>
inline void tree<T>::push(const T& val)
{
	/*node<T>* temp{ root };
	while (temp)
	{
		if (val > *temp)
		{
			if (temp->right == nullptr)
			{
				node<T>* newnode = new node<T>();
				newnode->key = val;
				temp->right = newnode;
				break;
			}
			else
			{
				temp = temp->right;
			}
		}
		else if (val < *temp)
		{
			if (temp->left == nullptr)
			{
				node<T>* newnode = new node<T>();
				newnode->key = val;
				temp->right = newnode;
				break;
			}
			else if (val < *temp)
			{
				temp = temp->left;
			}
		}
	}*/

	/*if (temp->right == nullptr)
	{
		node<T>* newnode = new node<T>();
		newnode->key = val;
		break;
	}*/

	if (root == nullptr)
	{
		root = new node<T>();
		root->key = val;
	}
	else
	{
		push(root, val);
	}
}

template<typename T>
inline void tree<T>::show()
{
	if (root == nullptr)
		std::cout << "data not found" << std::endl;
	tree<T>::show(root);
}

template<typename T>
inline void tree<T>::push(node<T>* ptr, const T& val)
{
	//if (ptr == nullptr)
	//{
	//	node<T>* newnode = new node<T>();
	//	newnode->key = val;
	//	/*ptr = newnode;*/
	//}
	//else
	//{
	//	if (val < ptr->key)
	//	{
	//		push(ptr->left, val);
	//	}
	//	else if (val > ptr->key)
	//	{
	//		push(ptr->right, val);
	//	}
	//}

	if (ptr->key > val)
	{
		if (ptr->left != nullptr)
		{
			push(ptr->left, val);
		}
		else
		{
			ptr->left = new node<T>();
			ptr->left->key = val;
		}
	}
	else
	{
		if (ptr->right != nullptr)
		{
			push(ptr->right, val);
		}
		else
		{
			ptr->right = new node<T>();
			ptr->right->key = val;
		}
	}
}

template<typename T>
inline void tree<T>::show(node<T>* ptr)
{
	if (ptr->left != nullptr)
		show(ptr->left);
	std::cout << ptr->key << " ";
	if (ptr->right != nullptr)
		show(ptr->right);
}
