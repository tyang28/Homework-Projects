#include "Tree.h"
#include <string>
#include <cassert>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;


class TreeTest {
public:

  // test constructor of a template Tree for different types
  static void constructorTest() {
    // build a few trees with constructor
    // Tree of char
    Tree<char>* t1 = new Tree<char>('A');
    assert(t1->toString() == "A\n");
    // Tree of int
    Tree<int>* t2 = new Tree<int>(32);
    assert(t2->toString() == "32\n");
    // Tree of short
    Tree<short>* t3 = new Tree<short>(255);
    assert(t3->toString() == "255\n");
    delete t1;
    delete t2;
    delete t3;
  }

  // test addChild and addSibling for templated Tree with type argument int
  static void addsTest() {
    // 1   
    Tree<int>* t1 = new Tree<int>(1);

    assert(t1->toString() == "1\n");

    // 1
    // |
    // 7
    assert(t1->addChild(7));
    assert(t1->toString() == "1\n7\n");
    // can't add again
    assert(!t1->addChild(7));
    assert(t1->toString() == "1\n7\n");
      
    // 1
    // |
    // 4 - 5
    assert(t1->addChild(8));
    assert(t1->toString() == "1\n7\n8\n");
    // can't add again
    assert(!t1->addChild(8));
    assert(t1->toString() == "1\n7\n8\n");

    // 1
    // |
    // 3 - 4 - 5
    assert(t1->addChild(6));
    // 2 comes before 3
    assert(t1->toString() == "1\n6\n7\n8\n");
    // can't add repeats
    assert(!t1->addChild(6));
    assert(!t1->addChild(7));
    assert(!t1->addChild(8));
    assert(t1->toString() == "1\n6\n7\n8\n");

    // can't add 1 as sibling of 1
    assert(!t1->addSibling(1));
    assert(t1->toString() == "1\n6\n7\n8\n");

    // make sure that we can't add siblings to the root
    assert(!t1->addSibling(1));
    assert(t1->toString() == "1\n6\n7\n8\n");

    // Adding a subTree
    // First build another tree
    // 2
    Tree<int>* t2 = new Tree<int>(2);
     
    assert(t2->toString() == "2\n");
        
    // 2
    // |
    // 4
    assert(t2->addChild(4));
    assert(t2->toString() == "2\n4\n");


    // 2
    // |
    // 4 - 5
    assert(t2->addChild(5));
    assert(t2->toString() == "2\n4\n5\n");
    // can't repeat
    assert(!t2->addChild(5));
    assert(t2->toString() == "2\n4\n5\n");

    // 2
    // |
    // 6 - 7 - 8
    assert(t2->addChild(3));
    assert(t2->toString() == "2\n3\n4\n5\n");
    // can't repeat
    assert(!t2->addChild(3));
    assert(t2->toString() == "2\n3\n4\n5\n");

    // Add t2 in as a child
    // 1
    // |
    // 2 - 6 - 7 - 8
    // |
    // 3 - 4 - 5

    // t1 is as before
    assert(t1->toString() == "1\n6\n7\n8\n");
    // add t1 to t2
    assert(t1->addChild(t2));
    // t1 should now include all numbers 1 through 8
    assert(t1->toString() == "1\n2\n3\n4\n5\n6\n7\n8\n");
    // t2 should be updated to have siblings
    assert(t2->toString() == "2\n3\n4\n5\n6\n7\n8\n");
    delete t1;
  }
  // test ^ operator for a template Tree
  static void testCaretOp() {
    // 1
    // |
    // 2 - 3
    Tree<int>* t1 = new Tree<int>(1);
    assert(t1->addChild(2));
    assert(t1->addChild(3));

    // 4
    // |
    // 5 - 6
    Tree<int>* t2 = new Tree<int>(4);
    assert(t2->addChild(5));
    assert(t2->addChild(6));
    // 1
    // |
    // 2 - 3 - 4
    //         |
    //         5 - 6   
    *t1 = *t1 ^ *t2;
    assert(t1->toString() == "1\n2\n3\n4\n5\n6\n");
    assert(t2->toString() == "4\n5\n6\n");
    delete t1;
  }

  // test << operator for a template Tree
  static void testOutputOp() {
    // 1
    // |
    // 2 - 3 - 4 - 5 - 6 
    Tree<int>* t1 = new Tree<int>(1);
    assert(t1->addChild(2));
    assert(t1->addChild(3));
    assert(t1->addChild(4));
    assert(t1->addChild(5));
    assert(t1->addChild(6));

    std::ostringstream o;
    o << *t1;
    assert(o.str() == t1->toString());
    delete t1;
  }
  
  // test adding a single child for template Tree
  static void addSimpleChildTest() {
    // ali 
    Tree<string>* t1 = new Tree<string>("ali");
    assert(t1->toString() == "ali\n");

    // ali
    Tree<string>* t2 = new Tree<string>("ali");
    assert(t2->toString() == "ali\n");

    // ali
    // |
    // ali
    assert(t2->addChild(t1));
    assert(t2->toString() == "ali\nali\n");
    assert(t1->toString() == "ali\n");
    delete t2;
  }

  
};



int main(void) {
    cout << "Testing Tree" << endl;
    TreeTest::constructorTest();
    TreeTest::addsTest();
    TreeTest::addSimpleChildTest();
    TreeTest::testCaretOp();
    TreeTest::testOutputOp();
    cout << "Tree tests passed" << endl;
}
