#ifndef LINKED_LIST_XOR
#define LINKED_LIST_XOR
#include <iostream>
#include <utility>

template <typename T>
class linked_list_xor {	
private:
	//node here
	class node {
		 
	public:
		node * nxt_and_pre{};
		T data;
		node(T Data);
	};
	node * first{};
	node * last{};
	node * XOR(node *a, node *b);
public:
	linked_list_xor() = default;
	~linked_list_xor();
	linked_list_xor(const linked_list_xor& copy);
	linked_list_xor(linked_list_xor&& move) noexcept;
	linked_list_xor& operator=(const linked_list_xor& copy);
	linked_list_xor& operator=(linked_list_xor&& move) noexcept;
	void swap(linked_list_xor& swapped) noexcept;
	void push_front(T object);
	void push_back(T object);
	void pop_front();
	void pop_back();
	void print_forward();
	void print_back();
	void clear();
	bool empty();
	
};

//node constructor
template <typename T>
linked_list_xor<T>::node::node(T Data) {
	data = Data;
};

//xor function
template <typename T>
typename linked_list_xor<T>::node* linked_list_xor<T>::XOR( node *a, node *b){
	return reinterpret_cast<node*>(reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b));
};

template <typename T>
linked_list_xor<T>::~linked_list_xor() {
	clear();
};

template <typename T>
linked_list_xor<T>::linked_list_xor(const linked_list_xor& copy) {
	node * itrsave;
	node * lastitr = nullptr;
	node * itr = copy.first;
	while (itr) {
		push_back(itr->data);
		itrsave = itr;
		itr = XOR(lastitr, itr->nxt_and_pre);
		lastitr = itrsave;
	}
};

template <typename T>
linked_list_xor<T>::linked_list_xor(linked_list_xor&& move) noexcept {
	first = move.first;
	move.first = nullptr;
	last = move.last;
	move.last = nullptr;
};

template <typename T>
linked_list_xor<T>& linked_list_xor<T>::operator=(const linked_list_xor& copy) {
	linked_list_xor file{copy};
	swap(file);
};

template <typename T>
linked_list_xor<T>& linked_list_xor<T>::operator=(linked_list_xor&& move) noexcept {
	linked_list_xor file{ std::move(move) };
	swap(file);
};

template <typename T>
void linked_list_xor<T>::swap(linked_list_xor& swapped) noexcept {
	std::swap(first, swapped.first);
	std::swap(last, swapped.last);
};

template <typename T>
void  linked_list_xor<T>::push_front(T object) {
	node * newhead = new node(object);
	newhead->nxt_and_pre = XOR(nullptr,first);
	if (first != nullptr) {
		first->nxt_and_pre = XOR (newhead, XOR (nullptr, first->nxt_and_pre) );
		
	}
	first = newhead;
	if (last == nullptr)  last = first;
};


template <typename T>
void  linked_list_xor<T>::push_back(T object) {
	node * newtail = new node(object);
	newtail->nxt_and_pre = XOR(last, nullptr);
	if (last != nullptr) {
		last->nxt_and_pre = XOR(XOR(last->nxt_and_pre, nullptr), newtail);

	}
	last = newtail;
	if (first == nullptr)  first = last;
};

template <typename T>
void linked_list_xor<T>::pop_front() {
	if (first == last) {
		delete first;
		first = last = nullptr;
		return;
	}
	node *next = XOR(nullptr, first->nxt_and_pre);
	next->nxt_and_pre = XOR(nullptr, XOR(first, next->nxt_and_pre));
	delete first;
	first = next;
};

template <typename T>
void linked_list_xor<T>::pop_back() {
	if (last == first) {
		delete last;
		last = first = nullptr;
		return;
	}
	node *prev = XOR(last->nxt_and_pre,nullptr);
	prev->nxt_and_pre = XOR(XOR(prev->nxt_and_pre,last),nullptr);
	delete last;
	last = prev;
};

template <typename T>
void linked_list_xor<T>::print_forward() {
	if (first == nullptr) return;
	node * itrsave;
	node * lastitr = nullptr;
	node * itr = first;
	while(itr) {
		std::cout << itr->data;
		itrsave = itr;
		itr = XOR(lastitr, itr->nxt_and_pre);
		lastitr = itrsave;
	}
	std::cout << std::endl;
};

template <typename T>
void linked_list_xor<T>::print_back() {
	if (last == nullptr) return;
	node * itrsave;
	node * lastitr = nullptr;
	node * itr = last;
	while (itr) {
		std::cout << itr->data;
		itrsave = itr;
		itr = XOR(itr->nxt_and_pre, lastitr);
		lastitr = itrsave;
	}
	std::cout << std::endl;
};

template <typename T>
void linked_list_xor<T>::clear() {
	if (first == nullptr) return;
	node * itrsave;
	node * lastitr = nullptr;
	node * itr = first;
	while (itr) {
		itrsave = itr;
		itr = XOR(lastitr, itr->nxt_and_pre);
		if (lastitr) delete lastitr;
		lastitr = itrsave;
	}
	delete lastitr;
	last = first =nullptr;
};

template <typename T>
bool linked_list_xor<T>::empty() {
	return first == nullptr;
};
#endif // !LINKED_LIST_XOR
