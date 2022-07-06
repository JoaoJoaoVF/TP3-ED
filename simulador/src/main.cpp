#include "memlog.hpp"
#include "msgassert.hpp"
#include "Simulador.hpp"
#include "Execucao.hpp"

using namespace std;

// variaveis globais para opcoes
char nome_entrada[100];
char nome_saida[100];
int M, S, regmem;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
    fprintf(stderr, "simulador\n");
    fprintf(stderr, "\t-I, -i \t(Nome do arquivo de entrada com o texto a ser processado) \n");
    fprintf(stderr, "\t-O, -o \t(endereço do arquivo de saída)\n");
}

void parse_args(int argc, char **argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida
{
    // variaveis externas do getopt
    extern char *optarg;

    // variavel auxiliar
    int c;

    // inicializacao variaveis globais para opcoes
    S = 0;
    regmem = 0;

    // getopt - letra indica a opcao, : junto a letra indica parametro
    // no caso de escolher mais de uma operacao, vale a ultima
    while ((c = getopt(argc, argv, "i:o:l")) != EOF)
        switch (c)
        {
        case 'i':
            strcpy(nome_entrada, optarg);
            break;
        case 'o':
            strcpy(nome_saida, optarg);
            break;
        case 'l':
            regmem = 1;
            break;
        case 'h':
        default:
            uso();
        }
}

int main(int argc, char **argv)
{
    // Usado para analisar os paramertos passado na linha de comando
    parse_args(argc, argv);

    // Inicia o memlog
    char nome[30] = "./bin/simulador_log.out";
    iniciaMemLog(nome);
    // ativaMemLog();

    // ativar ou nao o registro de acesso
    if (regmem == 1)
    {
        ativaMemLog();
    }
    else
    {
        desativaMemLog();
    }

    // Testa se os arquivos de entrada e saida
    FILE *entrada = fopen(nome_entrada, "r");
    erroAssert(entrada != NULL, "Não foi possivel abrir o arquivo");
    fclose(entrada);
    FILE *saida = fopen(nome_saida, "w");
    erroAssert(saida != NULL, "Não foi possivel abrir o arquivo");
    fclose(saida);

    // Chama a funcao resposavel pela execucao do programa
    Executa(nome_entrada, nome_saida);

    // finaliza a analise de tempo
    return finalizaMemLog();
}