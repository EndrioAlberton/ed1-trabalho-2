#ifndef LISTA_H
#define LISTA_H

typedef struct Contato {
    char nome[100];
    char email[100];
    char telefone[20];
    struct Contato *prox; 
    struct Contato *ant;  
} Contato;

typedef struct ListaContatos {
    struct Contato *inicio;
    struct Contato *fim; 
    int tamanho;
} ListaContatos;

/* Inicializa a lista */
void inicializaLista(ListaContatos *lista);

/* 
    Insere um contato ordenado por ordem alfabética.
    Retorna 1 para sucesso e 0 para falha.
*/
int insereOrdenado(ListaContatos *lista, Contato *c);

/*
    Remove um contato da lista na posição.
    Retorna 1 para sucesso e 0 para falha.
*/
int removeContato(ListaContatos *lista, int pos);

/*
    Consultar contato da lista na posição.
    Retorna 1 para sucesso e 0 para falha.
*/
int consultaContato(ListaContatos *lista, int pos);

/*
    Mostra todos os contatos da lista
*/
void imprimeContatos(ListaContatos *lista);


#endif