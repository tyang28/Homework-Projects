/**
 *HW7
 *Teng-Ju Yang tyang28
 */

#include <string>
#include <iostream>
#include "CTree.h"
#include <cstdlib>


using std::cin;
using std::string;
using std::endl;
using std::cout;

/*
CTree::CTree(char tch) : data(tch), kids(NULL), sibs(NULL), prev(NULL) {
  
}
*/

CTree::CTree(char tch) {
  this->data = tch;
  this->kids = nullptr; 
  this->sibs = nullptr;
  this->prev = nullptr;
}


bool CTree::findVal(char ch) {
  bool check = false;
  CTree *cur = this->kids;
  if(this->data == ch) {
      check = true;
      return check;
  }
  else if(cur != nullptr) {
    if(cur->data == ch) {
      check = true;
      return check;
    }
  }
  else {
    while(cur->sibs != nullptr) {
      if(cur->sibs->data == ch) {
	check = true;
	return check;
      }
      cur = cur->sibs;
    }
  }


  return check;
}


bool CTree::addChild(CTree *root) {
  bool check = false;
  if(root == nullptr) {
    return check;
  }
  
  if((root->prev != nullptr) || (root->sibs != nullptr)) {
    return check; 
  }
  if(findVal(root->data)) {
    return check;
  }
  if(addSibling(root)) {
    check = true;
    return check;
  }
 
  return check;
}




bool CTree::addSibling(CTree *root) {
  bool check = false;
  if(!findVal(root->data)) {
    CTree *nc = root;
    CTree *cur = this->kids;
    if(cur == nullptr) {
      cur = nc;
    }
    else if(cur != nullptr) {
      if(nc->data < cur->data) {
        nc->sibs = cur;
        nc->prev = nullptr;
        cur->prev = nc;
        check = true;
        return check;
      }
      else if(cur->data < nc->data) {
        while(cur->sibs != nullptr) {
          if(nc->data < cur->sibs->data) {
            nc->sibs = cur->sibs;
            nc->prev = cur;
            cur->sibs->prev = nc;
            cur->sibs = nc;
            check = true;
            return check;
          }
          cur = cur->sibs;
        }
        if(cur->sibs == nullptr){
          nc->sibs = nullptr;
          nc->prev = cur;
          cur->sibs = nc;
          check = true;
          return check;
        }
      }
    }
  }
  return check;
}

string CTree::toString() {
  string s;
  s += this->data;
  s += "\n";
  CTree *cur = this->kids;
  toString();
  cur = cur->sibs;
  toString();
  return s;
}

bool CTree::addChild(char ch) {
  bool check = false;
  if(!findVal(ch)) {
    CTree nc(ch);
    CTree *cur = this->kids;
    if(cur == nullptr) {
      cur = &nc;
    }
    else if(cur != nullptr) {
      if(nc.data < cur->data) {
	nc.sibs = cur;
	nc.prev = nullptr;
	cur->prev = &nc;
	check = true;
	return check;
      }
      else if(cur->data < nc.data) {
	while(cur->sibs != nullptr) {
	  if(nc.data < cur->sibs->data) {
	    nc.sibs = cur->sibs;
	    nc.prev = cur;
	    cur->sibs->prev = &nc;
	    cur->sibs = &nc;
	    check = true;
	    return check;
	  } 
	  cur = cur->sibs;
	}
	if(cur->sibs == nullptr){
	  nc.sibs = nullptr;
	  nc.prev = cur;
	  cur->sibs = &nc;
	  check = true;
	  return check;
	}	
      }
      
    }
  }

  return check;
}

CTree& CTree::operator^(CTree& rt) {
  addChild(&rt);  
  return rt;
}

CTree::~CTree() {
}




