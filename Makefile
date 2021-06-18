### ----------> Makefile <---------- ###
CC=gcc						#compilador utilizado
CFLAGS=-g -lm -Wall -Wextra -Wshadow -Wstrict-prototypes -Wswitch-default -Wswitch-enum -Wunreachable-code -ftrapv -Wcast-align -Wcast-qual -Wmissing-prototypes -fmessage-length=0 -std=c99 -Wwrite-strings -Winit-self -Wstrict-aliasing -Wformat=2 -Wmissing-declarations -Wmissing-include-dirs -Wno-unused-parameter -Wuninitialized -Wold-style-definition   #Flags para warning do programa
SRC= $(wildcard *.c)   	    #cada arquivo .c que sera usado no programa final
OBJ= $(SRC:.c=.o)           #Cada arquivo  .o que sera usado para compilar,no caso ja esta definido pelo SRC
EXEC=lab5				#nome do arquivo executavel gerado
all: $(EXEC)
	@echo "Comecando a compilacao!"
lab5: $(OBJ)
	
	$(CC) -o $@ $^
	# teste.o:teste.c
%.o: %.c
	#condicoes = todos os arquivos .c
	#gera todos os .o
	# $^ = interprete como todas as condicoes da regra
	# $< =  nome da primeira dependencia , no caso %.c
	# $@ = nome do comando , no caso %.o
	$(CC) -o $@ -c $< $(CFLAGS)
.PHONY: clean mrproper
clean:
	#limpa todos os .o temporarios criados
	rm -rf *.o
	@echo "Objetos deletados com sucesso!"
run: $(EXEC)
	@echo "Executando o programa!"
	./$(EXEC)
valgrind: $(EXEC)
	valgrind -v ./$(EXEC)
