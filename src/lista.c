#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

void inicializaLista(ListaContatos *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int insereOrdenado(ListaContatos *lista, Contato *c) {
    Contato *atual; 

    if (lista == NULL || c == NULL) {
        return 0;
    }

    if (lista->inicio == NULL) {
        lista->inicio = c;
        lista->fim = c;
    } else {
        atual = lista->inicio;

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
    Contato *atual;
    int pos = 1;
    atual = lista->inicio;
    printf("\n");
    while (atual != NULL) {
        printf("%d)\n", pos);
        printf("  Nome: %s\n", atual->nome);
        printf("  E-mail: %s\n", atual->email);
        printf("  Telefone: %s\n\n", atual->telefone);
        atual = atual->prox;
        pos++;
    }
}

Contato* encontraContatoNaPosicao(ListaContatos *lista, int pos) {
    Contato *atual;
    int i;

    if (pos < 0 || pos >= lista->tamanho) {
        return NULL;
    }

    atual = lista->inicio;
    for (i = 0; i < pos; i++) {
        atual = atual->prox;
    }
    return atual;
}

int consultaContato(ListaContatos *lista, int pos) {
    Contato *contato;

    contato = encontraContatoNaPosicao(lista, pos);
    if (contato == NULL) {
        return 0;
    }

    printf("Nome: %s\n", contato->nome);
    printf("Email: %s\n", contato->email);
    printf("Telefone: %s\n", contato->telefone);
    return 1;
}

int removeContato(ListaContatos *lista, int pos) {
    Contato *atual;
    Contato *ant;
    Contato *prox;
    int i;

    if (pos < 0 || pos >= lista->tamanho) {
        return 0;
    }

    atual = lista->inicio;
    for (i = 0; i < pos; i++) {
        atual = atual->prox;
    }

    /* Caso especial para unico item na lista */
    if (atual->prox == NULL && atual->ant == NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
        free(atual);
        return 1;
    }


    /* Troca os anteriores e próximos com navegabilidade segura */

    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }

    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    }

    /* Atualiza header */

    if (atual->prox == NULL) {
        lista->fim = atual->ant;
    }

    if (atual->ant == NULL) {
        lista->inicio = atual->prox;
    }

    lista->tamanho--;
    free(atual);

    return 1;
}