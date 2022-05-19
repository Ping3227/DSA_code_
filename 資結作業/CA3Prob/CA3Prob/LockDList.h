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
#ifndef LOCKDLIST_H
#define LOCKDLIST_H
#include "DList.h"
#include "LockDListNode.h"

template<typename T>
class LockDList :public DList<T> {
protected:
	DListNode<T>* newNode(const T& item, DListNode<T>* prev,
		DListNode<T>* next) override;
public:
	
	LockDList();
	void lockNode(DListNode<T>* node);
	void remove(DListNode<T>* node);
};

#endif