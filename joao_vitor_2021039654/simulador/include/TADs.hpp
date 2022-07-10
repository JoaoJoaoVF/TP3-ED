//---------------------------------------------------------------------
// Arquivo      : TADs.hpp
// Conteudo     : Arquivo de cabeçalho dos Tipos Abstratos de Dados
// Autor        : Joao Vitor Ferreira (ferreirajoao@dcc.ufmg.br)
//---------------------------------------------------------------------

#ifndef TADs
#define TADs

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "../include/memlog.hpp"
#include "../include/msgassert.hpp"

using namespace std;

class Mensagem
{
public:
    Mensagem();
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
    string arquivo_saida;
};

class TipoNo
{
public:
    TipoNo();

private:
    Mensagem email;
    TipoNo *esq;
    TipoNo *dir;
    friend class ArvoreBinaria;
};

class ArvoreBinaria
{
public:
    ArvoreBinaria();
    ~ArvoreBinaria();
    void Insere(Mensagem email);
    void Caminha(int tipo);
    void Limpa();
    Mensagem Pesquisa(int id_mensagem);
    void Remove(int id_mensagem);

private:
    void InsereRecursivo(TipoNo *&p, Mensagem email);
    void ApagaRecursivo(TipoNo *p);
    Mensagem PesquisaRecursivo(TipoNo *p, int id_mensagem);
    void RemoveRecursivo(TipoNo *&p, int id_mensagem);
    void Antecessor(TipoNo *q, TipoNo *&r);
    TipoNo *raiz;
};

class Hash_LE
{
public:
    Hash_LE(int M);
    Mensagem Pesquisa(Mensagem email, int M, int Tipo);
    void Insere(Mensagem email, int M);
    void Remove(Mensagem email, int M);

private:
    int Hash(int id_mensagem, int M);
    ArvoreBinaria *Tabela;
};

#endif