#include "Simulador.hpp"

using namespace std;

void Entregar_email(Hash_LE *server, Mensagem email, int U, string _conteudo, int M, int E)
{

    email.SetIdMensagem(E);
    email.SetConteudo(_conteudo);
    email.SetIdDestinatario(U);

    server->Insere(email, M);

    // cout << email.arquivo_saida << endl;
}

void Consultar_email(Hash_LE *server, Mensagem email, int U, int M, int E)
{
    Mensagem resposta;
    email.SetIdMensagem(E);
    email.SetIdDestinatario(U);

    resposta = server->Pesquisa(email, M, 1);

    // cout << email.arquivo_saida << endl;
}

void Apagar_email(Hash_LE *server, Mensagem email, int U, int M, int E)
{
    email.SetIdMensagem(E);
    email.SetIdDestinatario(U);
    server->Remove(email, M);

    // cout << email.arquivo_saida << endl;
}