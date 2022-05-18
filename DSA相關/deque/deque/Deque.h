#ifndef DEQUE_H
#define DEQUE_H

template <typename T,size_t buffersize>
class Deque {

private:
	T ** memory{};
	T* first{};
	T* last{};
	class iterator;
	void expand();
public:
	Deque() = default;
	~Deque();
	Deque(const Deque& copy);
	Deque(Deque&& move);
	void operator=(const Deque& copy);
	void operator=(Deque&& move);
	void push_front(T object);
	void push_back(T object);
	void pop_front();
	void pop_back();
	T front();
	T back();
	iterator begin();
	iterator end();
	T& at(int index);
	T& operator[](int index);
	clear();

};


template <typename T ,size_t buffersize>
class Deque<T>::iterator{
private:
	T ** buffer;
	T* ptr;
public:
	iterator& operator++();
	iterator& opeator++(int);
	iterator& operator--();
	iterator& operator--(int);

};
#endif 
template <typename T, size_t buffersize>
void Deque<T>::push_front(T object) {
	if (memory) {
		memory = new T*[1];
		memory[0] = new T[buffersize];
		first = last = memory[0][0];
	} 
	
	

	
};

template <typename T, size_t buffersize>
void Deque<T>::push_back() {
	if (memory) {
		memory = new T*[1];
		memory[0] = new T[buffersize];
		first = last = memory[0][0];
		return;
	}
	if(back)
};
template <typename T, size_t buffersize>
void Deque<T>::pop_front();
template <typename T, size_t buffersize>
void Deque<T>::pop_back();