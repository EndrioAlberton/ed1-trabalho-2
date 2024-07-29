#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void inicializaLista(ListaContatos *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

/* TODO: Não insere ordenado */
int insereOrdenado(ListaContatos *lista, Contato *c) {
    if (lista == NULL || c == NULL) {
        return 0;
    }

    if (lista->inicio == NULL) {
        lista->inicio = c;
        lista->fim = c;
    } else {
        Contato *atual = lista->inicio;

        while (atual != NULL && strcmp(c->nome, atual->nome) > 0) {
            atual = atual->prox;
        }

        if (atual == NULL) {
            lista->fim->prox = c;
            c->ant = lista->fim;
            lista->fim = c;
        } else {

            if (atual->ant == NULL) {
                c->prox = lista->inicio;
                lista->inicio->ant = c;
                lista->inicio = c;
            } else {
                c->prox = atual;
                c->ant = atual->ant;
                atual->ant->prox = c;
                atual->ant = c;
            }
        }
        
    }

    lista->tamanho++;
    return 1;
}

void imprimeContatos(ListaContatos *lista) {
    Contato *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("E-mail: %s\n", atual->email);
        printf("Telefone: %s\n\n", atual->telefone);
        printf("\n");
        atual = atual->prox;
    }
}