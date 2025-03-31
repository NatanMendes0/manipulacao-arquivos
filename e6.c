#include <stdio.h>
#include <stdlib.h>

#define NUM_ALUNOS 10

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float media;
} Aluno;

int main() {
    Aluno alunos[NUM_ALUNOS];
    FILE *arquivo;
    int i;

    // Leitura dos dados dos alunos
    for (i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf(" %[^\n]", alunos[i].nome);
        printf("Digite a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);
        printf("Digite a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);

        // Calcula a média
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2.0;
    }

    // Abre o arquivo para escrita
    arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    // Escreve os dados no arquivo
    for (i = 0; i < NUM_ALUNOS; i++) {
        fprintf(arquivo, "Nome: %s\n", alunos[i].nome);
        fprintf(arquivo, "Nota 1: %.2f\n", alunos[i].nota1);
        fprintf(arquivo, "Nota 2: %.2f\n", alunos[i].nota2);
        fprintf(arquivo, "Média: %.2f\n\n", alunos[i].media);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Dados dos alunos salvos no arquivo 'alunos.txt'.\n");

    return 0;
}