/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Node.hpp
 * @desc Homework Blatt3 for SciProg
 * A double linked list consisting of Nodes. Offers several methods
 * for appending, inserting, erasing and also finding the min/max Nodes.
*/

#ifndef __H__LIST__
#define __H__LIST__

#include <iostream>
#include <memory> // smart pointers
#include "Node.hpp"

class List {
public:
  void print() const;

  List () : List(nullptr, 0) {};  // create an empty list
  List (const int * array, int length);  // create a list resembling the array
  ~List ();  // clean up the list and all nodes
  NodeShared first() const;  // return a pointer to the first entry
  NodeShared next(const NodeShared n) const; // return a pointer to the node after n
  NodeShared prev(const NodeShared n) const; // return a pointer to the node before n, but not m_start

  NodeShared findMin(); // find node with lowest value
  NodeShared findMax(); // find node with highest value
  void append (int i);  // append a value to the end of the list
  // insert a value before n. won't insert if n is missing
  void insert (NodeShared n, int i);
  void erase (NodeShared n);  // remove n from the list and delete it.
private:
  NodeShared m_first; // pseudo node, points to the first real node in the list
  NodeShared m_maxCache = nullptr; // the cache for the maximum
  NodeShared m_minCache = nullptr; // the cache for the maximum

  NodeShared prev_(const NodeShared n) const; // return a pointer to the node before n, including m_start
};

#endif
