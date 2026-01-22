#include "header.h"
#include <stdio.h>

/*/
Definir a estrutura de dados para representar os nós da lista e o nó descritor.
Implementar as funções básicas para manipular a lista:
Iniciar a lista encadeada.
Adicionar um elemento no início da lista.
Adicionar um elemento no final da lista.
Remover o elemento do início da lista.
Remover o elemento do final da lista.
Remover um determinado elemento em qualquer posição da lista.
Exibir todos os elementos da lista e a quantidade de elementos.
Fazer a função principal
/*/

int main(){
    Descritor *lista;

    printf("--Menu de operacoes na lista encadeada:--\n");
    printf("1. Iniciar a lista encadeada\n");
    printf("2. Adicionar elemento no inicio da lista\n");
    printf("3. Adicionar elemento no final da lista\n");
    printf("4. Remover elemento do inicio da lista\n");
    printf("5. Remover elemento do final da lista\n");
    printf("6. Remover um elemento especifico\n");
    printf("7. Exibir todos os elementos da lista\n");
    printf("8. Sair\n");
    printf("-----------------------------------------\n");

    int opcao = 0;
    while(opcao != 8){
        printf("Digite a opcao desejada:\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                lista = inicializarLista();
                break;
            case 2:
                adicionarNoInicio(lista);
                break;
            case 3:
                adicionarNoFinal(lista);
                break;
            case 4:
                removerDoInicio(lista);
                break;
            case 5:
                removerDoFinal(lista);
                break;
            case 6:
                removerElemento(lista);
                break;
            case 7:
                exibirLista(lista);
                break;
            case 8:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    return 0;
}