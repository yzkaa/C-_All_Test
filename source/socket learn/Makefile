vpath %.c source
vpath %.h head
test : server1.o error.o package.o
	gcc -o test error.o package.o server1.o
server1.o : server1.c package.h
	gcc -c $< -Ihead
package.o : package.c package.h
	gcc -c $< -Ihead
error.o : error.c error.h
	gcc -c $< -Ihead
clean :
	-rm test server1.o package.o error.o
