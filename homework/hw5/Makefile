CXX=g++
CXXFLAGS =-std=c++11 -Wall -Wextra -pedantic -g

digraphAnalyzer: digraphAnalyzer.o functions.o
	$(CXX) digraphAnalyzer.o functions.o -lm -o digraphAnalyzer

digraphAnalyzer.o: digraphAnalyzer.cpp functions.h
	$(CXX) $(CFLAGS) -c digraphAnalyzer.cpp

functions.o: functions.cpp functions.h
	$(CXX) $(CXXFLAGS) -c functions.cpp

clean:
	rm *.o digraphAnalyzer
