/**
 *
 * @author 			���n��  Huang-wei-hsiang
 * @ID 				B09204045
 * @Department 		�a���Ǩt Geosciences
 * @Affiliation 	National Taiwan University
 *
 * 
 * 
 * this code is worte on my own by c++ on visual studio
 */
//use DListNode constructor to construct
#include "LockDListNode.h"
template <typename T>
LockDListNode<T>::LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n) :DListNode<T>{ i ,p,n } {
};