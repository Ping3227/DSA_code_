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
		node(T Data, node* Next, node * Pre);
	};

	node * first{};
	node * last{};

public:
	Linked_list() = default;
	~Linked_list();
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
	last = move.last;
	move.last = nullptr;
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
	std::swap(swapped.last);
};

template <typename T>
void Linked_list<T>::push_front(T object) {
	if (first == nullptr) {
		first = last = new node{ object ,nullptr ,nullptr };
		return;
	}
	node* tmp;
	tmp = first;
	first = new node{ object ,tmp ,nullptr };
	tmp->previous = first;
};

template <typename T>
void Linked_list<T>::push_back(T object) {
	if (first == nullptr) {
		first = last = new node{ object ,nullptr ,nullptr };
		return;
	}
	node* tmp;
	tmp = last;
	last = new node{ object  ,nullptr,tmp };
	tmp->next = last;
};

template<typename T>
void Linked_list<T>::pop_front() {
	if (first == nullptr)return;
	if (first->next == nullptr) {
		delete first;
		first = nullptr;
		last = nullptr;
		return;
	}
	first = first->next;// ddddd
	delete first->previous;
	first->previous = nullptr;

};

template <typename T>
void Linked_list<T>::pop_back() {
	if (last == nullptr)return;
	if (last->previous == nullptr) {
		delete last;
		first = nullptr;
		last = nullptr;
		return;
	}
	last = last->previous;
	delete last->next;
	last->next = nullptr;
};

template <typename T>
void Linked_list<T>::print_list() {

	std::cout << "print list called" << std::endl;
	if (first == nullptr)return;
	node *iter{};
	iter = first;
	while (iter->next != nullptr) {
		std::cout << iter->data;
		iter = iter->next;
	}
	std::cout << iter->data << std::endl;
};

template <typename T>
void Linked_list<T>::clear() {
	if (first == nullptr)return;
	node *iter = first;
	first = nullptr;
	while (iter->next != nullptr) {
		iter = iter->next;
		delete iter->previous;
	}
	delete last;
	last = nullptr;
};

template <typename T>
void Linked_list<T>::reverse() {
	if (first == nullptr) return;
	node *iter = first;
	while (iter->next != nullptr) {
		std::swap(iter->next, iter->previous);
		iter = iter->previous;
	}
	std::swap(iter->next, iter->previous);
	std::swap(last, first);
};

template <typename T>
bool Linked_list<T>::empty() {
	return first == nullptr;
};
#endif