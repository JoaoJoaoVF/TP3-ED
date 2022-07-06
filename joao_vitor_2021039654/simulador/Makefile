#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa Poker
# Autor		: Joao Vitor Ferreira (ferreirajoao@dcc.ufmg.br)
# Histórico	: 2022-06-30 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm 
SRC = src
OBJ = ./obj/
INC = ./include/
BIN = ./bin/
SAIDA = ./saida/
OBJS = $(OBJ)/Execucao.o $(OBJ)/Simulador.o $(OBJ)/main.o $(OBJ)/memlog.o
HDRS = $(INC)/memlog.hpp $(INC)/msgassert.hpp $(INC)/Execucao.hpp $(INC)/Simulador.hpp
CFLAGS = -pg -Wall -c -I$(INC) 

EXE = $(BIN)/simulador.out

all: use

use: $(EXE)
	$(EXE) -i entrada.txt -o saida.txt

$(BIN)/simulador: $(OBJS)
	$(CC) -g -o $(BIN)/simulador $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/Execucao.o: $(HDRS) $(SRC)/Execucao.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/Execucao.o $(SRC)/Execucao.cpp 

$(OBJ)/Simulador.o: $(HDRS) $(SRC)/Simulador.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/Simulador.o $(SRC)/Simulador.cpp 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp

clean:
	rm -f $(EXE)* $(OBJS)* $(SAIDA)* $(BIN)* gmon.out
	clear 
