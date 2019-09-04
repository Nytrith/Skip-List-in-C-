typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_final(Lista *lst, int valor);
int remove_inicio(Lista *lst, int *valor);
int tamanho_lista(Lista lst);
void imprime_lista(Lista lst);
int inserir_comeco(Lista *lst, int valor);
int inserir_posicao(Lista *lst, int valor, int posicao);
int remover_posicao(Lista *lst,int posicao);
int maior(Lista lst);