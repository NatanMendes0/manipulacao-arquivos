// Faça um programa que crie um arquivo TEXTO em disco, 
// com o nome “dados.txt”, e escreva neste arquivo 
// em disco uma contagem que vá de 1 até 100, com um 
// número em cada linha.

#include <stdio.h>
#include <string.h>

#define MAX 101
int main() {
    // declaração de uma string e de um ponteiro do arquivo
    char string[MAX];
    FILE *arq;

    // abertura do arquivo para escrita
    arq = fopen("dados.txt", "w");

    // checa se o arquivo foi aberto corretamente
    if (arq == NULL) {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }

    // declaração da variável do loop
    int i;
    // loop para escrever os números de 1 a 100 no arquivo
    for (i = 1; i <= 100; i++) {
        // formata a string com o número atual
        sprintf(string, "%d\n", i);
        // escreve a string no arquivo
        fputs(string, arq);
    }

    // fecha o arquivo
    fclose(arq);
    // mensagem de sucesso
    printf("Arquivo criado com sucesso!\n");
    return 0;
}