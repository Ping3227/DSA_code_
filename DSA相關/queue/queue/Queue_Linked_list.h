#ifndef QUEUE_LINKED_LIST
#define QUEUE_LINKED_LIST
#include <utility>
#include <iostream>
template <typename T>
class Queue{
private:
	class node {
	public:
		node * next;
		T data;
		node(T Data);
	};
	node * first;
	node * rear;
	int siz{};

public:
	Queue() = default;
	~Queue();
	Queue(const Queue& copy);
	Queue(Queue&& move);
	Queue& operator=(const Queue& copy);
	Queue& operator=(Queue&& move) noexcept;
	void swap(const Queue& copy) noexcept;
	void push(T object);
	void pop();
	T front();
	T back();
	bool empty();
	int size();
	void clear();
	void print_queue(); 

};

template <typename T>
Queue<T>::node::node(T Data) {
	data = Data;
};


template <typename T>
Queue<T>::~Queue(){
	clear();
};


template <typename T>
Queue<T>::Queue(const Queue& copy) {
	node * itr;
	itr = copy.first;
	while(itr){
		push(itr->data);
		itr=itr->next;
	}


};

template <typename T>
Queue<T>::Queue(Queue&& move) {
	first = move.first;
	move.first = nullptr;
	rear = move.rear;

};

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& copy) {
	Queue file{ copy };
	swap(file);
};

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& move) noexcept {
	Queue file{ move };
	swap(file);
};

template <typename T>
void Queue<T>::swap(const Queue& copy) noexcept {
	std::swap(first, copy.first);
	std::swap(rear, copy.rear);
	
};

template <typename T>
void Queue<T>::push(T object) {
	siz++;
	if (first == nullptr) {
		first = rear = new node{object};
		return;
	}
	rear->next =new node{object};
	rear = rear->next;
	
};

template <typename T>
void Queue<T>::pop() {
	if (first == nullptr) return;
	node * tmp = first;
	first = first->next;
	delete tmp;
	siz--;
	if (first == nullptr) rear = nullptr;
};

template <typename T>
T Queue<T>::front() {
	return first->data;
};

template <typename T>
T  Queue<T>::back() {
	return rear->data;
};

template <typename T>
bool Queue<T>::empty() {
	return first == nullptr;
};

template <typename T>
int Queue<T>::size() {
	return siz;
};

template <typename T>
void Queue<T>::clear() {
	while(!empty())pop();
};

template <typename T>
void Queue<T>::print_queue() {
	if (empty()) return;
	node * itr = first;
	while (itr) {
		std::cout << itr->data;
		itr = itr->next;
	}
	std::cout << std::endl;
};


#endif