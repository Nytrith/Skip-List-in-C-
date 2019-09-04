#include "DS.h"
#include <stdio.h>
#include <stdlib.h>


struct no{
    int info;
    struct no *prox;
};

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p == NULL)
        return 1;

    return 0;
}

int push(Pilha *p, int valor){
    Pilha N = (Pilha)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    
    N->info = valor;
    N->prox = *p;
    *p = N;
    return 1;
}

int pop(Pilha *p, int *elem){
    if(pilha_vazia(*p) == 1)
        return 0;

    Pilha aux = *p;

    *elem = aux->info;
    *p = aux->prox;
    free(aux);
    return 1;
}

int le_topo(Pilha *p, int *elem){
    if(pilha_vazia(p) == 1)
        return 0;

    *elem = (*p)->info;
    return 1;
}

void imprimir_pilha(Pilha p){
    if(pilha_vazia(p) == 1 || p == NULL)
        printf("Lista vazia ou inexistente");

    Pilha aux = p;
    
    while(aux->prox != NULL){
        printf("|");
        printf("%d", aux->info);
        printf("|");
        printf("\n");
        aux = aux->prox;
    }
    printf("|");
        printf("%d", aux->info);
        printf("|");
        printf("\n");
}

void imprimir_reversa(Pilha p){
    if(pilha_vazia(p) == 1)
        return 0;

    Pilha p2 = cria_pilha();
    Pilha aux = p;
    int elem;

    while(aux->prox != NULL){
        push(&p2, aux->info);
        aux = aux->prox;
    }

    push(&p2, aux->info);

    printf("Pilha reversa\n");
    imprimir_pilha(p2);
}

int palindromo(char *a){

    Pilha p = cria_pilha();
    Pilha p2 = cria_pilha();

    int elem, i;

    for(i = 0; a[i] != '\0'; i++){
        push(&p, a[i]);
    }

    Pilha aux0 = p;

    while(aux0->prox != NULL){
        push(&p2, aux0->info);
        aux0 = aux0->prox;
    }

    push(&p2, aux0->info); 

    Pilha aux3 = p;
    Pilha aux2 = p2;

    int elf = 0;

    while(aux3->prox != NULL && aux2->prox != NULL && elf == 0){
        if(aux3->info == aux2->info){
            aux3 = aux3->prox;
            aux2 = aux2->prox;
            elf = 0;
        }
        else 
            elf = 1;
    }

    if(elf == 0)
        return 1;
    else 
        return 0;

}

void pares_impares(int *v){

    Pilha p = cria_pilha();
    int i, elem;

    for(i = 0; v[i] != '\0'; i++){
        push(&p, v[i]);
    }

    Pilha p2 = cria_pilha();
    Pilha p3 = cria_pilha();

    Pilha aux = p;

    while(aux->prox != NULL){
        if(aux->info % 2 == 0){
            push(&p2, aux->info);
        }
        if(aux->info % 2 != 0){
            push(&p3, aux->info);
        }
        aux = aux->prox;
    }

    if(aux->info % 2 == 0){
            push(&p2, aux->info);
        }
        if(aux->info % 2 != 0){
            push(&p3, aux->info);
        }

    printf("\n");

    printf("Pilha par:\n");
    imprimir_pilha(p2);

    printf("\n");

    printf("Pilha impar:\n");
    imprimir_pilha(p3);
}

