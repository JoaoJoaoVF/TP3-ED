//---------------------------------------------------------------------
// Arquivo      : Execucao.cpp
// Conteudo     : Arquivo de Execução das operações realizadas no email
// Autor        : Joao Vitor Ferreira (ferreirajoao@dcc.ufmg.br)
//---------------------------------------------------------------------

#include "../include/Execucao.hpp"
#include "../include/TADs.hpp"

void Executa(char *arquivo_entrada, char *arquivo_saida)
{
    // Inicialização de variaveis que armazenaram os Comandos e as Palavras
    char Comando[10], Palavra[100];

    // Variaveis que representam o tamanho da tabela Hash(M), o destinatário(U), o identificador do
    // email(E) e o número de palavras da mensagem(N)
    int M, U, E, N;

    // Realiza a abertura do Arquivo de Entrada
    FILE *entrada = fopen(arquivo_entrada, "r");

    // Leitura do tamanho da tabela Hash
    fscanf(entrada, "%d", &M);

    // Inicia a tabela Hash com o tamanho M e inicializa a classe da mensagem do email
    Hash_LE *server = new Hash_LE(M);
    Mensagem email;

    // adiciona a mensagem o nome do arquivo de saida
    email.arquivo_saida = arquivo_saida;

    // Loop para realizar a leitura total do arquivo
    while (!feof(entrada))
    {
        // Leitura dos comandos
        fscanf(entrada, "%s", Comando);

        // No caso de ser ENTREGA, cria uma string para a mensagem, realiza a leitura dos parametros U, E,
        //  N e atraves de um loop adiciona essas palaveas a MSG, depois realiza a chamada da função de Entrega do Email
        if (strcmp(Comando, "ENTREGA") == 0)
        {
            string MSG;

            fscanf(entrada, "%d %d %d\n", &U, &E, &N);

            for (int i = 0; i < N; i++)
            {
                fscanf(entrada, "%s", Palavra);

                MSG = MSG + Palavra + " ";
            }
            Entregar_email(server, email, U, MSG, M, E);
        }
        // No caso de ser CONSULTA, realiza a leitura dos parametros U, E,
        //   depois realiza a chamada da função de Consultar o Email
        else if (strcmp(Comando, "CONSULTA") == 0)
        {
            fscanf(entrada, "%d %d\n", &U, &E);

            Consultar_email(server, email, U, M, E);
        }
        // No caso de ser APAGA, realiza a leitura dos parametros U, E,
        //   depois realiza a chamada da função de Apagar o Email
        else if (strcmp(Comando, "APAGA") == 0)
        {
            fscanf(entrada, "%d %d\n", &U, &E);

            Apagar_email(server, email, U, M, E);
        }
    }

    // Fechamento do arquivo de entrada e apaga a tabela Hash
    fclose(entrada);
    delete[] server;
}
