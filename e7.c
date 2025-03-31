// Faça um programa que receba dois arquivos do usuário, e crie um terceiro arquivo 
// com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do 
// conteúdo do segundo).

#include <stdio.h>
#include <string.h>

#define MAX 101

int main() {
    // declaração de uma string e de um ponteiro do arquivo
    char string[MAX];
    FILE *arq1, *arq2, *arq_saida; // ponteiros para os arquivos de entrada e saída

    // abrindo os arquivos de entrada
    arq1 = fopen("arquivo1.txt", "r");
    if (arq1 == NULL) {
        // Se o arquivo não existir, cria um novo arquivo para escrita
        arq1 = fopen("arquivo1.txt", "w");
        if (arq1 == NULL) {
            printf("Erro ao criar o arquivo 1\n");
            return 1;
        }
        // Escreve um conteúdo inicial no arquivo
        fprintf(arq1, "Conteúdo inicial do arquivo 1.\n");
        fclose(arq1);

        // Reabre o arquivo para leitura
        arq1 = fopen("arquivo1.txt", "r");
        if (arq1 == NULL) {
            printf("Erro ao reabrir o arquivo 1\n");
            return 1;
        }
    }
    if (arq1 == NULL) {
        printf("Erro ao abrir o arquivo 1\n");
        return 1;
    }

    arq2 = fopen("arquivo2.txt", "r");
    if (arq2 == NULL) {
        // Se o arquivo não existir, cria um novo arquivo para escrita
        arq2 = fopen("arquivo2.txt", "w");
        if (arq2 == NULL) {
            printf("Erro ao criar o arquivo 2\n");
            fclose(arq1); // fechar o arquivo 1 antes de sair
            return 1;
        }
        // Escreve um conteúdo inicial no arquivo
        fprintf(arq2, "Conteúdo inicial do arquivo 2.\n");
        fclose(arq2);

        // Reabre o arquivo para leitura
        arq2 = fopen("arquivo2.txt", "r");
        if (arq2 == NULL) {
            printf("Erro ao reabrir o arquivo 2\n");
            fclose(arq1); // fechar o arquivo 1 antes de sair
            return 1;
        }
    }

    // unificando os arquivos em um terceiro arquivo
    arq_saida = fopen("arquivo_saida.txt", "w");
    if (arq_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída\n");
        fclose(arq1); // fechar o arquivo 1 antes de sair
        fclose(arq2); // fechar o arquivo 2 antes de sair
        return 1;
    }

    // ler o arquivo 1 e escrever no arquivo de saída
    while (fgets(string, sizeof(string), arq1) != NULL) {
        fputs(string, arq_saida);
    }

    // ler o arquivo 2 e escrever no arquivo de saída
    while (fgets(string, sizeof(string), arq2) != NULL) {
        fputs(string, arq_saida);
    }

    // fechar os arquivos
    fclose(arq1);
    fclose(arq2);
    fclose(arq_saida);

    // mensagem de sucesso
    printf("Arquivos unidos com sucesso!\n");
    printf("O arquivo de saida foi salvo como 'arquivo_saida.txt'.\n");

    return 0;
}