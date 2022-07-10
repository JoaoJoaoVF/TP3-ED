#include "../include/Execucao.hpp"
#include "../include/TADs.hpp"

void Executa(char *arquivo_entrada, char *arquivo_saida)
{
    char Comando[10], aux[100];
    int M, U, E, N;

    // Realiza a abertura do Arquivo de Entrada
    FILE *entrada = fopen(arquivo_entrada, "r");
    // FILE *saida = fopen(arquivo_saida, "w");

    fscanf(entrada, "%d", &M);

    Hash_LE *server = new Hash_LE(M);

    Mensagem email;

    while (!feof(entrada))
    {
        email.arquivo_saida = arquivo_saida;
        fscanf(entrada, "%s", Comando);

        if (strcmp(Comando, "ENTREGA") == 0)
        {
            string MSG;

            fscanf(entrada, "%d %d %d\n", &U, &E, &N);

            for (int i = 0; i < N; i++)
            {
                fscanf(entrada, "%s", aux);

                MSG = MSG + aux + " ";
            }
            Entregar_email(server, email, U, MSG, M, E);
        }

        else if (strcmp(Comando, "CONSULTA") == 0)
        {
            fscanf(entrada, "%d %d\n", &U, &E);

            Consultar_email(server, email, U, M, E);
        }
        else if (strcmp(Comando, "APAGA") == 0)
        {
            fscanf(entrada, "%d %d\n", &U, &E);

            Apagar_email(server, email, U, M, E);
        }
    }

    fclose(entrada);
    delete[] server;
}
