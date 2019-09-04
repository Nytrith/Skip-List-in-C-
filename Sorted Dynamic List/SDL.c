#include "SDL.h"
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

int insere_ord(Lista *lst, int n)
{
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL) 
        return 0;

    N->info = n;

    if(*lst == NULL || n <= (*lst)->info){
        N->prox = *lst;
        *lst = N;
        return 1;
    }

    Lista aux = *lst;

    while(aux->prox != NULL && aux->prox->info < n)
        aux = aux->prox;
  
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int imprime_lista(Lista lst)
{
	if(lst == NULL) {
		printf("Lista Vazia ou inexistente\n");
		return 0;
	}
	Lista aux = lst;

	printf("{");
	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}

	printf("}\n");
	return 1;
}

int remove_ord(Lista *lst, int n)
{
	if(*lst == NULL) 
        return 0;
	
    Lista aux = *lst;
	if(n == (*lst)->info){
		*lst = aux->prox;
		free(aux);
		return 1;
	}
	while(aux->prox != NULL && aux->prox->info != n){
        if(aux->prox->info > n) return 0;
		aux = aux->prox;
    }

	if(aux->prox == NULL) return 0;
	Lista aux2 = aux->prox;
	aux->prox = aux2->prox;
	free(aux2);
	return 1;
}

int remove_impares(Lista *lst)
{
    if(*lst == NULL) 
        return 0;
   	
       Lista aux = *lst;
	while(aux != NULL && aux->info%2 != 0){
        Lista aux2 = aux;
        aux = aux2->prox;
        free(aux2);
    }
    *lst = aux;
    if(aux == NULL) 
        return 1;
    
    Lista ant = aux;
    aux = aux->prox;
    
    while(aux != NULL){
        if(aux->info%2 != 0){
            ant->prox = aux->prox;
            free(aux);
            aux = ant;
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
    
    int menor = 9999999;
    
    Lista aux = lst;
    while(aux != NULL){
        if(aux->info < menor)
			menor = aux->info;
        aux = aux->prox;
    }
    return menor;
}

int tamanho(Lista lst)
{
    int count = 0;
    Lista aux = lst;
    if(lst == NULL) return 0;
    while(aux != NULL) {
        aux = aux->prox;
        count++;
    }
    return count;
}

Lista intercala_lista(Lista x, Lista y)
{
    if(x == NULL && y == NULL) 
        return 0;

    Lista aux = x;
    Lista aux2;
    aux2 = y;
    Lista w;
    w = cria_lista(); 
   
    
    while(aux != NULL){ 
        insere_ord(&w, aux->info);
        aux = aux->prox;
    }
    while(aux2 != NULL){ 
        insere_ord(&w, aux2->info);
        aux2 = aux2->prox;
    }

    return w;
}