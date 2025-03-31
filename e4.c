// Faça um programa que receba do usuário um arquivo texto e 
// um caracter. Mostre na tela quantas vezes aquele caractere
// ocorre dentro do arquivo.

#include <stdio.h>
#include <string.h>
#define MAX 101

int main() {
    // declaração de uma string e de um ponteiro do arquivo
    char string[MAX];
    FILE *arq;

    // abertura do arquivo para escrita
    arq = fopen("contar-caracteres.txt", "w");

    // checa se o arquivo foi aberto corretamente
    if (arq == NULL) {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }

    // leitura do texto e do caractere a ser contado
    printf("Digite o texto (maximo %d caracteres): ", MAX - 1);
    fgets(string, sizeof(string), stdin);

    printf("Digite o caractere a ser contado: ");
    char caractere;
    scanf(" %c", &caractere);

    // contar quantas vezes o caracter aparece no texto
    int contador = 0;
    int i;

    for (i = 0; i < (int)strlen(string); i++){
        if (string[i] == caractere) {
            contador++;
        }
    }

    // fechar o arquivo
    fclose(arq);

    // mostrar o numero de vezes que o caracter aparece no texto
    printf("O caractere '%c' aparece %d vezes no texto. =)\n", caractere, contador);

    return 0;
}