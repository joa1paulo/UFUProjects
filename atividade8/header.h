struct No{
    int valor;
    struct No *prox; 
};
typedef struct No No;
 
 
struct Descritor{
    No *inicio;
    No *fim;
    int quantidade; 
};
typedef struct Descritor Descritor;

Descritor* inicializarLista();
void adicionarNoInicio(Descritor *lista);
void adicionarNoFinal(Descritor *lista);
void removerDoInicio(Descritor *lista);
void removerDoFinal(Descritor *lista);
void removerElemento(Descritor *lista);
void exibirLista(Descritor *lista);
