.PHONY: clean compile run
run: fork
		@./fork
compile fork: fork.o
	@gcc -o fork fork.o
fork.o: fork.c
	@gcc -c fork.c
clean:
	rm -f *o fork
