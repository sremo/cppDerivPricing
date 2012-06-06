all: SimpleMCMain

SimpleMCMain: SimpleMCMain.o Random.o
	g++ SimpleMCMain.o Random.o -o SimpleMCMain

SimpleMCMain.o: SimpleMCMain.cpp
	g++ -c SimpleMCMain.cpp

Random.o: Random.cpp
	g++ -c Random.cpp

clean:
	rm -rf *o
