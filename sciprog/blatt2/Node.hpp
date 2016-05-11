/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Node.hpp
 * @desc Homework Blatt2 for SciProg
 * A node for a linked list, pointing to the next node in line.
 * It contains an integer as value.
*/

#ifndef __H__NODE__
#define __H__NODE__

#include <iostream>

class Node
{
friend class List;
public:
  Node(int i) : Node(i, 0) {};
  Node(int i, Node * next) {
     value = i;
     this->next = next;
  }

  ~Node(){ // deletes the next node, too = whole list
    std::cout << "destr node " << value << std::endl;
    delete next;  next = nullptr;
  }

  int value;
private:
  Node * next;
};

#endif
