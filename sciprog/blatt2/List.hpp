/**
 * @author Jan Schnitker
 * @file Node.hpp
 * @desc Homework Blatt2 for SciProg
*/

#ifndef __H__LIST__
#define __H__LIST__

#include <iostream>
#include "Node.hpp"

class List {
public:
  void print() const;

  List () : List(nullptr, 0) {};  // create an empty list
  List (const int * array, int length);  // create a list resembling the array
  ~List ();  // clean up the list and all nodes
  Node *first() const;  // return a pointer to the first entry
  Node *next(const Node *n) const; // return a pointer to the node after n

  Node * findMin() const; // find node with lowest value
  Node * findMax() const; // find node with highest value
  void append (int i);  // append a value to the end of the list
  // insert a value before n. won't insert if n is missing
  void insert (Node *n, int i);
  void erase (Node *n);  // remove n from the list
private:
  Node * m_first; // pseudo node, points to the first real node in the list
};

#endif
