//---------------------------------------------------------------------
// Arquivo      : TADs.cpp
// Conteudo     : Arquivo de implentação dos Tipos Abstratos de Dados
// Autor        : Joao Vitor Ferreira (ferreirajoao@dcc.ufmg.br)
//---------------------------------------------------------------------

#include "../include/TADs.hpp"

using namespace std;

Mensagem::Mensagem()
{
    // Descricao: Construtor da Mensagem.
    // Entrada: Não possui.
    // Saida: Mensagem inicializada.

    id_mensagem = -1; // indica um item vazio
    conteudo = " ";
    id_destinatario = -1;
}

void Mensagem::SetIdMensagem(int _id_mensagem)
{
    // Descricao: Define o id da Mensagem.
    // Entrada: Um int com o id da Mensagem.
    // Saida: id da mensagem inicializado.

    id_mensagem = _id_mensagem;
}

int Mensagem::GetIdMensagem()
{
    // Descricao: Retorna o id da Mensagem.
    // Entrada: Não possui.
    // Saida: id da mensagem.

    return id_mensagem;
}

void Mensagem::SetIdDestinatario(int _id_destinatario)
{
    // Descricao: Define o id do destinatario.
    // Entrada: Um int com o id da destinatario.
    // Saida: id do destinatario inicializado.

    id_destinatario = _id_destinatario;
}

int Mensagem::GetIdDestinatario()
{
    // Descricao: Retorna o id do destinatario.
    // Entrada: Não possui.
    // Saida: id do destinatario.

    return id_destinatario;
}

void Mensagem::SetConteudo(string _msg_conteudo)
{
    // Descricao: Define o conteudo da mensagem, e remove o espaço em branco ao final da mensagem.
    // Entrada: Uma string com o conteudo da mensagem.
    // Saida: conteudo da mensagem inicializado.

    int x = _msg_conteudo.length();
    _msg_conteudo.erase(x - 1);

    conteudo = _msg_conteudo;
}

string Mensagem::GetConteudo()
{
    // Descricao: Retorna o conteudo da mensagem.
    // Entrada: Não possui.
    // Saida: Conteudo da mensagem.

    return conteudo;
}

TipoNo::TipoNo()
{
    // Descricao: Construtor do Nó.
    // Entrada: Não possui.
    // Saida: Nó inicializada.

    email.SetIdMensagem(-1);
    email.SetConteudo(" ");
    email.SetIdDestinatario(-1);
    esq = NULL;
    dir = NULL;
}

ArvoreBinaria::ArvoreBinaria()
{
    // Descricao: Construtor da Arvore Binaria.
    // Entrada: Não possui.
    // Saida: Arvore Binaria inicializada.

    raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
    // Descricao: Destrutor da Arvore Binaria.
    // Entrada: Não possui.
    // Saida: Arvore Binaria limpa.

    Limpa();
}

void ArvoreBinaria::Insere(Mensagem email)
{
    // Descricao: Insere os email na Arvore Binaria.
    // Entrada: Um TAD Mensagem.
    // Saida: Dado inserido na Arvore Binaria.

    InsereRecursivo(raiz, email);
}

void ArvoreBinaria::InsereRecursivo(TipoNo *&p, Mensagem email)
{
    // Descricao: Função que realiza o percorrimento dos Nós da Arvore para encontrar o local onde o email sera inserido.
    // Entrada: Um Nó e um TAD Mensagem.
    // Saida: Não possui.

    if (p == NULL)
    {
        p = new TipoNo();
        p->email = email;
    }
    else
    {
        if (email.GetIdMensagem() < p->email.GetIdMensagem())
            InsereRecursivo(p->esq, email);
        else
            InsereRecursivo(p->dir, email);
    }
}

void ArvoreBinaria::Limpa()
{
    // Descricao: Apaga os email na Arvore Binaria.
    // Entrada: Não possui.
    // Saida: Arvore Binaria vazia.

    ApagaRecursivo(raiz);
    raiz = NULL;
}

Mensagem ArvoreBinaria::Pesquisa(int id_mensagem)
{
    // Descricao: Pesquisa um email na Arvore Binaria.
    // Entrada: Um TAD Mensagem.
    // Saida: Um email.

    return PesquisaRecursivo(raiz, id_mensagem);
}

Mensagem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, int id_mensagem)
{
    // Descricao: Função que realiza o percorrimento dos Nós da Arvore para encontrar o
    // local onde o email esta e se ele esta presente na Arvore.
    // Entrada: Um Nó e um TAD Mensagem.
    // Saida: Um email.

    Mensagem aux;
    if (no == NULL)
    {
        aux.SetIdMensagem(-1); // Flag para item não presente
        return aux;
    }
    if (id_mensagem < no->email.GetIdMensagem())
        return PesquisaRecursivo(no->esq, id_mensagem);
    else if (id_mensagem > no->email.GetIdMensagem())
        return PesquisaRecursivo(no->dir, id_mensagem);
    else
        return no->email;
}

void ArvoreBinaria::Remove(int id_mensagem)
{
    // Descricao: Remove um email na Arvore Binaria.
    // Entrada: Um TAD Mensagem.
    // Saida: Não possui.

    return RemoveRecursivo(raiz, id_mensagem);
}

