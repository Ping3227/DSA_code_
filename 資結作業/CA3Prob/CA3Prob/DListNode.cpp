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
/**
 *  A DListNode is a node in a DList (doubly-linked list).
 */

#include "DListNode.h"

/**
 *  DListNode() constructor.
 *  @param i the item to store in the node.
 *  @param p the node previous to this node.
 *  @param n the node following this node.
 */
template<typename T>
DListNode<T>::DListNode(const T& i, DListNode<T>* p,
		DListNode<T>* n) {
	item = i;
	prev = p;
	next = n;
}

