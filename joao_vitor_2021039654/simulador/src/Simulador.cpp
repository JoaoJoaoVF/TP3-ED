#include "Simulador.hpp"

using namespace std;

void Entregar_email(Hash_LE *server, Mensagem email, int U, string _conteudo, int M, int E)
{

    // cout << U << " " << M << " " << E << endl;

    email.SetIdMensagem(E);
    email.SetConteudo(_conteudo);
    email.SetIdDestinatario(U);
    // email.Imprime();

    server->Insere(email, M);
}

void Consultar_email(Hash_LE *server, Mensagem dados, int U, int M, int E)
{
    Mensagem resposta;
    dados.SetIdMensagem(E);
    dados.SetIdDestinatario(U);

    resposta = server->Pesquisa(dados, M);
    // cout << resposta.id_mensagem << endl;

    if (resposta.id_mensagem == -1)
    {
        cout << "CONSULTA " << resposta.GetIdDestinatario() << "  " << resposta.GetIdMensagem() << ": MENSAGEM INEXISTENTE " << endl;
    }
    else
    {
        cout << "CONSULTA " << resposta.GetIdDestinatario() << " " << resposta.GetIdMensagem() << ": " << resposta.conteudo << endl;
    }
}

void Apagar_email(Hash_LE *server, int U, int M, int E)
{
    Mensagem busca;
    busca.SetIdMensagem(E);
    busca.SetIdDestinatario(U);
    server->Remove(busca, M);
}