#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include "TADs.hpp"

using namespace std;

void Entregar_email(Hash_LE *server, Mensagem dados, int U, string _conteudo, int M, int E);
void Consultar_email(Hash_LE *server, Mensagem dados, int U, int M, int E);
void Apagar_email(Hash_LE *server, Mensagem dados, int U, int M, int E);

#endif