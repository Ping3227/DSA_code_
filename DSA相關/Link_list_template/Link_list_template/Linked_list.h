#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <utility>
//forward_type without iterator
template <typename T>
class Linked_list {
private:

	//node here
	class node {
	public:
		node * next{};
		T data;
		node(T Data, node* Next);
	};

	node *first{};

public:
	Linked_list() = default;
	~Linked_list() ;
	Linked_list(const Linked_list& copy);
	Linked_list(Linked_list&& move) noexcept;
	Linked_list& operator=(const Linked_list& copy);
	Linked_list& operator=(Linked_list&& move) noexcept;
	void swap(Linked_list& swapped) noexcept;
	void push_front(T object);
	void push_back(T object);
	void pop_front();
	void pop_back();
	void print_list();
	void clear();
	void reverse();
	bool empty();

};

template <typename T>
Linked_list<T>::node::node(T Data, node* Next) {
	data = Data;
	next = Next;
};

template <typename T>
Linked_list<T>::~Linked_list() {
	clear();
};

template<typename T>
Linked_list<T>::Linked_list(const Linked_list& copy) {
	node * tmp = copy.first;
	while (tmp != nullptr)
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
	Linked_list newlist{copy};
	swap(newlist);
	return *this;
};

template <typename T>
Linked_list<T>& Linked_list<T>::operator=(Linked_list&& move) noexcept {
	Linked_list newlist{std::move(move)};
	swap(newlist);
	return *this;
};

template <typename T>
void Linked_list<T>::swap(Linked_list& swapped) noexcept {
	std::swap(swapped.first);
};

template <typename T>
void Linked_list<T>::push_front(T object) {
	node* tmp;
	tmp = first;
	first = new node{object ,tmp};
};

template <typename T>
void Linked_list<T>::push_back(T object) {
	if (first == nullptr) {
		first = new node{ object,nullptr };
		return;
	}
	node * iter = first;
	while (iter->next != nullptr) {
		iter = iter->next;
	}
	iter->next = new node{ object,nullptr };
};

template<typename T>
void Linked_list<T>::pop_front() {
	node * tmp;
	if (first == nullptr)return;
	tmp = first;
	first = first->next;
	delete tmp;
};

template <typename T>
void Linked_list<T>::pop_back() {
	if (first == nullptr|| first->next == nullptr){
		delete first;
		first = nullptr;
		return;
	}
	node * iter = first;
	while (iter->next->next != nullptr) {
		iter = iter->next;
	}
	delete iter->next;
	iter->next = nullptr;
};

template <typename T>
void Linked_list<T>::print_list() {
	node *iter{};
	std::cout << "print list called" << std::endl;
	if (first == nullptr)return;
	iter = first;
	while (iter->next != nullptr) {
		std::cout << iter->data;
		iter = iter->next;
	}
	std::cout << iter->data <<std::endl;
};

template <typename T>
void Linked_list<T>::clear() {
	if (first == nullptr)return;
	node* deleted = first;
	node* waited = first->next;
	first = nullptr;
	while (deleted->next != nullptr) {
		delete deleted;
		deleted = waited;
		waited = waited->next;
	}
	delete deleted;
};

template <typename T>
void Linked_list<T>::reverse() {
	if (first == nullptr || first->next == nullptr) return;
	node* previous = nullptr;
	node* currrent = first;
	node* preceding = first->next;

	while (preceding != nullptr) {
		currrent->next = previous;
		previous = currrent;
		currrent = preceding;
		preceding = preceding->next;
	}
	currrent->next = previous;
	first = currrent;
};

template <typename T>
bool Linked_list<T>::empty() {
	return first == nullptr;
};
#endif