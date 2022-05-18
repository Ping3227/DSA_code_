#ifndef VECTOR_H
#define VECTOR_H
/**/
#include <utility>
template <typename T>
class Vector {
	private:
		T * memory_ptr{};
		int length{};
		int capacity{};

	public:
		// Iterator here
		class Iterator {
		private:
			T * iter{};
		public:
			Iterator() = default;
			Iterator(T* pointer);
			void operator++();      //  prefix
			void operator++(int);   //postfix

			void operator--();      //prefix  ---->why dont return 
			void operator--(int);  //postfix

			bool operator == (const Iterator& index);
			bool operator != (const Iterator& index);
			bool operator > (const Iterator& index);
			bool operator >= (const Iterator& index);
			bool operator < (const Iterator& index);
			bool operator <= (const Iterator& index);
			Iterator operator+(int);
			Iterator operator-(int);
			int operator-(const Iterator& index);
			void operator=(const Iterator & index);
			T& operator*();
		};

		Vector() = default;         //default constructor
		explicit Vector(int len);   //nomal constructor    explict only in declaration
		Vector(const Vector& copy);     //copy constructor
		Vector(Vector&& move)noexcept; //move constructor
		~Vector();                    //destructor

		Vector& operator=(const Vector& copy);     //copy assignment
		Vector& operator=(Vector&& move)noexcept; //move assignment

		//function 
		void swap(Vector& Swap);
		void push_back(T object);
		void pop_back();
		int size();
		bool empty();
		T front();
		T back();
		T& At(int index);
		const T& At(int index) const;
		void clear();
		void Reserve(int N);
		void Resize(int N);

		//iterator function 
		Iterator begin();
		Iterator end();     //recheck again and down three
		void insert(Iterator index, T object);
		void erase(Iterator index);
		void erase(Iterator index, Iterator index2);
	

		//other operator 
		T& operator[](size_t index);
		const T& operator[](size_t index)const;

		
	};


template <typename T>           //nomal constructor
Vector<T>::Vector(int len) {
	if (len <= 0){
		memory_ptr = nullptr;
	}
	else {
		memory_ptr = new T[len];
		length = len;
		capacity = len;	
	}
};

template <typename T>           //copy constructor
Vector<T>::Vector(const Vector& copy) {
	if (memory_ptr)
		delete[] memory_ptr;
	memory_ptr = new T[copy.capacity];
	length = copy.length;
	capacity = copy.capacity;
	for (int i{}; i < length; i++) {
		(memory_ptr)[i] = (copy.memory_ptr)[i];
	}
};

template <typename T>           //move constructor
Vector<T>::Vector(Vector&& move) noexcept {
	if (memory_ptr)
		delete[] memory_ptr;
	memory_ptr = move.memory_ptr;
	move.memory_ptr = nullptr;
	capacity = move.capacity;
	length = move.length;
};

template <typename T>           //destructor
Vector<T>::~Vector() {
	delete[] memory_ptr;
};

template <typename T>          //copy assignment
Vector<T>& Vector<T>::operator=(const Vector& copy) {
	Vector copyfile{ copy };
	swap(copyfile);
};

template <typename T>         //move assignment
Vector<T>& Vector<T>::operator=(Vector&& move)noexcept {
	Vector copyfile{ std::move(move) };
	swap(copyfile);
};

template <typename T>
void Vector<T>::swap(Vector& Swap) {
	std::swap(length, Swap.length);
	std::swap(memory_ptr, Swap.memory_ptr);
	std::swap(capacity, Swap.capacity);
};

template <typename T>
void Vector<T>::push_back(T object) {
	if (length == capacity) {
		Reserve(length + 5);
	}
	(memory_ptr)[length] = object;
	length++;
};

template <typename T>
void Vector<T>::pop_back() {
	if (empty())
		return;
	length--;
	
};

template <typename T>
int Vector<T>::size() {
	return length;
};

template <typename T>
bool Vector<T>::empty() {
	return length==0;
};

template <typename T>
T Vector<T>::front() {
	return *memory_ptr;
};

template <typename T>
T Vector<T>::back() {
	return *(memory_ptr+length-1);
};

template<typename T>
T& Vector<T>::At(int index) {
	return const_cast<T&>(std::as_const(*this).At(index));
};

template<typename T>
const T& Vector<T>::At(int index) const {
	return *(memory_ptr + index);
};

template <typename T>
void Vector<T>::clear() {
	delete[] memory_ptr;
	memory_ptr = nullptr;
	length = 0;
	capacity = 0;
};

