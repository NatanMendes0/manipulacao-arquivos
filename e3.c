// Faça um programa que receba do usuário um arquivo texto e 
// mostre na tela quantas letras são vogais.

#include <stdio.h>
#include <string.h>

#define MAX 101
int main() {

    // abertura de um arquivo de texto
    FILE *arq;
    arq = fopen("c:\\Users\\Natan\\OneDrive\\Documentos\\A - IFSUL ADS\\Estrutura de Dados\\manipulacao-arquivos\\texto-exemplo.txt", "r");

    // verificar se o arquivo foi aberto corretamente
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    // declaração de uma string e de um ponteiro do arquivo
    char string[MAX];
    // contador de vogais
    int contador = 0;
    // ler o arquivo caractere por caractere
    while (fgets(string, sizeof(string), arq) != NULL) {
        // verificar se o caractere é uma vogal
        int i; // declarar a variável fora do loop
        for (i = 0; i < (int)strlen(string); i++) { // converter strlen para int
            if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
                string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
                // incrementar o contador para cada vogal encontrada
                contador++;
            }
        }
    }

    // fechar o arquivo
    fclose(arq);

    // mostrar o numero de vogais
    printf("O arquivo possui %d vogais.\n", contador);
    
    return 0;
}