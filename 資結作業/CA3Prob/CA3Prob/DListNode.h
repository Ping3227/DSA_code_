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
#ifndef DLISTNODE_H
#define DLISTNODE_H

template<typename T>
class DList;

template<typename T>
class DListNode {
	/**
	 *  item references the item stored in the current node.
	 *  prev references the previous node in the DList.
	 *  next references the next node in the DList.
	 *
	 *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
	 */

protected:
	DListNode<T>* prev;
	DListNode<T>* next;
	friend class DList<T>;
	

public:
	T item;

	/**
	 *  DListNode() constructor.
	 *  @param i the item to store in the node.
	 *  @param p the node previous to this node.
	 *  @param n the node following this node.
	 */
	DListNode(const T& i, DListNode<T>* p, DListNode<T>* n);
};

#endif
