typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int n);
int remove_elemento(Lista *lst, int n);
int imprime_lista(Lista lst);
int tamanho(Lista lst);
int remove_impares(Lista *lst);
int menor(Lista lst);
int iguais(Lista *x, Lista *y);
Lista intercala(Lista x, Lista y);
