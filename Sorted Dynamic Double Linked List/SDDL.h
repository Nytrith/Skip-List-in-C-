typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, int valor);
int remove_elem(Lista *lst, int valor);
void imprime_lista(Lista lst);
int remove_todos(Lista *lst, int valor);