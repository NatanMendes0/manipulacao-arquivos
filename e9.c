#include <stdio.h>
#include <stdlib.h>

void decryptFile(const char *inputFile, const char *outputFile, int key) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        // Descriptografar o caractere
        char decryptedChar = ch - key;
        fputc(decryptedChar, out);
    }

    fclose(in);
    fclose(out);
}

int main() {
    char inputFile[100], outputFile[100];
    int key;

    printf("Digite o nome do arquivo criptografado: ");
    scanf("%s", inputFile);

    printf("Digite o nome do arquivo para salvar o texto descriptografado: ");
    scanf("%s", outputFile);

    printf("Digite a chave de descriptografia: ");
    scanf("%d", &key);

    decryptFile(inputFile, outputFile, key);

    printf("Arquivo descriptografado com sucesso!\n");

    return 0;
}