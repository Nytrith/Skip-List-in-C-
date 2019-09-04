typedef struct no *Pilha;



Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p, int valor);
int pop(Pilha *p, int *elem);
int le_topo(Pilha *p, int *elem);
void imprimir_pilha(Pilha p);
void imprimir_reversa(Pilha p);
int palindromo(char *a);
void pares_impares(int *v);