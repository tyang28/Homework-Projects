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

/*
CTree::CTree(char tch) : data(tch), kids(NULL), sibs(NULL), prev(NULL) {
  
}
*/

CTree::CTree(char tch) {
  data = tch;
  kids = nullptr; 
  sibs = nullptr;
  prev = nullptr;
}


bool CTree::findVal(char ch) {
  
  bool check = false;
  
  CTree *cur = sibs;
  if(data == ch) {
      check = true;
      return check;
  }
  else if(kids != nullptr) {
    if(kids->data == ch) {
      check = true;
      return check;
    }
  }
  else {
    while(cur != nullptr) {
      if(cur->data == ch) {
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
  
  if(checkRoot(root)) {  
    CTree *nc = root;
    CTree *cur = sibs;
    if(kids == nullptr) {
      kids = nc;
      check = true;
      printf("11\n");
      return check;
    }
    else if(kids != nullptr) {  
      if(nc->data < kids->data) {
        nc->sibs = kids;
        kids->prev = nc;
        check = true;
        return check;
      }
      else if(kids->data < nc->data) {
	printf("3\n");
        while(cur != nullptr) {
          if(nc->data < cur->data) {
            nc->sibs = cur;
            nc->prev = cur->prev;
	    cur->prev->sibs = nc;
            cur->prev = nc;
            check = true;
            return check;
          }
          cur = cur->sibs;
        }
        if(cur == nullptr){
	  printf("4\n");
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

bool CTree::checkRoot(CTree *root) {
  bool check = true;
  if(root == nullptr) {
    cout << "1" << endl;
    check = false;
    return check;
  }
  else if((root->prev != nullptr) || (root->sibs != nullptr)) {
    cout << "2" << endl;
    check = false;
    return check;
  }
  else if(findVal(root->data)) {
    cout << "3" << endl;
    check = false;
    return check;
  }

  return check;
}

bool CTree::addSibling(CTree *root) {
  
  bool check = false;
  /*
  if(findVal(root->data)) {
    return check;
  }
  else {
    CTree *nc = root;
    CTree *cur = sibs;
    if(cur == nullptr) {
      cur = nc;
    }
    else if(cur != nullptr) {
      if(nc->data < cur->data) {
        nc->sibs = cur;
        nc->prev = kids;
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
  */
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
  bool check = false;
  
  if(findVal(ch)) {
    return check;
  }
  else if(!findVal(ch)) {
    CTree nc(ch);
    addChild(&nc);
    check = true;


    /*
    if(addChild(&nc)) {
      check = true;
      return check;
    }
    */
    
    /*
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
    */
  }

  return check;
}

CTree& CTree::operator^(CTree& rt) {
  addChild(&rt);  
  return rt;
}

CTree::~CTree() {
}




