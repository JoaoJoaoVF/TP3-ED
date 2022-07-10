//---------------------------------------------------------------------
// Arquivo      : Simulador.cpp
// Conteudo     : Arquivo que implementa as operações realizadas no servidor
// Autor        : Joao Vitor Ferreira (ferreirajoao@dcc.ufmg.br)
//---------------------------------------------------------------------

#include "Simulador.hpp"

using namespace std;

void Entregar_email(Hash_AB *server, Mensagem email, int U, string conteudo, int M, int E)
{
    // Descricao: Inicializa os atributos do email para serem adicionados na tabela.
    // Entrada: Caminhos para a tabela Hash e email, e as variaveis que contem os dados do No.
    // Saida: Não possui.

    email.SetIdMensagem(E);
    email.SetConteudo(conteudo);
    email.SetIdDestinatario(U);

    server->Insere(email, M);
}

void Consultar_email(Hash_AB *server, Mensagem email, int U, int M, int E)
{
    // Descricao: Inicializa os atributos do email a serem procurados na tabela, e armazena a saida da pesquisa numa mensagem auxiliar.
    // Entrada: Caminhos para a tabela Hash e email, e as variaveis que contem os dados.
    // Saida: Não possui.

    Mensagem resposta;
    email.SetIdMensagem(E);
    email.SetIdDestinatario(U);

    resposta = server->Pesquisa(email, M, 1);
}

void Apagar_email(Hash_AB *server, Mensagem email, int U, int M, int E)
{
    // Descricao: Inicializa os atributos do email para serem removidos da arvore.
    // Entrada: Caminhos para a tabela Hash e email, e as variaveis que contem os dados.
    // Saida: Não possui.

    email.SetIdMensagem(E);
    email.SetIdDestinatario(U);

    server->Remove(email, M);
}