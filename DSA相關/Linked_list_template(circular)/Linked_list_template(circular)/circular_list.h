
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <utility>

template <typename T>
class Linked_list {
private:

	//node here
	class node {
	public:
		node * next{};
		node * previous{};
		T data;
		node(T Data, node* Next,node * Pre);
	};
	
	node * first{};

public:
	Linked_list() = default;
	~Linked_list();
	Linked_list(const Linked_list& copy);
	Linked_list(Linked_list&& move) noexcept;
	Linked_list& operator=(const Linked_list& copy);
	Linked_list& operator=(Linked_list&& move) noexcept;
	void swap(Linked_list& swapped) noexcept;
	void push(T object);
	void pop();
	void rotate();
	void print_list();
	void clear();
	void reverse();
	bool empty();
	class iterator;

};

template <typename T>
Linked_list<T>::node::node(T Data, node* Next, node * Pre) {
	data = Data;
	next = Next;
	previous = Pre;
};

template <typename T>
Linked_list<T>::~Linked_list() {
	clear();
};

template<typename T>
Linked_list<T>::Linked_list(const Linked_list& copy) {
	node * tmp = copy.first;
	while (tmp != copy.first)
	{
		push_back(tmp->data);
		tmp = tmp->next;
	}
};

template<typename T>
Linked_list<T>::Linked_list(Linked_list&& move)noexcept {
	first = move.first;
	move.first = nullptr;
	
};

template <typename T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list& copy) {
	Linked_list newlist{ copy };
	swap(newlist);
	return *this;
};

template <typename T>
Linked_list<T>& Linked_list<T>::operator=(Linked_list&& move) noexcept {
	Linked_list newlist{ std::move(move) };
	swap(newlist);
	return *this;
};

template <typename T>
void Linked_list<T>::swap(Linked_list& swapped) noexcept {
	std::swap(swapped.first);
};

template <typename T>
void Linked_list<T>::push(T object) {
	if (first == nullptr) {
		first = new node{ object ,nullptr ,nullptr };
		first->previous = first->next = first;
		return;
	}

	first->previous->next = new node{ object ,first ,first->previous};
	first->previous = first->previous->next;

	/*first->previous = new node{ object ,first ,first->previous };
	first->previous->previous->next = first->previous;*/
	//same code 
};


template<typename T>
void Linked_list<T>::pop() {
	if (first == nullptr )return;
	if (first->next == first) {
		delete first;
		first = nullptr;
		return;
	}

	first->previous = first->previous->previous ;
	delete first->previous->next;
	first->previous->next = first;
	
};
template <typename T>
void Linked_list<T>::rotate() {
	if (first == nullptr)return;
	first = first->next;
};

template <typename T>
void Linked_list<T>::print_list() {
	
	std::cout << "print list called" << std::endl;
	if (first == nullptr) return;
	node *iter{};
	iter = first;
	while (iter->next != first) {
		std::cout << iter->data;
		iter = iter->next;
	}
	std::cout << iter->data << std::endl;
};

template <typename T>
void Linked_list<T>::clear() {
	if (first == nullptr) return;
	node *iter= first;
	while (iter->next != first) {
		iter = iter->next;
		delete iter->previous;
	}
	delete iter;
	first = nullptr;
};

template <typename T>
void Linked_list<T>::reverse() {
	if (first == nullptr||first->next==first) return;
	node *iter = first;
	while (iter->next != first) {
		std::swap(iter->next, iter->previous);
		iter = iter->previous;
	}
	std::swap(iter->next, iter->previous);
};

template <typename T>
bool Linked_list<T>::empty() {
	return first == nullptr;
};

//iterator defination here 
template <typename T>
class Linked_list<T>::iterator {
	friend Linked_list;
private:
	node * itr{};
public:
	iterator(node* ptr);
	iterator& operator++();
	iterator& operator++(int);
	iterator& operator--();
	iterator& operator--(int);

	bool operator==(const iterator&);
	bool operator!=(const iterator&);
	bool operator>(const iterator&);
	bool operator>=(const iterator&);
	bool operator<(const iterator&);
	bool operator<=(const iterator&);

	iterator& operator+(const int&index);
	iterator& operator-(const int& index);
	T& operator*();
};
template <typename T>
Linked_list<T>::iterator::iterator(node* ptr) {
	itr = ptr;
};
template <typename T>
typename Linked_list<T>::iterator& Linked_list<T>::iterator::operator++() {
	if (itr->next != nullptr) {
		itr = itr->next;
	}
	return itr;
};

template <typename T>
typename Linked_list<T>::iterator& Linked_list<T>::iterator::operator++(int) {
	iterator copy{ itr };
	if (itr->next != nullptr) {
		itr = itr->next;
	}
	return copy;
}; 

template <typename T>
typename Linked_list<T>::iterator& Linked_list<T>::iterator::operator--() {
	if (itr->previous != nullptr) {
		itr = itr->previous;
	}
	return itr;
};

template <typename T>
typename Linked_list<T>::iterator& Linked_list<T>::iterator::operator--(int) {
	iterator copy{ itr };
	if (itr->previous != nullptr) {
		itr = itr->previous;
	}
	return copy;
};

//copare opertor here 
template <typename T>
bool Linked_list<T>::iterator::operator==(const iterator& compare) {
	return itr == compare.itr;
};

template <typename T>
bool Linked_list<T>::iterator::operator!=(const iterator& compare) {
	return itr != compare.itr;
};

template <typename T>
bool Linked_list<T>::iterator::operator>(const iterator& compare) {
	return itr > compare.itr;
};

template <typename T>
bool Linked_list<T>::iterator::operator>=(const iterator& compare) {
	return itr >= compare.itr;
};

template <typename T>
bool Linked_list<T>::iterator::operator<(const iterator& compare) {
	return itr < compare.itr;
};

template <typename T>
bool Linked_list<T>::iterator::operator<=(const iterator& compare) {
	return itr <= compare.itr;
};

template <typename T>
typename Linked_list<T>::iterator& Linked_list<T>::iterator::operator+(const int& index) {
	iterator copy{ itr };
	for (int i{}; i<index; copy++) {
		if (copy.itr->next == nullptr) break;
	}
	return copy;
};

template <typename T>
typename Linked_list<T>::iterator& Linked_list<T>::iterator::operator-(const int& index) {
	iterator copy{ itr };
	for (int i{}; i < index; copy--) {
		if (copy.itr->previous == nullptr) break;
	}
	return copy;
};

template <typename T>
T& Linked_list<T>::iterator::operator*() {
	return itr->data;
};
#endif