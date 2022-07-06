#ifndef TADs_HPP
#define TADs_HPP

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include "memlog.hpp"
#include "msgassert.hpp"
using namespace std;

typedef int TipoChave; // TipoChave é um inteiro

class TipoItem
{
public:
    TipoItem();
    TipoItem(TipoChave c);
    void SetChave(TipoChave c);
    TipoChave GetChave();
    void Imprime();
    bool Vazio();

private:
    TipoChave chave;
    // outros membros
};

class TipoNo
{
public:
    TipoNo();

private:
    TipoItem item;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(TipoItem item);
    void Caminha(int tipo);
    void Limpa();
    TipoItem Pesquisa(TipoChave chave);
    void Remove(TipoChave chave);

private:
    void InsereRecursivo(TipoNo *&p, TipoItem item);
    void ApagaRecursivo(TipoNo *p);
    TipoItem PesquisaRecursivo(TipoNo *p, TipoChave chave);
    void RemoveRecursivo(TipoNo *&p, TipoChave chave);
    void Antecessor(TipoNo *q, TipoNo *&r);
    void PorNivel();
    void PreOrdem(TipoNo *p);
    void InOrdem(TipoNo *p);
    void PosOrdem(TipoNo *p);
    TipoNo *raiz;
};

class Hash_LE
{
public:
    Hash_LE();
    TipoItem Pesquisa(TipoChave chave);
    void Insere(TipoItem item);
    void Remove(TipoChave chave);

private:
    static const int M = 7;
    int Hash(TipoChave Chave);
    ArvoreBinaria Tabela[M];
};

#endif