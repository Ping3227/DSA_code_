#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <queue>
#include <iostream>
template <typename T>
class red_black_tree {
private:
	class node; 
	node * NIL{};
	node * root{};
	std::queue<node*> to_do{};
	void inorderfunction(node * current);
	void preorderfunction(node * current);
	void postorderfunction(node * current);
	int heightfunction(node * current);
	// addition
	void leftrotation(node * current);
	void rightrotation(node * current);
	void deletefixed(node * current);
	void addfixed(node * current);
	
public:

	red_black_tree() ;
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

template <typename T>
red_black_tree<T>::red_black_tree() {
	NIL = new node;
	NIL->color = 1;
	root = NIL;
};
// node function here 
template <typename T>
class red_black_tree<T>::node {
public:
	T data{};
	bool color{};
	node * left{};
	node * right{};
	node * parent{};
	node(T value);
	node() = default;
};

template <typename T>
red_black_tree<T>::node::node(T value) :data{ value } {};


// preorder inorder postorder levelorder above here

//inorder fun
template <typename T>
void red_black_tree<T>::inorder() {
	inorderfunction(root);
	std::cout << std::endl;
};

template <typename T>
void red_black_tree<T>::inorderfunction(node * current) {
	if (current==NIL) return;
	inorderfunction(current->left);
	std::cout << current->data;
	inorderfunction(current->right);

};

//preorder fun
template <typename T>
void red_black_tree<T>::preorder() {
	preorderfunction(root);
	std::cout << std::endl;
};

template <typename T>
void red_black_tree<T>::preorderfunction(node * current) {
	if (current==NIL) return;
	std::cout << current->data;
	preorderfunction(current->left);
	preorderfunction(current->right);

};

// postorder fun

template <typename T>
void red_black_tree<T>::postorder() {
	postorderfunction(root);
	std::cout << std::endl;
};

template <typename T>
void red_black_tree<T>::postorderfunction(node * current) {
	if (current==NIL) return;
	postorderfunction(current->left);
	postorderfunction(current->right);
	std::cout << current->data;
};


template <typename T>
void red_black_tree<T>::levelorder() {

	if (root==NIL) return;
	std::cout <<root->data<< (root->color ? "(black)" : "(red)")<< ".";
	if (root->left!=NIL) to_do.push(root->left);
	if (root->right!=NIL) to_do.push(root->right);
	while (!to_do.empty()) {
		node * current = to_do.front();
		to_do.pop();
		std::cout  << current->data<<(current->color?"(black)":"(red)")<<".";
		if (current->left!=NIL) to_do.push(current->left);
		if (current->right!=NIL) to_do.push(current->right);
	}
	std::cout << std::endl;
};

//success and precess

template <typename T>
typename red_black_tree<T>::node* red_black_tree<T>::sucessor(node * current) {
	if (current->right!=NIL) {
		return leftmost(current->right);
	}
	while (current->parent && current== current->parent->right) {
		current = current->parent;
	}
	current = current->parent;
	return current;

};

template <typename T>
typename red_black_tree<T>::node* red_black_tree<T>::precessor(node * current) {
	if (current->left!=NIL) {
		return rightmost(current->left);
	}
	while (current->parent && current == current->parent->left) {
		current = current->parent;
	}
	current = current->parent;
	return current;

};

template <typename T>
typename red_black_tree<T>::node * red_black_tree<T>::leftmost(node * current) {
	while (current->left!=NIL) {
		current = current->left;
	}
	return current;
};

template <typename T>
typename red_black_tree<T>::node * red_black_tree<T>::rightmost(node * current) {
	while (current->right!=NIL) {
		current = current->right;
	}
	return current;
};

template <typename T>
void red_black_tree<T>::add(T object) {
	if (root==NIL) {
		root = new node(object);
		root->color = 1;
		root->left = root->right = NIL;
		return;
	}

	node * aim{};
	node * itr = root;
	while (itr!=NIL) {
		aim = itr;
		if (itr->data <= object) itr = itr->right;
		else itr = itr->left;
	}
	if (aim->data <= object) {
		aim->right = new node(object);
		aim->right->left = aim->right->right = NIL;
		aim->right->color = 0;
		aim->right->parent = aim;
		
		addfixed(aim->right);
	}
	else {
		aim->left = new node(object);
		aim->left->left = aim->left->right = NIL;
		aim->left->color = 0;
		aim->left->parent = aim;
		
		addfixed(aim->left);
	}
	
};


template <typename T>
void red_black_tree<T>::addfixed(node *current) {       //the node that been inserted 
	while (current->parent&&current->parent->color == 0)   // root nil is black: 1
	{
		if (current->parent == current->parent->parent->left) {
			node * uncle = current->parent->parent->right;
			if (uncle->color == 0) {
				current->parent->parent->color = 0;
				current->parent->color = 1;
				uncle->color = 1;
				current = current->parent->parent;
			}
			else {
				if (current == current->parent->right) {
					current = current->parent;
					leftrotation(current);
				}
				current->parent->color = 1;
				current->parent->parent->color = 0;
				rightrotation(current->parent->parent);
			}
		}
		else {
			node * uncle = current->parent->parent->left;
			if (uncle->color == 0) {
				current->parent->parent->color = 0;
				current->parent->color = 1;
				uncle->color = 1;
				current = current->parent->parent;
			}
			else {
				if (current == current->parent->left) {
					current = current->parent;
					rightrotation(current);
				}
				current->parent->color = 1;
				current->parent->parent->color = 0;
				leftrotation(current->parent->parent);
			}
		}
	}
	root->color = 1;
}
template <typename T>
void red_black_tree<T>::remove(T object) {
	node * delete_node = search(object);
	if (delete_node==NIL) return;
	node * current{};
	node * kids{};
	if (delete_node->left ==NIL|| delete_node->right==NIL) {// double kids or not 
		current = delete_node;
	}
	else {
		current = sucessor(delete_node);
	}

	if (current->left==NIL) {
		kids = current->right;
	}
	else kids = current->left;

	kids->parent = current->parent; // for seach sibling 

	if (!current->parent) root = kids;
	else if (current == current->parent->left) current->parent->left = kids;
	else current->parent->right = kids;

	if (current != delete_node) {
		delete_node->data = current->data;
	}
	if (current->color == 1) {
		deletefixed(kids);
	}
	
	delete current;
};

template <typename T>
void red_black_tree<T>::deletefixed(node * current) {
	while (current != root && current->color == 1) {
		if (current == current->parent->left) {
			node *sibling = current->parent->right;
			// Case1:
			if (sibling->color == 0) {
				sibling->color = 1;
				current->parent->color = 0;
				leftrotation(current->parent);
				sibling = current->parent->right;
			}
			//case2:
			if (sibling->left->color == 1 && sibling->right->color == 1) {  // ciling will not be red:0 after case:1 if so it will be delt by case 1:
				sibling->color = 0;
				current = current->parent;
			}
			// Case3 & 4: 
			else {
				// case3: 
				if (sibling->right->color == 1) {
					sibling->left->color = 1;
					sibling->color = 0;
					rightrotation(sibling);
					sibling = current->parent->right;
				}
				// Case 4: 
				sibling->color = current->parent->color;
				current->parent->color = 1;
				sibling->right->color = 1;
				leftrotation(current->parent);
				current = root;
			}
		}
		else {
			node *sibling = current->parent->left;
			if (sibling->color == 0) {
				sibling->color = 1;
				current->parent->color = 0;
				rightrotation(current->parent);
				sibling = current->parent->left;
			}
			if (sibling->left->color == 1 && sibling->right->color == 1) {
				sibling->color = 0;
				current = current->parent;
			}
			else {
				if (sibling->left->color == 1) {
					sibling->right->color = 1;
					sibling->color = 0;
					leftrotation(sibling);
					sibling = current->parent->left;
				}
				sibling->color = current->parent->color;
				current->parent->color = 1;
				sibling->left->color = 1;
				rightrotation(current->parent);
				current = root;
			}
		}
	}
	current->color = 1; //case 0   if current is red:0 or root make it black
}
template <typename T>
typename red_black_tree<T>::node * red_black_tree <T>::search(T object) {
	node * itr = root;
	while (itr!=NIL) {
		if (itr->data == object) return itr;
		else if (itr->data < object) itr = itr->right;
		else itr = itr->left;
	}
	return itr;
};
template <typename T>
void red_black_tree<T>::clear() {
	if (root==NIL) return;
	node * itr;
	to_do.push(root);
	while (!to_do.empty()) {
		itr = to_do.front();
		to_do.pop();
		if (itr->left!=NIL) to_do.push(itr->left);
		if (itr->right!=NIL) to_do.push(itr->right);
		delete itr;
	}
	root = NIL;
};

template <typename T>
bool red_black_tree <T>::empty() {
	return root==NIL;
};

template <typename T>
bool red_black_tree <T>::contains(T object) {
	if (search(object)) return true;
	else return false;
}
template <typename T>
int red_black_tree <T>::height() {
	return heightfunction(root);
};
template <typename T>
int red_black_tree <T>::heightfunction(node * current) {
	if (current!=NIL) return 1
		+ ((heightfunction(current->left) > heightfunction(current->right)) ? heightfunction(current->left) : heightfunction(current->right));
	else return 0;
};

template <typename T>
T red_black_tree <T>::max() {
	if (root==NIL) return 0;
	return rightmost(root)->data;
};

template <typename T>
T red_black_tree <T>::min() {
	if (root==NIL) return 0;
	return leftmost(root)->data;
};

// addition
template <typename T>
void red_black_tree<T>::leftrotation(node * current) {
	node * newcurrent = current->right;
	current->right = newcurrent->left;
	if (current->right!=NIL) current->right->parent = current;

	if (!current->parent ) {
		root = newcurrent;
	}
	else if(current== current->parent->right){
		current->parent->right = newcurrent;
	}
	else{
		current->parent->left = newcurrent;
	}
	newcurrent->parent = current->parent;

	newcurrent->left = current;
	current->parent = newcurrent;
}

template <typename T>
void red_black_tree<T>::rightrotation(node * current) {
	node * newcurrent = current->left;
	current->left = newcurrent->right;
	if (current->left!=NIL) current->left->parent = current;

	if (!current->parent ) {
		root = newcurrent;
	}
	else if (current == current->parent->left) {
		current->parent->left = newcurrent;
	}
	else {
		current->parent->right = newcurrent;
	}
	newcurrent->parent = current->parent;

	newcurrent->right = current;
	current->parent = newcurrent;
}


#endif 
