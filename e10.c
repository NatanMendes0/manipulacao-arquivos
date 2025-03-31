#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_PHONE 20

int main() {
    FILE *file;
    char name[MAX_NAME];
    char phone[MAX_PHONE];

    file = fopen("cadastro.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Cadastro de Nomes e Telefones\n");
    printf("Digite '0' no telefone para encerrar.\n");

    while (1) {
        printf("Nome: ");
        fgets(name, MAX_NAME, stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character

        printf("Telefone: ");
        fgets(phone, MAX_PHONE, stdin);
        phone[strcspn(phone, "\n")] = '\0'; // Remove newline character

        if (strcmp(phone, "0") == 0) {
            break;
        }

        fprintf(file, "%s, %s\n", name, phone);
    }

    fclose(file);
    printf("Cadastro salvo no arquivo 'cadastro.txt'.\n");

    return 0;
}