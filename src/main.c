#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contato {
    char nome[100];
    char email[100];
    char telefone[20];
    struct Contato *prox; 
    struct Contato *ant;  
};

struct ListaContatos {
    struct Contato *inicio;
    struct Contato *fim; 
    int tamanho;
};

typedef struct Contato Contato;
typedef struct ListaContatos ListaContatos;

/* Criar um novo contato */
Contato *criarContato(char nome[], char email[], char telefone[]) {
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

/* Inserir um contato ordenadamente na lista */
void inserirOrdenado(ListaContatos *lista, Contato *novoContato) {
    if (lista == NULL || novoContato == NULL) {
        return;
    }

    /* Caso especial: lista vazia */
    if (lista->inicio == NULL) {
        lista->inicio = novoContato;
        lista->fim = novoContato;
    } else {
        Contato *atual = lista->inicio;
        while (atual != NULL && strcmp(novoContato->nome, atual->nome) > 0) {
            atual = atual->prox;
        }

        if (atual == NULL) {
            /* Inserir no final */
            lista->fim->prox = novoContato;
            novoContato->ant = lista->fim;
            lista->fim = novoContato;
        } else {
            /* Inserir antes de 'atual' */
            if (atual->ant == NULL) {
                /* Inserir no início */
                novoContato->prox = lista->inicio;
                lista->inicio->ant = novoContato;
                lista->inicio = novoContato;
            } else {
                /* Inserir no meio */
                novoContato->prox = atual;
                novoContato->ant = atual->ant;
                atual->ant->prox = novoContato;
                atual->ant = novoContato;
            }
        }
    }

    lista->tamanho++;
}

/* Imprimir todos os contatos da lista */
void imprimirContatos(ListaContatos *lista) {
    Contato *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->nome);
        printf("E-mail: %s\n", atual->email);
        printf("Telefone: %s\n\n", atual->telefone);
        atual = atual->prox;
    }
}

int main() {
    ListaContatos lista;
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tamanho = 0;

    char nome[100];
    char email[100];
    char telefone[20];
    char continuar;

    do {

        printf("Digite o nome do contato: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';  /* Remove o caractere de nova linha*/
       
        printf("Digite o e-mail do contato: ");
        fgets(email, sizeof(email), stdin);
        email[strcspn(email, "\n")] = '\0';

        printf("Digite o telefone do contato: ");
        fgets(telefone, sizeof(telefone), stdin);
        telefone[strcspn(telefone, "\n")] = '\0'; 

        Contato *novoContato = criarContato(nome, email, telefone);
        if (novoContato != NULL) {
            inserirOrdenado(&lista, novoContato);
        }

        printf("Deseja inserir outro contato? (s/n): ");
        scanf(" %c", &continuar);
        getchar();

    } while (continuar == 's' || continuar == 'S');

    /* Imprimir todos os contatos da lista */
    printf("\nLista de Contatos:\n");
    imprimirContatos(&lista);
}
