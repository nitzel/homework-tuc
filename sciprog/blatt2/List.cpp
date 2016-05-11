/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Node.cpp
 * @desc Homework Blatt1 for SciProg
 * See List.hpp
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
  return next(m_first); //m_first->next;
}
Node* List::next(const Node *n) const {
  if(n == nullptr) return nullptr;
  return n->next;
}
void List::append (int i) {
  Node *c;
  for (c = m_first; next(c) != nullptr; c = next(c)); // get last node
  c->next = new Node(i);
  m_maxCache = nullptr; // reset max cache
  m_minCache = nullptr; // reset min cache
}
void List::insert (Node *n, int i){
  if(n == nullptr) return;
  Node *c;
  for (c = m_first; next(c) != n && c != nullptr; c = next(c)); // get node before *n

  if(next(c) == n){
    c->next = new Node(i, n); // insert new node
    m_maxCache = nullptr; // reset max cache
    m_minCache = nullptr; // reset min cache
  }
}
void List::erase (Node *n){
  if(n == nullptr) return;
  Node * c;
  for (c = m_first; next(c) != n && c != nullptr; c = next(c)); // get node before *n
  if(next(c) == n){
    c->next = n->next;
    n->next = nullptr; // to avoid deletion of the whole list

    if(n == m_maxCache) m_maxCache = nullptr; // reset max cache
    if(n == m_minCache) m_minCache = nullptr; // reset min cache
  }
  delete n; // delete n anyways - this may or may not be a good idea
}

void List::print() const {
  std::cout << "List: ";
  for (Node *n = first(); n != 0; n = next(n))
    std::cout << "->" << n->value;
  std::cout << std::endl;
}

Node * List::findMin() {
  if(m_minCache) {
    std::cout << "(Using Min-Cache) ";
    return m_minCache;
  }
  // update cache
  Node * min = nullptr;
  for (Node * c = m_first->next; c != nullptr; c = next(c)){
    // if min is not initialized or higher than c, overwrite
    if(min == nullptr || min->value > c->value)
      min = c;
  }

  m_minCache = min;
  return min;
}
Node * List::findMax() {
  if(m_maxCache){
    std::cout << "(Using Max-Cache) ";
    return m_maxCache;
  }
  // update cache
  Node * max = nullptr;
  for (Node * c = m_first->next; c != nullptr; c = next(c)){
    // if min is not initialized or higher than c, overwrite
    if(max == nullptr || max->value < c->value)
      max = c;
  }

  m_maxCache = max;
  return max;
}
