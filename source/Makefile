
test3 : test3.o test2.o
	g++ -o test3 test3.o

test2.o : test2.cpp a6.h
	g++ -c test2.cpp 

test3.o : test3.cpp test2.cpp a6.h
	g++ -c  test3.cpp test2.cpp
	
clean :
	-rm test3.o test3.cpp
