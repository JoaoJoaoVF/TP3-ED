#ifndef TADs_HPP
#define TADs_HPP

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include "../include/memlog.hpp"
#include "../include/msgassert.hpp"
using namespace std;

// typedef int TipoChave; // TipoChave é um inteiro

class Mensagem
{
public:
    Mensagem();
    Mensagem(int msg_id, string msg_conteudo);
    void SetId();
    void SetId(int msg_id);
    int GetId();
    void SetConteudo(string msg_conteudo);
    string GetConteudo();
    void Imprime();
    bool Vazio();

    // TipoChave chave;
    // outros membros
    int id;
    string conteudo;
};

class TipoNo
{
public:
    TipoNo();

private:
    Mensagem dados;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(Mensagem dados);
    void Caminha(int tipo);
    void Limpa();
    Mensagem Pesquisa(int id);
    void Remove(int id);

private:
    void InsereRecursivo(TipoNo *&p, Mensagem dados);
    void ApagaRecursivo(TipoNo *p);
    Mensagem PesquisaRecursivo(TipoNo *p, int id_procurado);
    void RemoveRecursivo(TipoNo *&p, int id_procurado);
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
    // Hash_LE(int M);
    Mensagem Pesquisa(Mensagem dados, int M);
    void Insere(Mensagem dados, int M);
    void Remove(Mensagem dados, int M);

    static const int M = 50;
    int Hash(int id, int M);
    ArvoreBinaria Tabela[M];
};

#endif