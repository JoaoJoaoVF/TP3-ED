#include "../include/TADs.hpp"

// Mensagem::Mensagem()
// {
// }

// Mensagem::Mensagem(int msg_id, string msg_conteudo)
// {
//     id = msg_id;
//     conteudo = msg_conteudo;
// }

// void Mensagem::SetId(int msg_id)
// {
//     id = msg_id;
// }

// int Mensagem::id
// {
//     return id;
// }

// void Mensagem::SetConteudo(string msg_conteudo)
// {
//     conteudo = msg_conteudo;
// }

// string Mensagem::GetConteudo()
// {
//     return conteudo;
// }

// void Mensagem::Imprime()
// {
//     // printf("%d ", chave);
//     cout << id << " " << conteudo;
// }

TipoNo::TipoNo()
{
    dados.id = -1;
    dados.conteudo = nullptr;
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
        // p->item = item;
        p->dados = dados;
    }
    else
    {
        if (dados.id < p->dados.id)
            InsereRecursivo(p->esq, dados);
        else
            InsereRecursivo(p->dir, dados);
    }
}

// void ArvoreBinaria::PreOrdem(TipoNo *p)
// {
//     if (p != NULL)
//     {
//         p->dados.Imprime();
//         PreOrdem(p->esq);
//         PreOrdem(p->dir);
//     }
// }

// void ArvoreBinaria::InOrdem(TipoNo *p)
// {
//     if (p != NULL)
//     {
//         InOrdem(p->esq);
//         p->dados.Imprime();
//         InOrdem(p->dir);
//     }
// }

// void ArvoreBinaria::PosOrdem(TipoNo *p)
// {
//     if (p != NULL)
//     {
//         PosOrdem(p->esq);
//         PosOrdem(p->dir);
//         p->dados.Imprime();
//     }
// }

void ArvoreBinaria::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = NULL;
}

Mensagem ArvoreBinaria::Pesquisa(int id)
{
    return PesquisaRecursivo(raiz, id);
}

Mensagem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, int id_procurado)
{
    Mensagem aux;
    if (no == NULL)
    {
        aux.id = -1; // Flag para item não presente
        aux.conteudo = nullptr;
        return aux;
    }
    if (id_procurado < no->dados.id)
        return PesquisaRecursivo(no->esq, id_procurado);
    else if (id_procurado > no->dados.id)
        return PesquisaRecursivo(no->dir, id_procurado);
    else
        return no->dados;
}

void ArvoreBinaria::Remove(int id)
{
    return RemoveRecursivo(raiz, id);
}

void ArvoreBinaria::RemoveRecursivo(TipoNo *&no, int id_procurado)
{
    TipoNo *aux;
    if (no == NULL)
    {
        throw("Item nao está presente");
    }
    if (id_procurado < no->dados.id)
        return RemoveRecursivo(no->esq, id_procurado);
    else if (id_procurado > no->dados.id)
        return RemoveRecursivo(no->dir, id_procurado);
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
    ArvoreBinaria *Tabela = new ArvoreBinaria[M];
}

// Hash_LE::Hash_LE()
// {
//     Tabela->~ArvoreBinaria();
// }

Mensagem Hash_LE::Pesquisa(Mensagem dados)
{
    int pos;
    Mensagem texto;
    pos = Hash(dados.id);
    texto = Tabela[pos].Pesquisa(dados.id);
    return dados;
}

void Hash_LE::Insere(Mensagem dados)
{
    Mensagem aux;
    int pos;
    aux = Pesquisa(dados);
    if (aux.id != -1)
        throw("Erro: Item já está presente");
    pos = Hash(dados.id);
    Tabela[pos].Insere(dados);
}

void Hash_LE::Remove(Mensagem dados)
{
    int pos;
    pos = Hash(dados.id);
    Tabela[pos].Remove(dados.id);
}
