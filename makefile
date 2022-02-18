CC=clang
CFLAGS=-Wall 

solution:
	$(CC) $(CFLAGS) solution.c -o solution

clean:
	rm ./solution
