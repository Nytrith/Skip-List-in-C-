typedef struct fila *Fila;
typedef struct no *No;

Fila cria_fila();
int fila_vazia(Fila f);
int remove_inicio(Fila f, int *elem);
int insere_ord_pri_asc(Fila f, int elem, int pri);
void imprimir_fila(Fila f);