#include "header.h"
#include <stdio.h>
#include <stdlib.h>


Descritor* inicializarLista(){
    Descritor *lista = (Descritor *) malloc(sizeof(Descritor));
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->quantidade = 0;
    return lista;
}

void adicionarNoInicio(Descritor *lista){
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return; 
    int valor;
    scanf("%d", &valor);
    novo->valor = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    if (lista->fim == NULL) { // lista estava vazia
        lista->fim = novo;
    }
    lista->quantidade++;
}

void adicionarNoFinal(Descritor *lista){
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return; 
    int valor;
    scanf("%d", &valor);
    novo->valor = valor;
    novo->prox = NULL;
    if (lista->fim != NULL) {
        lista->fim->prox = novo;
    } else { // lista estava vazia
        lista->inicio = novo;
    }
    lista->fim = novo;
    lista->quantidade++;
}

void removerDoInicio(Descritor *lista){
    if (lista->inicio == NULL) return; // lista vazia
    No *temp = lista->inicio;
    lista->inicio = lista->inicio->prox;
    free(temp);
    lista->quantidade--;
    if (lista->inicio == NULL) { // lista ficou vazia
        lista->fim = NULL;
    }
}

void removerDoFinal(Descritor *lista){
    if (lista->inicio == NULL) return; // lista vazia
    if (lista->inicio == lista->fim) { // apenas um elemento
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
    } else {
        No *atual = lista->inicio;
        while (atual->prox != lista->fim) {
            atual = atual->prox;
        }
        free(lista->fim);
        atual->prox = NULL;
        lista->fim = atual;
    }
    lista->quantidade--;
}

void removerElemento(Descritor *lista){
    if (lista->inicio == NULL) return; // lista vazia
    No *atual = lista->inicio;
    No *anterior = NULL;
    int elemento;
    scanf("%d", &elemento);
    while (atual != NULL && atual->valor != elemento) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return; // elemento nao encontrado
    if (anterior == NULL) { // remover do inicio
        lista->inicio = atual->prox;
        if (lista->inicio == NULL) { // lista ficou vazia
            lista->fim = NULL;
        }
    } else {
        anterior->prox = atual->prox;
        if (atual == lista->fim) { // remover do fim
            lista->fim = anterior;
        }
    }
    free(atual);
    lista->quantidade--;
}

void exibirLista(Descritor *lista){
    No *atual = lista->inicio;
    printf("Elementos da lista: ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\nQuantidade de elementos: %d\n", lista->quantidade);
}

