#include "SDDL.h"
#include <stdio.h>
#include <stdlib.h>

struct no{
    int info;
    struct no *prox;
    struct no *ant;
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

int insere_valor(Lista *lst, int valor)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if(N == NULL)
        return 0;

    N->info = valor;
    N->ant = NULL;
    N->prox = *lst;

    if(lista_vazia(*lst) == 0)
        (*lst)->ant = N;

    *lst = N;
    return 1;
}

int remove_valor(Lista *lst, int valor)
{
    if(lista_vazia(*lst) == 1)
        return 0;

    Lista aux = *lst;

    while(aux->prox != NULL && aux->info != valor)
        aux = aux->prox;

    if(aux->prox == NULL && aux->info != valor)
        return 0;

    if(aux->prox != NULL)
        aux->prox->ant = aux->ant;
    
    if(aux->ant != NULL)
        aux->ant->prox = aux->prox;
    
    if(aux == *lst)
        *lst = aux->prox;

    free(aux);
    return 1;
}

void imprime_lista(Lista lst)
{
    if(lista_vazia(lst) == 1 || lst == NULL)
        printf("Lista vazia ou inexistente!");

    Lista aux = lst;

    printf("{ ");
    while(aux->prox != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    
    printf("%d", aux->info);
    printf(" }");
}

int remove_todos(Lista *lst,int valor)
{
    if(lista_vazia(*lst) == 1)
        return 0;

    if((*lst)->info == valor){
        *lst == NULL;
    }

    Lista aux = *lst;
    Lista aux2;

    while(aux->prox != NULL){
        if(aux->prox->info == valor){
            aux2 = aux->prox;
            aux->prox = aux2->prox;

            if(aux2->prox != NULL){
                Lista aux3 = aux2->prox;
                aux->ant = aux2->ant;
            }
            free(aux2);
    }
    aux = aux->prox;
}

return 1;
}






