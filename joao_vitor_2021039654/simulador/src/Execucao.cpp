#include "../include/Execucao.hpp"
#include "../include/TADs.hpp"

void Executa(char *arquivo_entrada, char *arquivo_saida)
{
    char Comando[10], aux[100];
    int M, U, E, N;

    // cout << arquivo_entrada << endl;

    // Realiza a abertura do Arquivo de Entrada
    FILE *entrada = fopen(arquivo_entrada, "r");

    fscanf(entrada, "%d", &M);

    // cout << M << endl;

    Hash_LE *server = new Hash_LE(M);

    Mensagem email;

    while (!feof(entrada))
    {
        fscanf(entrada, "%s", Comando);

        if (strcmp(Comando, "ENTREGA") == 0)
        {
            string MSG;
            // cout << Comando << endl;
            fscanf(entrada, "%d %d %d", &U, &E, &N);
            // cout << U << " " << E << " " << N << endl;

            for (int i = 0; i < N; i++)
            {
                fscanf(entrada, "%s", aux);
                MSG = MSG + aux + " ";
            }
            // cout << MSG << endl;
            Entregar_email(server, email, U, MSG, M, E);
        }

        else if (strcmp(Comando, "CONSULTA") == 0)
        {
            // cout << Comando << endl;
            fscanf(entrada, "%d %d", &U, &E);
            // cout << U << " " << E << endl;

            Consultar_email(server, email, U, M, E);
        }
        else if (strcmp(Comando, "APAGA") == 0)
        {
            // cout << Comando << endl;
            fscanf(entrada, "%d %d", &U, &E);
            // cout << U << " " << E << endl;
            Apagar_email(server, U, M, E);
        }
    }

    // cout << arquivo_saida << endl;
    fclose(entrada);
    delete[] server;
}
