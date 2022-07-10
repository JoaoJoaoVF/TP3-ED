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
SAIDA = ./saidas/
OBJS = $(OBJ)/Execucao.o $(OBJ)/Simulador.o $(OBJ)/main.o $(OBJ)/memlog.o $(OBJ)/TADs.o
HDRS = $(INC)/memlog.hpp $(INC)/msgassert.hpp $(INC)/Execucao.hpp $(INC)/Simulador.hpp $(INC)/TADs.hpp 
CFLAGS = -pg -Wall -c -I$(INC) -std=c++11

EXE = $(BIN)/simulador.out

all: use

use: $(EXE)
#	$(EXE) -i "./entradas/entrada.txt" -o "./saidas/saida.txt"
#	$(EXE) -i "./entradas/entrada_1.txt" -o "./saidas/saida_1.txt"
#	$(EXE) -i "./entradas/entrada_2.txt" -o "./saidas/saida_2.txt"
#	$(EXE) -i "./entradas/entrada_3.txt" -o "./saidas/saida_3.txt"
	$(EXE) -i "./entradas/entrada_4.txt" -o "./saidas/saida_4.txt"

$(BIN)/simulador: $(OBJS)
	$(CC) -g -o $(BIN)/simulador $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/Execucao.o: $(HDRS) $(SRC)/Execucao.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/Execucao.o $(SRC)/Execucao.cpp 

$(OBJ)/Simulador.o: $(HDRS) $(SRC)/Simulador.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/Simulador.o $(SRC)/Simulador.cpp 

$(OBJ)/TADs.o: $(HDRS) $(SRC)/TADs.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/TADs.o $(SRC)/TADs.cpp 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.cpp

clean:
	rm -f $(EXE)* $(OBJS)* $(SAIDA)* $(BIN)* gmon.out
	clear 
