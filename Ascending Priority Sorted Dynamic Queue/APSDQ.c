#include "APSDQ.h"
#include <stdio.h>
#include <stdlib.h>

struct no{
    int pri;
    int info;
    struct no *prox;
};

struct fila{
    struct no *ini;
    struct no *fim;
};

Fila cria_fila(){
    Fila f = (Fila)malloc(sizeof(struct fila));

    if(f != NULL){
        f->fim = NULL;
        f->ini = NULL;
    }

    return f;
}

int fila_vazia(Fila f){
    if(f->ini == NULL)
        return 1;

    return 0;
}

int remove_inicio(Fila f, int *elem){
    if(fila_vazia(f) == 1)
        return 0;

    No aux = f->ini;

    *elem = aux->info;

    if(f->ini == f->fim)
        f->fim = NULL;

    f->ini = aux->prox;
    free(aux);
    return 1;
}

int insere_ord_pri_asc(Fila f, int elem, int pri){
    No N = (No)malloc(sizeof(struct no));
    
    if(N == NULL)
        return 0;

    N->info = elem;
    N->pri  = pri;
    N->prox = NULL;


    if(fila_vazia(f) == 1){
        f->fim = N;
        f->ini = N;
        return 1;
    }

    if(N->pri >= f->fim->pri){
        f->fim->prox = N;
        f->fim = N;
        return 1;
    }

    No aux = f->ini;

    while(aux->prox != NULL && aux->pri < N->pri)
        aux = aux->prox;

    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

void imprimir_fila(Fila f){
    if(fila_vazia(f) == 1)
        printf("Fila vazia ou inexistente!\n");

    No aux = f->ini;

    printf("{ ");
    while(aux->prox != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }

    printf("%d", aux->info);
    printf(" }\n");
}

