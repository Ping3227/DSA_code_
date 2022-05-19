/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 **/

 /*
 @author 			黃緯翔  Huang-wei-hsiang
 @ID 				B09204045
 @Department 		地質科學系 Geosciences
 @Affiliation 	National Taiwan University
 I put all the  inform at HashTableChained.h
 */
#include <iostream>
#include <iomanip>
#include "HashTableChained.h"

/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {
	load_factor = 0.5;
	bool prime{0};
	
	while (!prime)
	{
		prime = 1;
		for (int i{ 2 };i<sizeEstimate/2; i++) {
			
			if ((sizeEstimate % i) == 0) {
				prime = 0;
				break;
			}
			
			
		}
		
		sizeEstimate++;
		
	}
	
	bucket = --sizeEstimate;
	container.resize(bucket, std::list<Entry<K, V>>());
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained() {
	bucket = 107;
	container.resize(bucket, std::list<Entry<K, V>>);
	load_factor = INT_MAX;
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::compFunction(int code) {
    
    code=((31*code)% 3571)%bucket ;
	return code >= 0 ? code : code + bucket;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::size() {
	return number_of_elements;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {
	return number_of_elements == 0;
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value) {
	
	
	if ((double(++number_of_elements) / bucket) >= load_factor) {
		resort();
	}
	container[compFunction(key->hashCode())].push_back(Entry<K, V>(key, value));
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::find(const K& key) {

	auto& current_list= container[compFunction(key->hashCode())];
	for (auto itr = current_list.begin(); itr != current_list.end(); itr++) {
		if (key->equals(*(itr->getkey()))) return true;
		
	}
	return false;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void HashTableChained<K, V>::remove(const K& key) {
	
	auto& current_list = container[compFunction(key->hashCode())];
	
	for (auto itr = current_list.begin(); itr != current_list.end(); itr++) {
			
		if (key->equals(*(itr->getkey()))) {

			current_list.erase(itr);

			number_of_elements--;
			return;
		}

	}

	
	
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {
	for (int i{}; i < bucket; i++) {
		for (auto itr = container[i].begin(); itr != container[i].end(); itr++) {
			delete itr->getkey();
			delete itr->getvalue();

		}
	}
	
	container.resize(bucket, std::list<Entry<K, V>>());
	number_of_elements = 0;
	return;
}
template<typename K, typename V>
void HashTableChained<K, V>::resort() {
	
	bucket*=2;
	
	bool prime{ 0 };
	while (!prime)
	{
		prime = 1;
		for (int i{ 2 }; i < bucket / 2; i++) {
			if ((bucket % i) == 0) {
				prime = 0;
				 
				break;
			}

		}
		bucket++;
	}
	bucket--;
	
	std::vector<std::list<Entry<K, V>>> new_container{};
	new_container.resize(bucket, std::list<Entry<K, V>>());
	for (std::list<Entry<K, V>>& a : container) {
		for (auto itr= a.begin();itr!= a.end();itr++)
			new_container[compFunction(itr->getkey()->hashCode())].push_back(Entry<K, V>(itr->getkey(), itr->getvalue()));
	}
	container = new_container;
}




template<typename K, typename V>
void HashTableChained<K, V>::show_object() {
	int count[10]{};
	for (int i{}; i < bucket; i++) {
		std::cout <<"bucket" << std::setw(4) << i+1<<" : ";
		int j{};
		for (auto itr = container[i].begin(); itr != container[i].end(); itr++) {
			
			if (++j % 10 == 0) {
				std::cout<<std::endl;
			}
			std::cout << " -- " <<(itr->getvalue())->getvalue();
			
		}
		std::cout<<std::endl;
		count[j]++;
		
	}
	for (int k{}; k < 10; k++) {
		std::cout << k  << "elements: " << count[k]<<std::endl;
	}
	
};