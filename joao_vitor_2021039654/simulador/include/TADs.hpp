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

class Mensagem
{
public:
    Mensagem();
    Mensagem(int id_mensagem, string msg_conteudo);
    void SetIdMensagem(int _id_mensagem);
    int GetIdMensagem();
    void SetIdDestinatario(int _id_destinatario);
    int GetIdDestinatario();
    void SetConteudo(string _msg_conteudo);
    string GetConteudo();
    void Imprime();
    bool Vazio();

    int id_mensagem;
    int id_destinatario;
    string conteudo;
};

class TipoNo
{
public:
    TipoNo();

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
    Mensagem Pesquisa(int id_mensagem);
    void Remove(int id_mensagem);

    void InsereRecursivo(TipoNo *&p, Mensagem dados);
    void ApagaRecursivo(TipoNo *p);
    Mensagem PesquisaRecursivo(TipoNo *p, int id_mensagem);
    void RemoveRecursivo(TipoNo *&p, int id_mensagem);
    void Antecessor(TipoNo *q, TipoNo *&r);
    void PreOrdem(TipoNo *p);
    void InOrdem(TipoNo *p);
    void PosOrdem(TipoNo *p);
    TipoNo *raiz;
};

class Hash_LE
{
public:
    Hash_LE(int M);
    // Hash_LE(int M);
    Mensagem Pesquisa(Mensagem dados, int M, int Tipo);
    void Insere(Mensagem dados, int M);
    void Remove(Mensagem dados, int M);

    // static const int M = 50;
    int Hash(int id_mensagem, int M);
    ArvoreBinaria *Tabela;
};

#endif