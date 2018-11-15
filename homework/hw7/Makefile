CXX=g++
CXXFLAGS =-std=c++11 -Wall -Wextra -pedantic -g

CTreeTest: CTreeTest.o CTree.o
	$(CXX) CTreeTest.o CTree.o -lm -o cTreeTest

CTreeTest.o: CTreeTest.cpp CTree.h
	$(CXX) $(CXXFLAGS) -c CTreeTest.cpp

CTree.o: CTree.cpp CTree.h
	$(CXX) $(CXXFLAGS) -c CTree.cpp

clean:
	rm *.o cTreeTest
