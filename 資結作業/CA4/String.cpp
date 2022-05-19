/**
 *  A class that stores a string and generates a hash code for it.
 *
 **/

 /*
 @author 			���n��  Huang-wei-hsiang
 @ID 				B09204045
 @Department 		�a���Ǩt Geosciences
 @Affiliation 	National Taiwan University
 I put all the  inform at HashTableChained.h
 */
#include "String.h"
#include <typeinfo>
#include <exception>
/**
 *  Construct a new String with the given variable.
 *  @param str the string by which the String stores.
 */
String::String(const string& str) {
    this->str = str;
}

/**
 *  Get the value of the string variable.
 *  @return the stored value.
 */
string String::getvalue() const {
    return str;
}

/**
 *  Returns true if "this" String and "strg" have identical values.
 *  @param strg is the second String.
 *  @return true if the string values are equal, false otherwise.
 */
bool String::equals(const String& strg) {
    // Replace the following line with your solution.  Be sure to return false
    //   (rather than throwing a ClassCastException) if "strg" is not
    //   a String.
    
    if (typeid(strg) != typeid(String)) return false;
    if (str == strg.getvalue()) return true;
    return false;
}

/**
 *  Returns a hash code for this String.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int String::hashCode() const {
    // Replace the following line with your solution.
    long long hash{};
    int i{};
    for (char a : str) {
        hash += a*a;

        hash *= 73939;
    }
    return hash;
}
