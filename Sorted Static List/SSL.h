typedef struct lista *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_ordenado(Lista lst, int n);
int remove_ordenado(Lista lst, int n);
void imprime_lista(Lista lst);
int maior(Lista lst);
int tamanho(Lista lst);
int iguais(Lista x, Lista y);


