typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int n);
int remove_ord(Lista *lst, int elem);
int remove_impares(Lista *lst);
int menor(Lista lst);
int imprime_lista(Lista lst);
int tamanho(Lista lst);
Lista intercala_lista(Lista x, Lista y);

