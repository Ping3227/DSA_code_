/**
/**
 *
 * @author 			黃緯翔  Huang-wei-hsiang
 * @ID 				B09204045
 * @Department 		地質科學系 Geosciences
 * @Affiliation 	National Taiwan University
 *
 * 
 * 
 * this code is worte on my own by c++ on visual studio
 *
 *  A DList is a mutable doubly-linked list ADT.  Its implementation is
 *  circularly-linked and employs a sentinel (dummy) node at the head
 *  of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

#include <iostream>
#include "DList.h"

using namespace std;

/* DList invariants:
 *  1)  head != null.
 *  2)  For any DListNode x in a DList, x.next != null.
 *  3)  For any DListNode x in a DList, x.prev != null.
 *  4)  For any DListNode x in a DList, if x.next == y, then y.prev == x.
 *  5)  For any DListNode x in a DList, if x.prev == y, then y.next == x.
 *  6)  size is the number of DListNodes, NOT COUNTING the sentinel,
 *      that can be accessed from the sentinel (head) by a sequence of
 *      "next" references.
 */

/**
 *  newNode() calls the DListNode constructor.  Use this class to allocate
 *  new DListNodes rather than calling the DListNode constructor directly.
 *  That way, only this method needs to be overridden if a subclass of DList
 *  wants to use a different kind of node.
 *  @param item the item to store in the node.
 *  @param prev the node previous to this node.
 *  @param next the node following this node.
 */
template<typename T>
DListNode<T>* DList<T>::newNode(const T& item,
		DListNode<T>* prev, DListNode<T>* next) {
	DListNode<T> *new_node = new DListNode<T>(item, prev, next);
	prev->next = next->prev = new_node;
	return new_node;
}

/**
 *  DList() constructor for an empty DList.
 */
template<typename T>
DList<T>::DList() {
	head = new DListNode<T>{0,nullptr,nullptr}; // create a sentinel node
	head->next = head->prev = head;
}

/**
 *  isEmpty() returns true if this DList is empty, false otherwise.
 *  @return true if this DList is empty, false otherwise. 
 *  Performance:  runs in O(1) time.
 */
template<typename T>
bool DList<T>::isEmpty() {
	return size == 0;
}

/** 
 *  length() returns the length of this DList. 
 *  @return the length of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
int DList<T>::length() {
	return size;
}

/**
 *  insertFront() inserts an item at the front of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertFront(const T& item) {
	newNode(item, head, head->next);
	size++;
}

/**
 *  insertBack() inserts an item at the back of this DList.
 *  @param item is the item to be inserted.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertBack(const T& item) {
	newNode(item, head->prev, head);
	size++;
}

/**
 *  front() returns the node at the front of this DList.  If the DList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the front of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::front() {
	if (isEmpty())return nullptr;
	return head->next;
}

/**
 *  back() returns the node at the back of this DList.  If the DList is
 *  empty, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @return the node at the back of this DList.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::back() {
	if (isEmpty())return nullptr;
	return head->prev;
}

/**
 *  next() returns the node following "node" in this DList.  If "node" is
 *  null, or "node" is the last node in this DList, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @param node the node whose successor is sought.
 *  @return the node following "node".
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::next(DListNode<T>* node) {
	if (!node||node->next==head) return nullptr;
	return node->next;
}

/**
 *  prev() returns the node prior to "node" in this DList.  If "node" is
 *  null, or "node" is the first node in this DList, return null.
 *
 *  Do NOT return the sentinel under any circumstances!
 *
 *  @param node the node whose predecessor is sought.
 *  @return the node prior to "node".
 *  Performance:  runs in O(1) time.
 */
template<typename T>
DListNode<T>* DList<T>::prev(DListNode<T>* node) {
	if (!node || node->prev == head) return nullptr;
	return node->prev;
}

/**
 *  insertAfter() inserts an item in this DList immediately following "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item after.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertAfter(const T& item, DListNode<T>* node) {
	if (!node) return ;
	newNode(item, node, node->next);
	size++;
}

/**
 *  insertBefore() inserts an item in this DList immediately before "node".
 *  If "node" is null, do nothing.
 *  @param item the item to be inserted.
 *  @param node the node to insert the item before.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::insertBefore(const T& item, DListNode<T>* node) {
	if (!node) return;
	newNode(item, node->prev, node);
	size++;
}

/**
 *  remove() removes "node" from this DList.  If "node" is null, do nothing.
 *  Performance:  runs in O(1) time.
 */
template<typename T>
void DList<T>::remove(DListNode<T>* node) {
	if (node == nullptr||node==head) return;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
	size--;
}

/**
 *  toString() prints a string representation of this DList.
 *
 *  DO NOT CHANGE THIS METHOD.
 *
 *  Performance:  runs in O(n) time, where n is the length of the list.
 */
template<typename T>
void DList<T>::toString() {
	cout << "  ListNode     Item   " << endl;
	cout << "----------------------" << endl;
	DListNode < T > *current = head->next;
	int i = 1;
	while (current != head) {
		cout << i++ << "        " << current->item << endl;
		current = current->next;
	}
}
