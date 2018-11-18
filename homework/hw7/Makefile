CXX=g++
CXXFLAGS =-std=c++11 -Wall -Wextra -pedantic -g

all: CTreeTest TTreeTest

CTreeTest: CTreeTest.o CTree.o
	$(CXX) CTreeTest.o CTree.o -lm -o cTreeTest

TTreeTest: TTreeTest.cpp Tree.h
	$(CXX) TTreeTest.cpp Tree.h -lm -o tTreeTest 

CTreeTest.o: CTreeTest.cpp CTree.h
	$(CXX) $(CXXFLAGS) -c CTreeTest.cpp

CTree.o: CTree.cpp CTree.h
	$(CXX) $(CXXFLAGS) -c CTree.cpp


clean:
	rm *.o cTreeTest tTreeTest
