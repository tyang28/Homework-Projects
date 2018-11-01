CXX=g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 -g

digraphAnalyzer: digraphAnalyzer.o functions.o
	$(CXX) -o digraphAnalyzer digraphAnalyzer.o functions.o

digraphAnalyzer.o: digraphAnalyzer.cpp functions.h
	$(CXX) $(CFLAGS) -c digraphAnalyzer.cpp

functions.o: functions.cpp functions.h
	$(CXX) $(CXXFLAGS) -c functions.cpp

clean:
	rm *.o digraphAnalyzer
