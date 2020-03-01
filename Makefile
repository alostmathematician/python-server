scanner:main.o hash_map.o lexer.o general.o token_string.o
	gcc -g -o scanner main.o hash_map.o lexer.o general.o token_string.o 

main.o:main.c
	gcc -c main.c

hash_map.o:./src/hash_map.c
	gcc -c ./src/hash_map.c

lexer.o: ./src/lexer.c
	gcc -c ./src/lexer.c

general.o: ./src/general.c
	gcc -c ./src/general.c

token_string.o: ./src/token_string.c
	gcc -c ./src/token_string.c

	
.PHONY:clean
clean:
	rm *.o