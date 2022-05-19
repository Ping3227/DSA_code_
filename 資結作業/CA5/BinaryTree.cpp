/*
@author 			黃緯翔  Huang-wei-hsiang
@ID 				B09204045
@Department 		地質科學系 Geosciences
@Affiliation 	National Taiwan University
in this program i use recursion to deal with the findhelper,makeEmpty(by emptyHelper)
emptyhelper is a function i add for using recursion method on makeempty()
check left and right node ,then delete current node 

in funciton remove()
I first check whether both left right child exist ,if not , i can just delete it ,
and making their parent(include root ptr)and child point at each other

if not ,find the next larger key elelment (as inorder order) ,it  definely dont have any left child,satify the top condition   
then switch it with the node which going to be deleted(my way is to switch their entry for wasting time)

*/
#include "BinaryTree.h"
using namespace std;

template<typename K, typename V>
BinaryTree<K, V>::BinaryTree() {
  makeEmpty();
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int BinaryTree<K, V>::size() {
  return tsize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool BinaryTree<K, V>::isEmpty() {
  return size() == 0;
}

template<typename K, typename V>
void BinaryTree<K, V>::insertHelper(Entry<K, V>* entry, const K& key, BinaryTreeNode<K, V>* node) {
  if (key.compareTo(node->entry->getkey()) <= 0) {
    if (node->leftChild == NULL) {
      node->leftChild = new BinaryTreeNode<K, V>(entry, node);
    } else {
      insertHelper(entry, key, node->leftChild);
    }
  } else {
    if (node->rightChild == NULL) {
      node->rightChild = new BinaryTreeNode<K, V>(entry, node);
    } else {
      insertHelper(entry, key, node->rightChild);
    }
  }
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void BinaryTree<K, V>::insert(const K& key, const V& value) {
  Entry<K, V>* entry = new Entry<K, V>(key, value);
  if (root == NULL) {
    root = new BinaryTreeNode<K, V>(entry);
  } else {
    insertHelper(entry, key, root);
  }
  tsize++;
}

/**
 *  Search for a node with the specified key, starting from "node".  If a
 *  matching key is found (meaning that key1.compareTo(key2) == 0), return
 *  a node containing that key.  Otherwise, return null.
 *
 *  Be sure this method returns null if node == null.
 **/
template<typename K, typename V>
BinaryTreeNode<K, V>* BinaryTree<K, V>::findHelper(const K& key, BinaryTreeNode<K, V>* node) {
  // Replace the following line with your solution.
    if (!node) return nullptr;
    if (key.compareTo(node->entry->getkey()) == 0) {
        return node;
    }
    BinaryTreeNode<K, V>* The_Node{};
    
    if (key.compareTo(node->entry->getkey()) > 0) { // using recursion to find the target node
        The_Node = findHelper(key, node->rightChild); 
    }
    else {
        The_Node = findHelper(key, node->leftChild);
    }
    return The_Node;
    
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  @param key the search key.
 *  @return an entry containing the key and an associated value, or null if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
Entry<K, V>* BinaryTree<K, V>::find(const K& key) {
  BinaryTreeNode<K, V>* node = findHelper(key, root);
  if (node != NULL) {
    return node->entry;
  } else {
    return NULL;
  }
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void BinaryTree<K, V>::remove(const K& key) {
    BinaryTreeNode<K, V>* node = findHelper(key, root);
    if (node) {
        BinaryTreeNode<K, V>* delete_node{};
        BinaryTreeNode<K, V>* child_node{};
        if (!node->leftChild || !node->rightChild) {   //if one of child doesnt exist ,the node can be deleted easily
            delete_node = node;
        }
        else {
            delete_node = node->rightChild;
            while (delete_node->leftChild) {
                delete_node = delete_node->leftChild;  // find the next number greater than node 

            }
            Entry<K,V> * copy_entry = node->entry;  // I choose exchange the entry for avoiding too much ptr change
            node->entry = delete_node->entry;
            delete_node->entry = copy_entry;
        }
        if (delete_node->leftChild)child_node = delete_node->leftChild;
        else child_node = delete_node->rightChild;

        if (child_node) child_node->parent = delete_node->parent;

        if (!delete_node->parent) root = child_node;
        else if (delete_node == delete_node->parent->leftChild) delete_node->parent->leftChild = child_node;
        else delete_node->parent->rightChild = child_node;

        
        delete delete_node;
        tsize--;
    }
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void BinaryTree<K, V>::makeEmpty() {
    if (root) emptyHelper(root);
    tsize = 0;
}

/**
 *  Convert the tree into a string.
 **/
template<typename K, typename V>
std::string BinaryTree<K, V>::toString() {
  if (root == NULL) {
    return "";
  } else {
    return root->toString();
  }
}

// help method ,using the recursion to delete all node
template<typename K, typename V>
void BinaryTree<K, V>::emptyHelper(BinaryTreeNode<K, V>* node) {
    if(node->leftChild) emptyHelper(node->leftChild);
    if(node->rightChild)emptyHelper(node->rightChild);
    delete node;
};