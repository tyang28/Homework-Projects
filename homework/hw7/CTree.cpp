/**
 *HW7
 *Teng-Ju Yang tyang28
 */

#include <string>
#include <iostream>
#include "CTree.h"
#include <cstdlib>
#include <sstream>

using std::cin;
using std::string;
using std::endl;
using std::cout;


CTree::CTree(char tch) : data(tch), kids(nullptr), sibs(nullptr), prev(nullptr) {
}

bool CTree::addChild(CTree *root) {
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


bool CTree::addSibling(CTree *root) {

  bool check = false;
  
  if((root->prev != nullptr) || (root->sibs != nullptr)) {
    delete root;
    return check;
  }
  if(prev == nullptr && sibs == nullptr) {
    delete root;
    return false;
  }
  CTree *cur = this;
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

string CTree::toString() {
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

bool CTree::addChild(char ch) {
  if(kids == nullptr) {
    CTree *nc = new CTree(ch);
    kids = nc;
    nc->prev = this;
    return true;
  }
  else {
    return kids->addSibling(ch);
  }
}


bool CTree::addSibling(char ch) {
  CTree *nc = new CTree(ch);
  
  return addSibling(nc);
}


CTree& CTree::operator^(CTree& rt) {
  addChild(&rt);  

  return *this;
}


CTree::~CTree() {
  if(kids) {
    delete kids;
  }
  if(sibs) {
    delete sibs;
  }
}

std::ostream& operator<<(std::ostream& os, CTree& rt) {
  os << rt.toString();
  return os;
}


