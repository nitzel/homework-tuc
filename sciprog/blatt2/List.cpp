/**
 * @author Jan Schnitker
 * @file Node.cpp
 * @desc Homework Blatt1 for SciProg
 * See Rational.hpp
 */
#include "List.hpp"

List::List (const int * array, int length){
  m_first = new Node(-1);
  for(int i=0; i<length; ++i)
    append(array[i]);
}

List::~List () {
  std::cout << "destr: ";
  print();
  delete m_first; // recurses!
}
Node* List::first() const {
  return next(m_first); //m_first->m_next;
}
Node* List::next(const Node *n) const {
  if(n == nullptr) return nullptr;
  return n->m_next;
}
void List::append (int i) {
  Node *c;
  for (c = m_first; next(c) != 0; c = next(c)); // get last node
  c->m_next = new Node(i);
  m_minCacheOk = false;
  m_maxCacheOk = false;
}
void List::insert (Node *n, int i){
  if(n == nullptr) return;
  Node *c;
  for (c = m_first; next(c) != n && c != nullptr; c = next(c)); // get node before *n

  if(next(c) == n){
    c->m_next = new Node(i, n); // insert new node
    m_minCacheOk = false;
    m_maxCacheOk = false;
  }
}
void List::erase (Node *n){
  if(n == nullptr) return;
  Node * c;
  for (c = m_first; next(c) != n && c != nullptr; c = next(c)); // get node before *n
  if(next(c) == n){
    c->m_next = n->m_next;
    n->m_next = nullptr; // to avoid deletion of the whole list
    m_minCacheOk = false;
    m_maxCacheOk = false;
  }
  delete n; // delete n anyways
}

void List::print() const {
  std::cout << "List: ";
  for (Node *n = first(); n != 0; n = next(n))
    std::cout << "->" << n->value;
  std::cout << std::endl;
}

Node * List::findMin() {
  static Node * last; // cached minimum
  if(m_minCacheOk) {
    std::cout << "(Min-Cache used) ";
    return last;
  }
  // update cache
  Node * min = nullptr;
  for (Node * c = m_first->m_next; c != nullptr; c = next(c)){
    // if min is not initialized or higher than c, overwrite
    if(min == nullptr || min->value > c->value)
      min = c;
  }

  last = min;
  m_minCacheOk = true;
  return min;
}
Node * List::findMax() {
  static Node * last; // cached maximum
  if(m_maxCacheOk){
    std::cout << "(Max-Cache used) ";
    return last;
  }
  // update cache
  Node * max = nullptr;
  for (Node * c = m_first->m_next; c != nullptr; c = next(c)){
    // if min is not initialized or higher than c, overwrite
    if(max == nullptr || max->value < c->value)
      max = c;
  }

  last = max;
  m_maxCacheOk = true;
  return max;
}