void ArvoreBinaria::RemoveRecursivo(TipoNo *&no, int id_mensagem)
{
    // Descricao: Função que realiza o percorrimento dos Nós da Arvore para encontrar o
    // local onde o email esta e se ele esta presente na Arvore o remove, e realiza a
    // escrita no arquivo de saida do sucesso ou não da operação.
    // Entrada: Um Nó e um TADs Mensagem.
    // Saida: Não possui.

    TipoNo *aux;

    ofstream saida(no->email.arquivo_saida, ios::app);

    if (no == NULL)
    {
        cout << "ERRO: MENSAGEM INEXISTENTE" << endl;
        saida << "ERRO: MENSAGEM INEXISTENTE" << endl;
    }
    if (id_mensagem < no->email.GetIdMensagem())
        return RemoveRecursivo(no->esq, id_mensagem);
    else if (id_mensagem > no->email.GetIdMensagem())
        return RemoveRecursivo(no->dir, id_mensagem);
    else
    {
        if (no->dir == NULL)
        {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if (no->esq == NULL)
        {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
            Antecessor(no, no->esq);

        cout << "OK: MENSAGEM APAGADA" << endl;
        saida << "OK: MENSAGEM APAGADA" << endl;
        saida.close();
    }
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p)
{
    // Descricao: Apaga todos os dados da Arvore.
    // Entrada: Um Nó.
    // Saida: Não possui.

    if (p != NULL)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo *&r)
{
    // Descricao: Encontra um Pai da folha e realiza a troca.
    // Entrada: Dois Nós.
    // Saida: Não possui.

    if (r->dir != NULL)
    {
        Antecessor(q, r->dir);
        return;
    }
    q->email = r->email;
    q = r;
    r = r->esq;
    free(q);
}

Hash_AB::Hash_AB(int M)
{
    // Descricao: Construtor da Tabela Hash.
    // Entrada: Não possui.
    // Saida: Tabela Hash inicializada.

    this->Tabela = new ArvoreBinaria[M];
}

int Hash_AB::Hash(int id_mensagem, int M)
{
    // Descricao: Calcula o valor do mod para determinar a posição na tabela.
    // Entrada: O id da mensagem e o tamanho da Tabela
    // Saida: A posição do email Tabela Hash.

    return id_mensagem % M;
}

Mensagem Hash_AB::Pesquisa(Mensagem email, int M, int Tipo)
{
    // Descricao: Realiza a pesquisa de dado Email na Tabela, e
    // realiza a escrita no arquivo saida do resultado da pesquisa.
    // Entrada: Um TAD email, o tamanho da tabela, um identificador
    // se sera realizada a escrita no arquivo de saida
    // Saida: Não possui.

    int pos;
    Mensagem texto;
    pos = Hash(email.GetIdDestinatario(), M);
    texto = Tabela[pos].Pesquisa(email.GetIdMensagem());

    ofstream saida(email.arquivo_saida, ios::app);

    if (Tipo == 1)
    {
        if (texto.GetIdMensagem() == -1 || texto.GetIdDestinatario() != email.GetIdDestinatario())
        {

            saida << "CONSULTA " << email.GetIdDestinatario() << " " << email.GetIdMensagem() << ": MENSAGEM INEXISTENTE" << endl;
            cout << "CONSULTA " << email.GetIdDestinatario() << " " << email.GetIdMensagem() << ": MENSAGEM INEXISTENTE" << endl;
        }
        else
        {
            saida << "CONSULTA " << texto.GetIdDestinatario() << " " << texto.GetIdMensagem() << ": " << texto.GetConteudo() << endl;
            cout << "CONSULTA " << texto.GetIdDestinatario() << " " << texto.GetIdMensagem() << ": " << texto.GetConteudo() << endl;
        }
    }
    saida.close();
    return email;
}

void Hash_AB::Insere(Mensagem email, int M)
{
    // Descricao: Realiza a inserção de dado Email na Tabela, e
    // realiza a escrita no arquivo saida do resultado da inserção.
    // Entrada: Um TAD email, o tamanho da tabela.
    // Saida: Não possui.

    Mensagem aux;
    int pos;
    ofstream saida(email.arquivo_saida, ios::app);

    aux = Pesquisa(email, M, 0);
    pos = Hash(email.GetIdDestinatario(), M);
    Tabela[pos].Insere(email);
    saida << "OK: MENSAGEM " << email.GetIdMensagem() << " PARA " << email.GetIdDestinatario() << " ARMAZENADA EM " << pos << endl;
    cout << "OK: MENSAGEM " << email.GetIdMensagem() << " PARA " << email.GetIdDestinatario() << " ARMAZENADA EM " << pos << endl;
    saida.close();
}

void Hash_AB::Remove(Mensagem email, int M)
{
    // Descricao: Realiza a remoção de dado Email na Tabela, inicialemente
    // realiza a procura desse elemento na Tabela e caso ele não esteja presente
    // realiza o apontamento disso no arquivo de saida e caso ele esteja presente
    // realiza a remoção dele.
    // Entrada: Um TAD email, o tamanho da tabela.
    // Saida: Não possui.

    int pos;
    Mensagem texto;
    ofstream saida(email.arquivo_saida, ios::app);
    pos = Hash(email.GetIdDestinatario(), M);
    texto = Tabela[pos].Pesquisa(email.GetIdMensagem());
    if (texto.GetIdMensagem() == -1)
    {
        cout << "ERRO: MENSAGEM INEXISTENTE" << endl;
        saida << "ERRO: MENSAGEM INEXISTENTE" << endl;
    }
    else
        Tabela[pos].Remove(email.GetIdMensagem());
    saida.close();
}
