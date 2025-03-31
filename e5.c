// Faça um programa que receba do usuário um arquivo texto. 
// Crie outro arquivo texto contendo o texto do arquivo de 
// entrada, mas com as vogais substituídas por ‘*’

#include <stdio.h>
#include <string.h>
#define MAX 101
int main() {
    // declaração de uma string e de um ponteiro do arquivo
    char string[MAX];
    FILE *arq; // ponteiro para o arquivo de entrada
    FILE *arq_saida; // ponteiro para o arquivo de saída

    // ler o arquivo de entrada
    arq = fopen("c:\\Users\\Natan\\OneDrive\\Documentos\\A - IFSUL ADS\\Estrutura de Dados\\manipulacao-arquivos\\texto-exemplo.txt", "r");

    // verificar se o arquivo foi aberto corretamente
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }

    // abrir o arquivo de saída para escrita
    arq_saida = fopen("c:\\Users\\Natan\\OneDrive\\Documentos\\A - IFSUL ADS\\Estrutura de Dados\\manipulacao-arquivos\\texto-exemplo-vogais-substituidas.txt", "w");

    // verificar se o arquivo de saída foi aberto corretamente
    if (arq_saida == NULL) {
        printf("Erro ao abrir o arquivo de saída\n");
        fclose(arq); // fechar o arquivo de entrada antes de sair
        return 1;
    }

    // ler o arquivo caractere por caractere
    while (fgets(string, sizeof(string), arq) != NULL) {
        // verificar se o caractere é uma vogal
        int i; // declarar a variável fora do loop
        for (i = 0; i < (int)strlen(string); i++) { // converter strlen para int
            if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
                string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
                // substituir a vogal por '*'
                string[i] = '*';
            }
        }
        // escrever a linha modificada no arquivo de saída
        fputs(string, arq_saida);
    }

    // fechar os arquivos
    fclose(arq);
    fclose(arq_saida);

    // mensagem de sucesso
    printf("Arquivo de saida criado com sucesso!\n");
    printf("O arquivo de entrada foi lido e as vogais foram substituidas por '*'.\n");
    printf("O arquivo de saida foi salvo como 'texto-exemplo-saida.txt'.\n");
    
    return 0;
}