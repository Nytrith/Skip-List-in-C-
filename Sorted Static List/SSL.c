#include "SSL.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct lista{
     int vet[MAX];
     int Fim;
};

Lista cria_lista()
{

    Lista lst;

    lst = (Lista)malloc(sizeof(struct lista));

    if(lst != NULL)
        lst -> Fim = 0;

    return lst;
}

int lista_vazia(Lista lst)
{

     if(lst -> Fim == 0)
        return 1;              //O yago eh lindo
     else
        return 0;
}

int lista_cheia(Lista lst)
{

    if(lst -> Fim == MAX)
        return 1;
    else
        return 0;
}

int insere_ordenado(Lista lst, int n)
{
    int i, aux = 0;

    if(lst == NULL || lista_cheia(lst) == 1)
        return 0;

    if(lista_vazia(lst) == 1 || n >= lst->vet[lst->Fim-1])
        lst->vet[lst->Fim] = n;

    while(n < lst->vet[aux])
        aux++;

    for( i = lst->Fim; i > aux; i--)
        lst->vet[i] = lst->vet[i-1];

    lst->vet[aux] = n;
    lst->Fim++;

    return 1;

}

int remove_ordenado(Lista lst, int n)
{
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0;

    int i, aux = 0;

    while(aux < lst->Fim && lst->vet[aux] < n)
        aux++;
    
    if(aux == lst->Fim && lst->vet[aux] > n)
        return 0;

    for(i = aux+1; i < lst->Fim; i++)
    lst->vet[i-1] = lst->vet[i];

    lst->Fim--;
    return 1;
}

void imprime_lista(Lista lst)
{
   int i;

   if(lista_vazia(lst) == 1){
       printf("Lista vazia ou inexistente!\n");
   }

   printf("{ ");

   for(i = 0;i < lst->Fim; i++)
      printf("%d ", lst->vet[i]);

   printf("}\n");
}


int remove_pares(Lista lst)
{
	if(lst==NULL||lista_vazia(lst)) 
        return 0;
	
	int i=0, j, aux = lst->Fim;

	while(i < lst->Fim)
	{
	if(lst->vet[i] % 2 == 0){
        if(i == lst->Fim-1){
			lst->Fim--;
			return 1;
		}
		else{
			for(j = i; j < lst->Fim-1; j++){
				lst->vet[j] = lst->vet[j+1];
			}
			    lst->Fim--;
			}
		}
		else i++;
	}
	if(lst->Fim < aux) return 1;
    return 0;	
}

int tamanho(Lista lst)
{
	return lst->Fim;
}

int maior(Lista lst)
{
	if(lst == NULL || lista_vazia(lst) == 1) return -99999; //Numero absurdo para representar erro de lista vazia ou inexistente
	
return lst->vet[lst->Fim-1];	
}

int iguais(Lista x, Lista y)
{
	if(x->Fim != y->Fim)
         return 0;
	
    int aux = 0, i;
	
	for(i = 0; i < x->Fim; i++){
		if(x->vet[i] != y->vet[i])
            aux++;
	}
	
	if(aux != 0)
        return 0;
	
return 1;	
}



