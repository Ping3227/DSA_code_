// hash function 
//  1: division 餘數
//  2: mulitiplication     size *( ( key * C ) % 1 )
//  3: mid square          key^2  取二進位中間幾碼
//  4: floding addition    key 切割再相加
//  5: digit analysis


//open addressing is hash that save all value in a slot 
//1.linear
//2.quadratic
//3.double hash 
//perfect hashing -> hash to a hash than hash to value 

// this project is chaining hash 
#ifndef HASH_H
#define HASH_H
#include <vector>
#include <list>
#include <iostream>

//Class unorder map
template <typename T1,typename T2>
class Unorder_map{

private:
	int amount;
	int len;
	class node;
	std::vector<std::list<node>> memory;
	int function(T1 key);  // hash function
	void rehashing();

public:
	Unorder_map(int size =128);
	~Unorder_map() =default;
	T2& operator[](T1 key);
	void print();
};

//class node in class on order map
template <typename T1, typename T2>
class Unorder_map<T1, T2>::node{
public:
	T1 key;
	T2 value;
	node(T1 input);
	node(T1 input1, T2 input2);
};

// node function
template <typename T1, typename T2>
Unorder_map<T1, T2>::node::node(T1 input) {
	key = input;
};

//for rehashing
template <typename T1, typename T2>
Unorder_map<T1, T2>::node::node(T1 input1, T2 input2) {
	key = input1;
	value = input2;
};

//unorder map funtion 
template <typename T1, typename T2>
Unorder_map<T1, T2>::Unorder_map(int size) {
	len = size;
	memory.resize(size);
}


template <typename T1, typename T2>
T2& Unorder_map<T1, T2>::operator[](T1 key) {
	int index = function(key);//hash function here 
	
	for (auto itr = memory[index].begin(); itr != memory[index].end(); itr++) {
		if (itr->key == key) {
			return itr->value;
		}
	}
	if (++amount/len > 5) {
		rehashing();
		int index = function(key);
	}
	memory[index].push_back(node(key));
	return memory[index].back().value;
};


template <typename T1, typename T2>
void Unorder_map<T1, T2>::rehashing() {
	len *= 2;
	std::vector<std::list<node>> altr_memory(len);
	for (size_t i{}; i < memory.size(); i++) {
		for (auto itr = memory[i].begin(); itr != memory[i].end(); itr++) {
			T1 altr_key = itr->key;
			T2 altr_value = itr->value;
			int index = function(altr_key);
			altr_memory[index].push_back(node(altr_key, altr_value));
		}

	}
	memory = altr_memory;
};

template <typename T1, typename T2>
void Unorder_map<T1, T2>::print() {
	for (size_t i{}; i < memory.size(); i++) {
		for (auto itr = memory[i].begin(); itr != memory[i].end(); itr++) {
			std::cout << "{" << itr->key << "," << itr->value << "}";
		}
		std::cout << std::endl;
	}
};

///hash function here
/*
template<typename T1, typename T2>
int Unordered_Map<T1, T2>::Hash_Func_Mul(T1 input) {
	long long int sum = 0;
	double c = (sqrt(5) - 1) / 2.0;
	int tmp = 1;
	for (char c : input) {
		sum += tmp * c;
		tmp *= 256;
	}
	// get fraction of c*sum
	double frac = c * sum - (int)(c*sum);
	int index = frac * len;
	return index;
}
*/

template <typename T1, typename T2>
int Unorder_map<T1, T2>::function(T1 key) {
	// division
	long long int sum = 0;
	for (char c : key) {
		sum += c;
	}
	return sum % len;
};

#endif
