#include "TADs.hpp"

TipoItem::TipoItem()
{
    chave = -1; // indica um item vazio
}

TipoItem::TipoItem(TipoChave c)
{
    chave = c;
}

void TipoItem::SetChave(TipoChave c)
{
    chave = c;
}

TipoChave TipoItem::GetChave()
{
    return chave;
}

void TipoItem::Imprime()
{
    printf("%d ", chave);
}

TipoNo::TipoNo()
{
    item.SetChave(-1);
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

void ArvoreBinaria::Insere(TipoItem item)
{
    InsereRecursivo(raiz, item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo *&p, TipoItem item)
{
    if (p == NULL)
    {
        p = new TipoNo();
        p->item = item;
    }
    else
    {
        if (item.GetChave() < p->item.GetChave())
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::PreOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        p->item.Imprime();
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void ArvoreBinaria::InOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        InOrdem(p->esq);
        p->item.Imprime();
        InOrdem(p->dir);
    }
}

void ArvoreBinaria::PosOrdem(TipoNo *p)
{
    if (p != NULL)
    {
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        p->item.Imprime();
    }
}

void ArvoreBinaria::Limpa()
{
    ApagaRecursivo(raiz);
    raiz = NULL;
}

TipoItem ArvoreBinaria::Pesquisa(TipoChave chave)
{
    return PesquisaRecursivo(raiz, chave);
}

void ArvoreBinaria::Remove(TipoChave chave)
{
    return RemoveRecursivo(raiz, chave);
}

TipoItem ArvoreBinaria::PesquisaRecursivo(TipoNo *no, TipoChave chave)
{
    TipoItem aux;
    if (no == NULL)
    {
        aux.SetChave(-1); // Flag para item não presente
        return aux;
    }
    if (chave < no->item.GetChave())
        return PesquisaRecursivo(no->esq, chave);
    else if (chave > no->item.GetChave())
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
}

void ArvoreBinaria::RemoveRecursivo(TipoNo *&no, TipoChave chave)
{
    TipoNo *aux;
    if (no == NULL)
    {
        throw("Item nao está presente");
    }
    if (chave < no->item.GetChave())
        return RemoveRecursivo(no->esq, chave);
    else if (chave > no->item.GetChave())
        return RemoveRecursivo(no->dir, chave);
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
    q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}

TipoItem Hash_LE::Pesquisa(TipoChave chave)
{
    int pos;
    TipoItem item;
    pos = Hash(chave);
    item = Tabela[pos].Pesquisa(chave);
    return item;
}

void Hash_LE::Insere(TipoItem item)
{
    TipoItem aux;
    int pos;
    aux = Pesquisa(item.GetChave());
    if (!aux.Vazio())
        throw("Erro: Item já está presente");
    pos = Hash(item.GetChave());
    Tabela[pos].Insere(item);
}

void Hash_LE::Remove(TipoChave chave)
{
    int pos;
    pos = Hash(chave);
    Tabela[pos].Remove(chave);
}