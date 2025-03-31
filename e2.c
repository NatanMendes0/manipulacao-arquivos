// Faça um programa que receba do usuário um arquivo texto e 
// mostre na tela quantas linhas esse arquivo possui.

#include <stdio.h>
#include <string.h>

#define MAX 101

int main() {
    
    //declaração de uma string e de um ponteiro do arquivo
    char string[MAX];
    FILE *arq;

    // abertura do arquivo somente leitura
    arq = fopen("dados.txt", "r");

    // verificar se o arquivo foi aberto corretamente
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    // contador de linhas
    int contador = 0;
    // ler o arquivo linha por linha
    while (fgets(string, sizeof(string), arq) != NULL) {
        // incrementar o contador para cada linha lida
        contador++;
    }

    // fechar o arquivo
    fclose(arq);

    // mostrar o numero de linhas
    printf("O arquivo possui %d linhas.\n", contador);

    return 0;
}