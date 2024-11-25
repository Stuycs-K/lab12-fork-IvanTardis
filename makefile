run: gogo
	@./gogo
compile gogo: main.o
	@gcc -o gogo main.o
main.o: main.c
	@gcc -c main.c
clean:
	@rm -rf *.o
	@rm -rf gogo