template<typename T>
void Vector<T>::Reserve(int N) {
	if (N < length)
		return;
	capacity = N;
	T* tmp = new T[N];
	for (int i = 0; i < length; i++) {
		*(tmp + i) = *(memory_ptr + i);
	}
	delete[] memory_ptr;
	memory_ptr = tmp;
}

template<typename T>
void Vector<T>::Resize(int N) {
	if (N < 0)
		return;
	if (N <= capacity)
		length = N;
}

//other operator 
template <typename T>
T& Vector<T>::operator[](size_t index) {
	return const_cast<T&>(std::as_const(*this)[index]);
};

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
	return (memory_ptr)[index];
};

//  iterator manipulate
template <typename T>
typename Vector<T>::Iterator Vector<T>::begin() {
	Iterator result{ memory_ptr };
	return result;
};

template <typename T>
typename Vector<T>::Iterator Vector<T>::end() {
	Iterator result {memory_ptr+length};       // front close behind open
	return result;
};

template <typename T>
void Vector<T>::insert(Iterator index, T object) {
	if (index > end())
		return;
	if (index < begin())
		return;
	if (length == capacity) {
		Reserve(length + 5);
	}
	auto tmp = index;
	for (index = end(); index >= tmp; index--) {
		*(index + 1) = *(index);
	}
	*(tmp) = object;
	length++;
};

template <typename T>
void Vector<T>::erase(Iterator index) {
	if (empty())
		return;
	if (index >= end())
		return;
	if (index < begin())
		return;
	for (index++; index < end(); index++) {
		*(index - 1) = *(index);
	}
	length--;

};

template <typename T>
void Vector<T>::erase(Iterator index1, Iterator index2) {
	if (empty())
		return;
	if (index2 >= end())
		return;
	if (index2 <= index1)
		return;
	if (index1 < begin())
		return;
	auto tmp = index1;
	for (; tmp < end(); tmp++) {
		*(tmp - (index1 - index2)) = *tmp;
	}
	length -= index1 - index2;
};

// iterator function

template<typename T>
Vector<T>::Iterator::Iterator(T* pointer) {
	iter = pointer;
}

template <typename T>       //  prefix
void Vector<T>::Iterator::operator++() {
	iter++;
};     


template <typename T>
void Vector<T>::Iterator::operator--() {
	iter--;
};

template <typename T>     //postfix
void Vector<T>::Iterator::operator++(int) {
	iter++;
};

template <typename T>
void Vector<T>::Iterator::operator--(int) {
	iter--;
};

template <typename T>
bool Vector<T>::Iterator::operator == (const Iterator& index) {
	return iter == index.iter;
};

template <typename T>
bool Vector<T>::Iterator::operator != (const Iterator& index) {
	return iter != index.iter;
};

template <typename T>
bool Vector<T>::Iterator::operator > (const Iterator& index) {
	return iter > index.iter;
};

template <typename T>
bool Vector<T>::Iterator::operator >= (const Iterator& index) {
	return iter >= index.iter;
};

template <typename T>
bool Vector<T>::Iterator::operator < (const Iterator& index) {
	return iter < index.iter;
};

template <typename T>
bool Vector<T>::Iterator::operator <= (const Iterator& index) {
	return iter <= index.iter;
};

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator+(int offset) {
	Iterator result(iter + offset);
	return result;
};

template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator-(int offset) {
	Iterator result(iter - offset);
	return result;
};

template <typename T>
int Vector<T>::Iterator::operator-(const Iterator& index) {
	Iterator result(iter -index);
	return result;
};

template<typename T>
void Vector<T>::Iterator::operator=(const Iterator& index) {
	iter = index.iter;
};

template <typename T>
T& Vector<T>::Iterator::operator*() {
	return *iter;
};

template <typename T>
typename Vector<T>::Iterator Find(Vector<T>& v, T target) {
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		if (*Iter == target)
			return Iter;
	}
	return v.end();
};


template <typename T>
typename Vector<T>::Iterator Remove(Vector<T>& v, T target) {
	int counts = 0;
	for (auto Iter = v.begin(); Iter != v.end(); Iter++) {
		if (*Iter == target)
			continue;
		*(v.begin() + counts) = *Iter;
		counts++;
	}
	for (auto Iter = (v.begin() + counts); Iter != v.end(); Iter++) {
		*Iter = target;
	}
	return v.begin() + counts;// point on the first one that would be deleted
};
#endif 