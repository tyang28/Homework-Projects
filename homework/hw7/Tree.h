#ifndef _TREE_H
#define _TREE_H

#include <cstdlib>
#include <string>


// tree of characters, can be used to implement a trie                                                        
template<typename T>
class Tree {
  friend class TreeTest;


  T data;     // the value stored in the tree node                                                         

  Tree * kids;  // children - pointer to first child of list, maintain order & uniqueness                    

  Tree * sibs;  // siblings - pointer to rest of children list, maintain order & uniqueness                  
                 // this should always be null if the object is the root of a tree                            

  Tree * prev;  // pointer to parent if this is a first child, or left sibling otherwise                     
                 // this should always be null if the object is the root of a tree                            

 public:

  template<typename X>
  friend std::ostream& operator<<(std::ostream& os, Tree<X>& rt);
  Tree(T ch);

  ~Tree();  // clear siblings and children                                                                   

  //^ operator to do the same thing as addChild                                                               
  Tree<T>& operator^(Tree& rt);

  // siblings and children must be unique, return true if added, false otherwise                              
  bool addChild(T ch);

  // add tree root for better building, root should have null prev and sibs                                   
  // returns false on any type of failure, including invalid root                                             
  bool addChild(Tree<T> *root);

  std::string toString(); // all characters, separated by newlines, including at the end                      

  private:
  // these should only be called from addChild, and have the same restrictions                                
  // the root of a tree should never have any siblings                                                        
  // returns false on any type of failure, including invalid root                                             
  bool addSibling(T ch);
  bool operator==(Tree<T>& rt) const;
  bool operator>(Tree<T>& rt) const;
  bool operator<(Tree<T>& rt) const;
  bool addSibling(Tree<T> *root);

} ;
#include "Tree.inc"
#endif
