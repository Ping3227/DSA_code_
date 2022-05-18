#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDE
#include <utility>
#include <iostream>
template <typename T>
class Stack {
private:
	T * memory{};
	int length{};
	int capacity{};
	void expand_capacity();
public:
	Stack() = default;
	Stack(int len);
	Stack(const Stack& copy);
	Stack(Stack&& move);
	~Stack();
	Stack& operator=(const Stack& copy);
	Stack& operator=(Stack&& move);
	void swap(const Stack& other);
	bool empty();
	int size();
	void push(const T& object);
	void pop();
	T top();
	void print_stack();
};
template <typename T>
Stack<T>::Stack(int len) {
	memory = new T[len];
	capacity = len;
};
template <typename T>
Stack<T>::Stack(const Stack& copy) {
	memory = new T[copy.capacity];
	for (int i{}; i < copy.length; i++) memory[i] = copy.memory[i];
	length = copy.length;
	capacity = copy.capacity;
};

template <typename T>
Stack<T>::Stack(Stack&& move) {
	memory = move.memory;
	move.memory = nullptr;
	length = move.length;
	capacity = move.capacity;
};

template <typename T>
Stack<T>::~Stack() {
	delete memory;
};

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& copy) {
	Stack file{ copy };
	swap(file);
};

template <typename T>
Stack<T>& Stack<T>::operator=(Stack&& move) {
	Stack file{ std::move(move) };
	swap(file);
};

template <typename T>
void Stack<T>::swap(const Stack& other) {
	std::swap(memory, other.memory);
	std::swap(length, other.length);
	std::swap(capacity, other.capacity);
};
template <typename T>
bool Stack<T>::empty() {
	return length == 0;
};

template <typename T>
int Stack<T>::size() {
	return length;
};

template <typename T>
void Stack<T>::push(const T& object) {
	if (length == capacity) expand_capacity();
	memory[length] = object;
	length++;
};
template <typename T>
void Stack<T>::expand_capacity() {
	T * new_memory = new T[capacity + 5];
	for (int i{}; i < length; i++) new_memory[i] = memory[i];
	delete memory;
	memory = new_memory;
};


template <typename T>
void Stack<T>::pop() {
	if (!empty())length--;
};

template <typename T>
T Stack<T>::top() {
	return memory[length - 1];
};

template <typename T> //not good fun in stack
void Stack<T>::print_stack() {
	for (int i{}; i < length; i++) std::cout << memory[i];
	std::cout << std::endl;
};
#endif
