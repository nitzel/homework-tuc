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
}
void List::insert (Node *n, int i){
  if(n == nullptr) return;
  Node *c;
  for (c = m_first; next(c) != n && c != nullptr; c = next(c)); // get node before *n

  if(next(c) == n){
    c->m_next = new Node(i, n); // insert new node
  }
}
void List::erase (Node *n){
  if(n == nullptr) return;
  Node * c;
  for (c = m_first; next(c) != n && c != nullptr; c = next(c)); // get node before *n
  if(next(c) == n){
    c->m_next = n->m_next;
    n->m_next = nullptr;
  }
  delete n; // delete n anyways
}

void List::print() const {
  std::cout << "List: ";
  for (Node *n = first(); n != 0; n = next(n))
    std::cout << "->" << n->value;
  std::cout << std::endl;
}
