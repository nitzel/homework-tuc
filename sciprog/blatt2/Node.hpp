/**
 * @author Jan Schnitker
 * @file Node.hpp
 * @desc Homework Blatt2 for SciProg
*/

#ifndef __H__NODE__
#define __H__NODE__

#include <iostream>
//#include "List.hpp"

class Node
{
friend class List;
public:
  Node(int i) : Node(i, 0) {};
  Node(int i, Node * next) {
     value = i;
     m_next = next;
  }

  ~Node(){ // delete the next node, too = whole list
    delete m_next;  m_next = 0;
  }

  int value;
private:
  Node * m_next;
};

#endif
