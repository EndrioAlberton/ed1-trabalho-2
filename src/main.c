#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/* Criar um novo contato */
/* TODO: Retornar um status para sucesso/falha */
Contato *criaContato(char nome[], char email[], char telefone[]) {
    Contato *novoContato = (Contato *) malloc(sizeof(Contato));
    
    if (novoContato == NULL) {
        printf("Erro ao alocar memória para novo contato.\n");
        /*return;*/
    }
    strcpy(novoContato->nome, nome);
    strcpy(novoContato->email, email);
    strcpy(novoContato->telefone, telefone);
    novoContato->prox = NULL;
    novoContato->ant = NULL;
    return novoContato;
}

int main() {
    ListaContatos lista;
    Contato *novoContato;

    char nome[100];
    char email[100];
    char telefone[20];
    char continuar;

    inicializaLista(&lista);

    do {

        printf("Digite o nome do contato: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
       
        printf("Digite o e-mail do contato: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';

        printf("Digite o telefone do contato: ");
        fgets(telefone, sizeof(telefone), stdin);
        telefone[strcspn(telefone, "\n")] = '\0'; 

        novoContato = criaContato(nome, email, telefone);
        if (novoContato != NULL) {
            insereOrdenado(&lista, novoContato);
        }

        printf("Deseja inserir outro contato? (s/n): ");
        scanf(" %c", &continuar);
        getchar();

    } while (continuar == 's' || continuar == 'S');

    /* Imprimir todos os contatos da lista */
    printf("\nLista de Contatos:\n");
    imprimeContatos(&lista);
}
