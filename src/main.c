#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    ListaContatos lista;
    Contato *novoContato;
    char nome[100];
    char email[100];
    char telefone[20];
    char continuar;
    int opcao;

    inicializaLista(&lista);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir contato\n");
        printf("2. Remover contato\n");
        printf("3. Consultar contato\n");
        printf("4. Listar todos os contatos\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
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
                break;

            case 2:
                /* Remover contato */
                {
                    int pos;

                    printf("\nLista de Contatos:\n");
                    imprimeContatos(&lista);

                    printf("Digite a posição do contato a ser removido (começando em 1): ");
                    scanf("%d", &pos);
                    getchar(); 

                    if (!removeContato(&lista, pos - 1)) {
                        printf("Não foi possível remover o contato na posição %d.\n", pos);
                    }
                    
                    break;
                }
                break;

            case 3:
                /* Consultar contato específico */
                {
                    int pos;
                    printf("Digite a posição do contato a ser consultado (começando em 1): ");
                    scanf("%d", &pos);
                    getchar(); 

                    if (!consultaContato(&lista, pos - 1)) {
                        printf("Contato na posição %d não encontrado.\n", pos);
                    }
                    
                    break;
                }
            case 4:
                /* Listar todos os contatos */
                printf("\nLista de Contatos:\n");
                imprimeContatos(&lista);
                break;

            case 5:
                printf("\nSaindo...\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }
    return 0;
}
