#include "SDCL.h"
#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if(lst == NULL)
        return 1;

    return 0;
}

int insere_final(Lista *lst, int valor)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
        return 0;

    N->info = valor;

    if(lista_vazia(*lst) == 1){
        N->prox = N;
        *lst = N;
    }
    else{
        N->prox = (*lst)->prox; //O no a ser inserido aponta para o primeiro no
        (*lst)->prox = N;
        (*lst) = N;
    }

    return 1;
}

int remove_inicio(Lista *lst, int *valor)
{
    if(lista_vazia(*lst) == 1)
        return 0;

    Lista aux = (*lst)-> prox;
    *valor = aux->info;

    if(*lst == (*lst)->prox){
        *lst = NULL;
    }
    else{
        (*lst)->prox = aux->prox;
    }

    free(aux);
    return 1;
}

void imprime_lista(Lista lst)
{
    int i;
    Lista aux = lst->prox;

    if(lista_vazia(lst) == 1)
        printf("Lista vazia!");

    printf("{");
    while(aux != lst){
        printf("%d,", aux->info);
        aux = aux->prox;
    }
    printf("%d", aux->info);
    printf("}");

}

int tamanho_lista(Lista lst)
{
    int tam = 0;
    Lista aux = lst->prox;

    if(lista_vazia(lst) == 1 )
        return 0;

    while(aux != lst ){
        tam++;
        aux = aux->prox;
    }
    tam++;
    return tam;
}

int inserir_comeco(Lista *lst, int valor)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
        return 0;

    N->info = valor;

    if(lista_vazia(*lst) == 1){
        *lst = N;
        N->prox = N;
        return 1;
    }

    N->prox = (*lst)->prox;
    (*lst)->prox = N;
    
    return 1;
}

int inserir_posicao(Lista *lst, int valor, int posicao)
{
    int contador = 1;
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
        return 0;

    N->info = valor;

    if(lista_vazia(*lst) == 1){
        *lst = N;
        N->prox = N;
        return 1;
    }

    Lista aux = *lst;
    Lista aux2 = *lst;

    while(aux->prox != aux2 && contador < posicao){
        aux = aux->prox;
        contador++;
    }

    N->prox = aux->prox;
    aux->prox = N;
    return 1;

}

int remover_posicao(Lista *lst,int posicao)
{
    int contador = 1;

    if(lista_vazia(*lst) == 1)
        return 0;

    Lista aux = *lst;
    Lista aux2 = *lst;

    while(aux->prox != aux2 && contador < posicao){
        aux = aux->prox;
        contador++;
    }

    if(aux->prox == aux2)
        return 0;

    Lista aux3 = aux->prox;
    aux->prox = aux3->prox;
    free(aux3);

    return 1;

}

int maior(Lista lst)
{
    int contador = 0,maior = 0;

    if(lista_vazia(lst) == 1)
        return 0;

    Lista aux = lst;
    Lista aux2 = lst;

    while(aux->prox != aux2){
        if(aux->info >= maior)
            maior = aux->info;
        aux = aux->prox;
    }

    return maior;
}



