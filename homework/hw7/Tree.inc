/**
 *HW7
 *Teng-Ju Yang tyang28
 */

#include <string>
#include <iostream>
#include "Tree.h"
#include <cstdlib>
#include <sstream>

using std::cin;
using std::string;
using std::endl;
using std::cout;

template<typename T>
Tree<T>::Tree(T tch) : data(tch), kids(nullptr), sibs(nullptr), prev(nullptr) {
}

template<typename T>
bool Tree<T>::addChild(Tree<T> *root) {
  bool check = false;
  if(kids == nullptr) {
    kids = root;
    kids->prev = this;
    check = true;
    return check;
  }
  else {
    return kids->addSibling(root);
  }
}

template<typename T>
bool Tree<T>::addSibling(Tree<T> *root) {

  bool check = false;
  
  if((root->prev != nullptr) || (root->sibs != nullptr)) {
    delete root;
    return check;
  }
  if(prev == nullptr && sibs == nullptr) {
    delete root;
    return false;
  }
  Tree *cur = this;
  if(sibs == nullptr) {
    
    if(data == root->data) {
      delete root;
      return check;
    }
    sibs = root;
    sibs->prev = this;
  }
  else {
    if(root->data < cur->data) {
      root->sibs = this;
      root->prev = prev;
      prev->kids = root;
      prev = root;
      check = true;
      return check;
    }
    while(cur->sibs != nullptr) {
      if(cur->data == root->data) {
	delete root;
	return check;
      }
      if(root->data < cur->data) {
	root->sibs = cur;
	root->prev = cur->prev;
	cur->prev->sibs = root;
	cur->prev = root;
	check = true;
	return check;
      }
      cur = cur->sibs;
    }
    if(cur->data == root->data) {
      delete root;
      return check;
    }
    if(root->data < cur->data) {
      root->sibs = cur;
      root->prev = cur->prev;
      cur->prev->sibs = root;
      cur->prev = root;
      check = true;
      return check;
    }
    cur->sibs = root;
    cur->sibs->prev = cur;
  }
  check = true;
  return check;
}

template<typename T>
string Tree<T>::toString() {
  std::stringstream ss;
  ss << data << endl;
  if(kids != nullptr) {
    ss << kids->toString();
  }
  if(sibs != nullptr) {
    ss << sibs->toString();
  }
  return ss.str();
}

template<typename T>
bool Tree<T>::addChild(T ch) {
  if(kids == nullptr) {
    Tree *nc = new Tree(ch);
    kids = nc;
    nc->prev = this;
    return true;
  }
  else {
    return kids->addSibling(ch);
  }
}

template<typename T>
bool Tree<T>::addSibling(T ch) {
  Tree *nc = new Tree(ch);
  
  return addSibling(nc);
}

template<typename T>
Tree<T>& Tree<T>::operator^(Tree<T>& rt) {
  addChild(&rt);  

  return *this;
}

template<typename T>
Tree<T>::~Tree() {
  if(kids) {
    delete kids;
  }
  if(sibs) {
    delete sibs;
  }
}

template<typename X>
std::ostream& operator<<(std::ostream& os, Tree<X>& rt) {
  os << rt.toString();
  return os;
}

template<typename T>
bool Tree<T>::operator>(Tree<T>& rt) const{
  return this.data.compare(rt.data);
}

template<typename T>
bool Tree<T>::operator==(Tree<T>& rt) const{
  if(this.data.compare(rt.data) == 0) {
    return true;
  }
}



template<typename T>
bool Tree<T>::operator<(Tree<T>& rt) const{
  return !this.data.compare(rt.data);
}