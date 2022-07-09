#ifndef SIMULADOR_HPP
#define SIMULADOR_HPP

#include "TADs.hpp"

using namespace std;

void Entregar_email(Hash_LE *server, Mensagem dados, int _id, string _conteudo);
void Consultar_email();
void Apagar_email();

#endif