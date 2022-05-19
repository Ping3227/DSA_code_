/**
 *  A class that stores a variable of type double and generates a hash code for it.
 *
 **/

 /*
 @author 			���n��  Huang-wei-hsiang
 @ID 				B09204045
 @Department 		�a���Ǩt Geosciences
 @Affiliation 	National Taiwan University
 I put all the  inform at HashTableChained.h
 */
#include "Double.h"
#include <typeinfo>
/**
 *  Construct a new Double with the given variable.
 *  @param d the double variable by which the Double stores.
 */
Double::Double(const double& d) {
    this->d = d;
}

/**
 *  Get the value of the double variable.
 *  @return the stored value.
 */
double Double::getvalue() const {
    return d;
}

/**
 *  Returns true if "this" Double and "db" have identical values.
 *  @param db is the second Double.
 *  @return true if the double values are equal, false otherwise.
 */
bool Double::equals(const Double& db) {
    if (typeid(db) != typeid(Double)) return false;
    if (d == db.getvalue()) return true;
    return false;
}

/**
 *  Returns a hash code for this Double.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int Double::hashCode() const{
    // Replace the following line with your solution.
    long long hash{};
    hash = d * 7629137;
    hash %= 7393;
    hash *= 9137;
    return hash;
}
