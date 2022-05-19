/**
 *
 * @author 			黃緯翔  Huang-wei-hsiang
 * @ID 				B09204045
 * @Department 		地質科學系 Geosciences
 * @Affiliation 	National Taiwan University
 *
 * 
 * this code is worte on my own by c++ on visual studio
 */
#include "LockDList.h"

// check wheather the nod valid or not 
// then static_cast to LockDList for using lock member 
template<typename T>
void LockDList<T>::lockNode(DListNode<T>* node) {
	if (node == nullptr || node == DList<T>::head) return;
	static_cast<LockDListNode<T>*>(node)->lock = true;
};

//using DList to initialize
template <typename T> 
LockDList<T>::LockDList() :DList<T>{} {};

//override the function,new LockDlistNode ,not DlistNode
template <typename T> 
DListNode<T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev,DListNode<T>* next) {
	
	DListNode<T> * new_node = new LockDListNode<T>(item, prev, next);
	static_cast<LockDListNode<T>*>(prev)->next = static_cast<LockDListNode<T>*>(next)->prev = new_node;
	return new_node;
};

//check if the node valid and wheather it is locked
//then use Dlist funciton to remove node
template<typename T>
void LockDList<T>::remove(DListNode<T>* node) {
	if (node == nullptr) return;
	if (static_cast<LockDListNode<T>*>(node)->lock) return;
	DList<T>::remove(node);
}