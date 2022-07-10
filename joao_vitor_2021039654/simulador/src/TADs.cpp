#include "../include/TADs.hpp"

Mensagem::Mensagem()
{
    id_mensagem = -1; // indica um item vazio
    conteudo = " ";
    id_destinatario = -1;
}

Mensagem::Mensagem(int id_mensagem, string msg_conteudo)
{
    id_mensagem = id_mensagem;
    conteudo = msg_conteudo;
}

void Mensagem::SetIdMensagem(int _id_mensagem)
{
    id_mensagem = _id_mensagem;
}

int Mensagem::GetIdMensagem()
{
    return id_mensagem;
}

void Mensagem::SetIdDestinatario(int _id_destinatario)
{
    id_destinatario = _id_destinatario;
}

int Mensagem::GetIdDestinatario()
{
    return id_destinatario;
}

void Mensagem::SetConteudo(string _msg_conteudo)
{
    conteudo = _msg_conteudo;
}

string Mensagem::GetConteudo()
{
    return conteudo;
}

bool Mensagem::Vazio()
{
    if (conteudo.empty() && id_mensagem == -1)
    {
        return true;
    }
    else
        return false;
}

void Mensagem::Imprime()
{
    cout << id_mensagem << " " << conteudo << endl;
}

TipoNo::TipoNo()
{
    dados.SetIdMensagem(-1);
    dados.SetConteudo(" ");
    dados.SetIdDestinatario(-1);
    esq = NULL;
    dir = NULL;
}

ArvoreBinaria::ArvoreBinaria()
{
    raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria()
{
    Limpa();
}

void ArvoreBinaria::Insere(Mensagem dados)
{
    InsereRecursivo(raiz, dados);
}

void ArvoreBinaria::InsereRecursivo(TipoNo *&p, Mensagem dados)
{
    if (p == NULL)
    {
        p = new TipoNo();
        p->dados = dados;
    }
    else
    {
        if (dados.GetIdMensagem() < p->dados.GetIdMensagem())
            InsereRecursivo(p->esq, dados);
        else
            InsereRecursivo(p->dir, dados);
    }
}

void ArvoreBinaria::PreOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        p->dados.Imprime();
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void ArvoreBinaria::InOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        InOrdem(p->esq);
        p->dados.Imprime();
        InOrdem(p->dir);
    }
}

void ArvoreBinaria::PosOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        p->dados.Imprime();
    }
}

void ArvoreBinaria::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = NULL;
}

Mensagem ArvoreBinaria::Pesquisa(int id_mensagem)
{
    return PesquisaRecursivo(raiz, id_mensagem);
}

Mensagem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, int id_mensagem)
{
    Mensagem aux;
    if (no == NULL)
    {
        aux.SetIdMensagem(-1); // Flag para item não presente
        return aux;
    }
    if (id_mensagem < no->dados.GetIdMensagem())
        return PesquisaRecursivo(no->esq, id_mensagem);
    else if (id_mensagem > no->dados.GetIdMensagem())
        return PesquisaRecursivo(no->dir, id_mensagem);
    else
    {
        return no->dados;
    }
}

void ArvoreBinaria::Remove(int id_mensagem)
{
    return RemoveRecursivo(raiz, id_mensagem);
}

void ArvoreBinaria::RemoveRecursivo(TipoNo *&no, int id_mensagem)
{
    TipoNo *aux;
    if (no == NULL)
    {
        cout << "ERRO: MENSAGEM INEXISTENTE" << endl;
    }
    if (id_mensagem < no->dados.GetIdMensagem())
        return RemoveRecursivo(no->esq, id_mensagem);
    else if (id_mensagem > no->dados.GetIdMensagem())
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
    }
}

void ArvoreBinaria::ApagaRecursivo(TipoNo *p)
{
    if (p != NULL)
    {
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}

void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo *&r)
{
    if (r->dir != NULL)
    {
        Antecessor(q, r->dir);
        return;
    }
    q->dados = r->dados;
    q = r;
    r = r->esq;
    free(q);
}

Hash_LE::Hash_LE(int M)
{
    this->Tabela = new ArvoreBinaria[M];
}

int Hash_LE::Hash(int id_mensagem, int M)
{
    return id_mensagem % M;
}

Mensagem Hash_LE::Pesquisa(Mensagem dados, int M, int Tipo)
{
    int pos;
    Mensagem texto;
    pos = Hash(dados.GetIdDestinatario(), M);
    texto = Tabela[pos].Pesquisa(dados.GetIdMensagem());

    if (Tipo == 1)
    {
        if (texto.id_mensagem == -1)
        {
            cout << "CONSULTA " << dados.GetIdDestinatario() << " " << dados.GetIdMensagem() << ": MENSAGEM INEXISTENTE " << endl;
        }
        else
        {
            cout << "CONSULTA " << texto.GetIdDestinatario() << " " << texto.GetIdMensagem() << ": " << texto.GetConteudo() << endl;
        }
    }
    return dados;
}

void Hash_LE::Insere(Mensagem dados, int M)
{
    Mensagem aux;
    int pos;
    aux = Pesquisa(dados, M, 0);
    pos = Hash(dados.GetIdDestinatario(), M);
    Tabela[pos].Insere(dados);
    cout << "OK: MENSAGEM " << dados.GetIdMensagem() << " PARA " << dados.GetIdDestinatario() << " ARMAZENADA EM " << pos << endl;
}

void Hash_LE::Remove(Mensagem dados, int M)
{
    int pos;
    pos = Hash(dados.GetIdDestinatario(), M);
    Tabela[pos].Remove(dados.GetIdMensagem());
}
