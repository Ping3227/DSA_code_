/**
 *  A class that stores a variable of type int.
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/

 /*
 @author 			黃緯翔  Huang-wei-hsiang
 @ID 				B09204045
 @Department 		地質科學系 Geosciences
 @Affiliation 	National Taiwan University
 I put all the  inform at HashTableChained.h
 */
#ifndef INTEGER_H
#define INTEGER_H

class Integer {
private:
  int i;

public:

  /**
   *  Construct a new Integer with the given variable.
   *  @param i the int variable by which the Integer stores.
   */
  Integer(const int& i) {
    this->i = i;
  }

  /**
   *  Get the value of the int variable.
   *  @return the stored value.
   */
  int getvalue() const {
    return i;
  }
};

#endif
