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
#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H

#include "DListNode.h"

template<typename T>
class LockDList;

template<typename T>
class LockDListNode: public DListNode<T> {
public:
	LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n);
	friend class LockDList<T>;
protected:
	// I add a boolean lock to cheack wheather lock or not 
	bool lock{};

};

#endif
