#include "Simulador.hpp"

using namespace std;

void Entregar_email(Hash_LE *server, Mensagem email, int U, string _conteudo, int M, int E)
{

    email.SetIdMensagem(E);
    email.SetConteudo(_conteudo);
    email.SetIdDestinatario(U);

    server->Insere(email, M);
}

void Consultar_email(Hash_LE *server, Mensagem dados, int U, int M, int E)
{
    Mensagem resposta;
    dados.SetIdMensagem(E);
    dados.SetIdDestinatario(U);

    resposta = server->Pesquisa(dados, M, 1);
}

void Apagar_email(Hash_LE *server, int U, int M, int E)
{
    Mensagem busca;
    busca.SetIdMensagem(E);
    busca.SetIdDestinatario(U);
    server->Remove(busca, M);
}