/**
 *  A class for dictionary entries.
 *
 *  DO NOT CHANGE THIS FILE.  It is part of the interface of the
 *  Dictionary ADT.
 **/

 /*
 @author 			黃緯翔  Huang-wei-hsiang
 @ID 				B09204045
 @Department 		地質科學系 Geosciences
 @Affiliation 	National Taiwan University
 I put all the  inform at HashTableChained.h
 */
#ifndef ENTRY_H
#define ENTRY_H

template<typename K, typename V>
class Entry {
protected:
  K key;
  V value;

public:
  Entry(K k, V v) {
    key = k;
    value = v;
  }

  K& getkey() {
    return key;
  }

  V& getvalue() {
    return value;
  }

};

#endif
