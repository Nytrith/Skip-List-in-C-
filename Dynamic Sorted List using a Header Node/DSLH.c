#include "DLSH.h"
#include <stdio.h>
#include <stdlib.h> 

struct no{
    int info;
    struct no *prox;
};

Lista cria_lista()
{
	Lista cab;

    cab  =  (Lista) malloc(sizeof(struct no));
    if(cab != NULL){
        cab->prox = NULL;
        cab->info = 0;
    }

    return cab;
}

int lista_vazia(Lista lst)
{
    if(lst->prox == NULL)
        return 1;

    return 0;
}

int insere_ord(Lista *lst, int n)
{
    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;

    N->info = n;
    Lista aux = *lst;

    while(aux->prox != NULL && aux->prox->info <= n)
        aux = aux->prox;

    N->prox = aux->prox;
    aux->prox = N;
    (*lst)->info++;
    
    return 1;
}



int imprime_lista(Lista lst)
{
    if(lst->prox == NULL)
        return 0;

    Lista aux = lst;
    printf("{");
        while(aux->prox !=NULL){
            printf("%d ", aux->prox->info);
            aux = aux->prox;
        }
    printf("}");

    return 1;
}

int tamanho(Lista lst)
{
    if(lst == NULL) 
        return 0;
    return lst->info;
}

 int remove_elemento(Lista *lst, int n)
{
    if(lista_vazia(lst) == 1)
        return 0;

    Lista aux = *lst;

    while(aux->prox != NULL && aux->prox->info < n)
        aux = aux->prox;

    if(aux->prox == NULL || aux->prox->info > n)
        return 0;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;

    free(aux2);
    (*lst)->info--;
    return 1;
} 

int remove_impares(Lista *lst)
{
    if(*lst == NULL) 
        return 0;
   	
    Lista aux = *lst;
	
    while(aux->prox != NULL && aux->prox->info % 2 != 0)
    {
        Lista aux2 = aux->prox;
        aux->prox = aux2->prox;
        free(aux2);
        (*lst)->info--;
    }

    *lst = aux;

    if(aux->prox == NULL) 
        return 1;
    
    Lista ant = aux;
    aux = aux->prox;
    
    while(aux != NULL)
    {
        if(aux->info % 2 != 0)
        {
            ant->prox = aux->prox;
            free(aux);
            aux = ant;
            (*lst)->info--;
        }
        
        ant = aux;
        aux = aux->prox;
    }
    return 1;
}

int menor(Lista lst)
{
    if(lst == NULL)
        return 0;
    
    int menor = -999999999;

    Lista aux = lst;
    menor = aux->prox->info;

    while(aux->prox != NULL){  
        if(aux->prox->info < menor)
            menor = aux->prox->info;
        aux = aux->prox;
    }

    return menor;
}

int iguais(Lista *x, Lista *y)
{
    if(lista_vazia(x) && lista_vazia(y))
        return 0;

    Lista aux = (*x)->prox;
    Lista aux2 = (*y)->prox;

    while(aux !=  NULL)
    {
        if(aux->info != aux2->info)
            return 0;
        aux = aux->prox;
        aux2 = aux2->prox;
    }

    return 1;
}

Lista intercala(Lista x, Lista y)
{
    if(x == NULL && y == NULL) 
        return 0;
    
    Lista aux = x;
    Lista w = cria_lista();
    Lista aux2 = y;
    
    while(aux->prox != NULL)
    { 
        insere_ord(&w, aux->prox->info);
        aux = aux->prox;
    }
    
    while(aux2->prox != NULL)
    { 
        insere_ord(&w, aux2->prox->info);
        aux2 = aux2->prox;
    }
    return w;
}



