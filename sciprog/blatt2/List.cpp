/**
 * @author Jan Schnitker
 * @file Node.cpp
 * @desc Homework Blatt1 for SciProg
 * See Rational.hpp
 */
#include "List.hpp"

List::List() {
  m_first = new Node(-1);
}
List::~List () {
  std::cout << "deleting: ";
  print();
  delete m_first; // recurses!
}
Node* List::first() const {
  return next(m_first); //m_first->m_next;
}
Node* List::next(const Node *n) const {
  if(n == 0) return 0;
  return n->m_next;
}
void List::append (int i) {
  Node *n;
  for (n = m_first; next(n) != 0; n = next(n)); // get last node
  n->m_next = new Node(i);
}
void List::insert (Node *n, int i){
  Node *c;
  for (c = m_first; next(c) != n; n = next(c)); // get node before *n

  if(next(c) == n){
    c->m_next = new Node(i, n); // insert new node
  }
}
void List::erase (Node *n){
  Node * c;
  for (c = m_first; next(c) != n; n = next(c)); // get node before *n
  if(next(c) == n){
    c->m_next = n->m_next;
    n->m_next = 0;
    delete n;
  }
}


void List::print() const {
  std::cout << "List: ";
  for (Node *n = first(); n != 0; n = next(n))
    std::cout << "->" << n->value;
  std::cout << std::endl;
}
