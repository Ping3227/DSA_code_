#ifndef TREE_H
#define TREE_H
#include <queue>
#include <iostream>
template <typename T>
class tree {
private:
	class node;
	std::queue<node*> to_do{};
	node * root{};
	void inorderfunction(node * current);
	void preorderfunction(node * current);
	void postorderfunction(node * current);
	int heightfunction(node * current);
public:

	tree() = default;
	// out put form
	void inorder();
	void preorder();
	void postorder();
	void levelorder();

	node* sucessor(node * current);
	node* precessor(node * current);
	node * leftmost(node * current);
	node * rightmost(node * current);
	void add(T object);
	void remove(T object);
	node * search(T object);
	void clear();
	bool empty();
	bool contains(T object);
	int height();
	T max();
	T min();

};
// node function here 
template <typename T>
class tree<T>::node {
public:
	T data{};
	
	node * left{};
	node * right{};
	node * parent{};
	node(T value);
	node() = default;
};

template <typename T>
tree<T>::node::node(T value) :data{ value } {};


// preorder inorder postorder levelorder above here

//inorder fun
template <typename T>
void tree<T>::inorder() {
	inorderfunction(root);
	std::cout << std::endl;
};

template <typename T>
void tree<T>::inorderfunction(node * current) {
	if (!current) return;
	inorderfunction(current->left);
	std::cout << current->data;
	inorderfunction(current->right);

};

//preorder fun
template <typename T>
void tree<T>::preorder() {
	preorderfunction(root);
	std::cout << std::endl;
};

template <typename T>
void tree<T>::preorderfunction(node * current) {
	if (!current) return;
	std::cout << current->data;
	preorderfunction(current->left);
	preorderfunction(current->right);

};

// postorder fun

template <typename T>
void tree<T>::postorder() {
	postorderfunction(root);
	std::cout << std::endl;
};

template <typename T>
void tree<T>::postorderfunction(node * current) {
	if (!current) return;
	postorderfunction(current->left);
	postorderfunction(current->right);
	std::cout << current->data;
};


template <typename T>
void tree<T>::levelorder() {
	
	if (!root) return;
	std::cout <<root->data;
	if (root->left) to_do.push(root->left);
	if (root->right) to_do.push(root->right);
	while (!to_do.empty()) {
		node * current = to_do.front();
		to_do.pop();
		std::cout << "." << current->data;
		if (current->left) to_do.push(current->left);
		if (current->right) to_do.push(current->right);
	}
	std::cout << std::endl;
};

//success and precess

template <typename T>
typename tree<T>::node* tree<T>::sucessor(node * current) {
	if (current->right) {
		current = current->right;
		return leftmost(current);
	}
	while (current->parent&&current->parent->right == current) {
		current = current->parent;
	}
	current = current->parent;
	return current;

};

template <typename T>
typename tree<T>::node* tree<T>::precessor(node * current) {
	if (current->left) {
		current->left;
		return rightmost(current);
	}
	while (current->parent&&current->parent->left == current) {
		current = current->parent;
	}
	current = current->parent;
	return current;

};

template <typename T>
typename tree<T>::node * tree<T>::leftmost(node * current) {
	while (current->left) {
		current = current->left;
	}
	return current;
};

template <typename T>
typename tree<T>::node * tree<T>::rightmost(node * current) {
	while (current->right) {
		current = current->right;
	}
	return current;
};

template <typename T>
void tree<T>::add(T object) {
	if (!root) {
		root = new node(object);
		return;
	}
	node * aim{};
	node * itr = root;
	while (itr) {
		aim = itr;
		if (itr->data <= object) itr = itr->right;
		else itr = itr->left;
	}
	if (aim->data <= object) {
		aim->right = new node(object);
		aim->right->parent = aim;
	}
	else {
		aim->left = new node(object);
		aim->left->parent = aim;
	}
};
template <typename T>
void tree<T>::remove(T object) {
	node * delete_node = search(object);
	if (!delete_node) return;
	node * current{};
	node * kids{};
	if (!delete_node->left || !delete_node->right) {// double kids or not 
		current = delete_node;
	}
	else {
		current = sucessor(delete_node);
	}

	if (current->left) {
		kids = current->left;
	}
	else kids = current->right;

	if (kids) kids->parent = current->parent;

	if (!current->parent) root = kids;
	else if (current == current->parent->left) current->parent->left = kids;
	else current->parent->right = kids;

	if (current != delete_node) {
		delete_node->data = current->data;
	}
	delete current;
};
template <typename T>
typename tree<T>::node * tree<T>::search(T object) {
	node * itr = root;
	while (itr) {
		if (itr->data == object) return itr;
		else if (itr->data < object) itr = itr->right;
		else itr = itr->left;
	}
	return itr;
};
template <typename T>
void tree<T>::clear() {
	if (!root) return;
	node * itr;
	to_do.push(root);
	while (!to_do.empty()) {
		itr = to_do.front();
		to_do.pop();
		if (itr->left) to_do.push(itr->left);
		if (itr->right) to_do.push(itr->right);
		delete itr;
	}
	root = nullptr;
};

template <typename T>
bool tree<T>::empty() {
	return !root;
};

template <typename T>
bool tree<T>::contains(T object) {
	if (search(object)) return true;
	else return false;
}
template <typename T>
int tree<T>::height() {
	return heightfunction(root);
};
template <typename T>
int tree<T>::heightfunction(node * current) {
	if (current) return 1
		+((heightfunction(current->left) > heightfunction(current->right)) ? heightfunction(current->left) : heightfunction(current->right));
	else return 0;
};

template <typename T>
T tree<T>::max() {
	if (!root) return 0;
	return rightmost(root)->data;
};

template <typename T>
T tree<T>::min() {
	if (!root) return 0;
	return leftmost(root)->data;
};
#endif


