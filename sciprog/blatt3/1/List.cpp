/**
 * @author Birte Pajunk, Jan Schnitker, Yule Meyer-Olbersleben
 * @file Node.cpp
 * @desc Homework Blatt3 for SciProg
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
  if(!n) return nullptr;
  return n->next;
}

NodeShared List::prev(const NodeShared n) const {
  if(!n /* || n->prev.lock() == m_first */) // null if previous is m_first
    return nullptr;
  return n->prev.lock();
}

void List::append (int i) {
  NodeShared c;
  for (c = m_first; next(c); c = next(c)); // get last node
  c->next = NodeShared(new Node(i, c, nullptr));
  m_maxCache = nullptr; // reset max cache
  m_minCache = nullptr; // reset min cache
}
void List::insert (NodeShared n, int i){
  if(!n) return;
  NodeShared newNode(new Node(i, prev(n), n));
  if(prev(n)) prev(n)->next = newNode;
  if(next(n)) n->prev = newNode;

  m_maxCache = nullptr; // reset max cache
  m_minCache = nullptr; // reset min cache
}
void List::erase (NodeShared n){
  if(!n) return;
  if(prev(n)) prev(n)-> = next(n);
  if(next(n)) next(n)-> = prev(n);
  // we decided not make n->next/prev a nullptr, so that these
  // pointers can still be used if n is continued to be used.

  if(n == m_maxCache) m_maxCache = nullptr; // reset max cache
  if(n == m_minCache) m_minCache = nullptr; // reset min cache
}

void List::print() const {
  std::cout << "List: ";
  for (NodeShared n = first(); n; n = next(n))
    std::cout << "-> " << n->value ;
    // std::cout << "-> (" << n->value << "|" << (prev(n)?prev(n)->value:-5) << "|" << (next(n)?next(n)->value:-5) << ")";
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
