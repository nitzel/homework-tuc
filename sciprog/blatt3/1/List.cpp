/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Node.cpp
 * @desc Homework Blatt1 for SciProg
 * See List.hpp
 */
#include "List.hpp"

List::List (const int * array, int length){
  m_first = NodeShared(new Node(-1));
  for(int i=0; i<length; ++i)
    append(array[i]);
}

List::~List () {
  std::cout << "destr: ";
  print();
  //delete m_first; // recurses!
}
NodeShared List::first() const {
  return next(m_first); //m_first->next;
}
NodeShared List::next(const NodeShared n) const {
  if(n == nullptr) return nullptr;
  return n->next;
}
void List::append (int i) {
  NodeShared c;
  for (c = m_first; next(c) != nullptr; c = next(c)); // get last node
  c->next = NodeShared(new Node(i));
  m_maxCache = nullptr; // reset max cache
  m_minCache = nullptr; // reset min cache
}
void List::insert (NodeShared n, int i){
  if(n == nullptr) return;
  NodeShared c;
  for (c = m_first; next(c) != n && c != nullptr; c = next(c)); // get node before *n

  if(next(c) == n){
    c->next = NodeShared(new Node(i, n)); // insert new node
    m_maxCache = nullptr; // reset max cache
    m_minCache = nullptr; // reset min cache
  }
}
void List::erase (NodeShared n){
  if(n == nullptr) return;
  NodeShared c;
  for (c = m_first; next(c) != n && c != nullptr; c = next(c)); // get node before *n
  if(next(c) == n){
    c->next = n->next;
    n->next = nullptr; // to avoid deletion of the whole list

    if(n == m_maxCache) m_maxCache = nullptr; // reset max cache
    if(n == m_minCache) m_minCache = nullptr; // reset min cache
  }
  //delete n; // delete n anyways - this may or may not be a good idea
}

void List::print() const {
  std::cout << "List: ";
  for (NodeShared n = first(); n != 0; n = next(n))
    std::cout << "->" << n->value;
  std::cout << std::endl;
}

NodeShared List::findMin() {
  if(m_minCache) {
    std::cout << "(Using Min-Cache) ";
    return m_minCache;
  }
  // update cache
  NodeShared min = nullptr;
  for (NodeShared c = m_first->next; c != nullptr; c = next(c)){
    // if min is not initialized or higher than c, overwrite
    if(min == nullptr || min->value > c->value)
      min = c;
  }

  m_minCache = min;
  return min;
}
NodeShared List::findMax() {
  if(m_maxCache){
    std::cout << "(Using Max-Cache) ";
    return m_maxCache;
  }
  // update cache
  NodeShared max = nullptr;
  for (NodeShared c = m_first->next; c != nullptr; c = next(c)){
    // if min is not initialized or higher than c, overwrite
    if(max == nullptr || max->value < c->value)
      max = c;
  }

  m_maxCache = max;
  return max;
}
