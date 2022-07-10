//---------------------------------------------------------------------
// Arquivo      : Simulador.hpp
// Conteudo     : Arquivo que cabeçalho as operações realizadas no servidor
// Autor        : Joao Vitor Ferreira (ferreirajoao@dcc.ufmg.br)
//---------------------------------------------------------------------

#ifndef SIMULADOR
#define SIMULADOR

#include "TADs.hpp"

using namespace std;

void Entregar_email(Hash_AB *server, Mensagem email, int U, string conteudo, int M, int E);
void Consultar_email(Hash_AB *server, Mensagem email, int U, int M, int E);
void Apagar_email(Hash_AB *server, Mensagem email, int U, int M, int E);

#endif