#include <stdio.h>
#include <stdlib.h>

void encryptFile(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");

    if (inFile == NULL || outFile == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch + 1, outFile); // Soma 1 ao valor ASCII de cada caractere
    }

    fclose(inFile);
    fclose(outFile);
}

int main() {
    char inputFile[100], outputFile[100];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", inputFile);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", outputFile);

    encryptFile(inputFile, outputFile);

    printf("Arquivo criptografado com sucesso!\n");

    return 0;
}