#include "../include/Execucao.hpp"
#include "../include/TADs.hpp"

void Executa(char *arquivo_entrada, char *arquivo_saida)
{
    char Comando[10], aux[100];
    int M, U, E, N;
    string MSG;
    Hash_LE server;
    Mensagem email;
    // ArvoreBinaria arv;

    // TipoItem dado;
    cout << arquivo_entrada << endl;

    FILE *entrada = fopen(arquivo_entrada, "r");

    fscanf(entrada, "%d", &M);

    cout << M << endl;

    while (!feof(entrada))
    {
        fscanf(entrada, "%s", Comando);

        if (strcmp(Comando, "ENTREGA") == 0)
        {
            cout << Comando << endl;
            fscanf(entrada, "%d %d %d", &U, &E, &N);
            cout << U << " " << E << " " << N << endl;

            for (int i = 0; i < N; i++)
            {
                fscanf(entrada, "%s", aux);
                MSG = MSG + aux + " ";
            }
            cout << MSG << endl;
            // Entregar_email(server, email, U, MSG);
            // email->SetConteudo(MSG);
            // email.SetId(U % M);
            // email->Imprime();
            // dado->SetChave(MSG);
            // email.Imprime();
            // email.conteudo = MSG;
            // email.id = (U % M);
            // cout << email.id << " " << email.conteudo << endl;

            // server->Insere(email, M);
        }
        else if (strcmp(Comando, "CONSULTA") == 0)
        {
            cout << Comando << endl;
            fscanf(entrada, "%d %d", &U, &E);
            cout << U << " " << E << endl;
        }
        else if (strcmp(Comando, "APAGA") == 0)
        {
            cout << Comando << endl;
            fscanf(entrada, "%d %d", &U, &E);
            cout << U << " " << E << endl;
        }
    }

    cout << arquivo_saida << endl;
    fclose(entrada);
}
