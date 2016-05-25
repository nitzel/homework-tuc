/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Node.hpp
 * @desc Homework Blatt3 for SciProg
 * A node for a double linked list, pointing to the next&previous node in line.
 * It contains an integer as value.
*/

#ifndef __H__NODE__
#define __H__NODE__

#include <iostream>
#include <memory> // smart pointers

class Node;

typedef std::shared_ptr<Node> NodeShared;
typedef std::weak_ptr<Node> NodeWeak;

class Node
{
friend class List;
public:
  Node(int i) : Node(i, nullptr, nullptr) {};
  Node(int i, NodeShared prev, NodeShared next) :
    Node(i, NodeWeak(prev), next){};
  Node(int i, NodeWeak prev, NodeShared next) {
     value = i;
     this->next = next;
     this->prev = prev;
  }

  ~Node(){ // deletes the next node, too = whole list
    std::cout << "dtor Node " << value << std::endl;
  }

  int value;
private:
  NodeShared next;
  NodeWeak prev; // previous
};

#endif
