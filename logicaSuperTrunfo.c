#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura Cidade
typedef struct {
    char estado[3];
    char codigo[50];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float pib_per_capita;
    float densidade;
    float superpoder;
} Cidade;

void exibir_menu() {
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
}

void gerar_cidade_aleatoria(Cidade *cidade) {
    // Gerando dados aleatórios para a cidade
    cidade->populacao = rand() % 20000000 + 1000000;  // População entre 1M e 20M
    cidade->area = (rand() % 5000) + 100.0;  // Área entre 100 e 5000 km²
    cidade->pib = (rand() % 100000) + 1000.0;  // PIB entre 1000 e 100000 milhões
    cidade->pontos_turisticos = rand() % 100 + 1;  // Pontos turísticos entre 1 e 100
    cidade->pib_per_capita = cidade->pib / cidade->populacao;  // PIB per capita
    cidade->densidade = cidade->populacao / cidade->area;  // Densidade demográfica
    cidade->superpoder = rand() % 100 + 1;  // Superpoder entre 1 e 100
}

void comparar_cidades(Cidade cidade1, Cidade cidade2, int atributo1, int atributo2) {
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    
    // Determina os valores dos atributos escolhidos
    switch (atributo1) {
        case 1: valor1_c1 = cidade1.populacao; valor1_c2 = cidade2.populacao; break;
        case 2: valor1_c1 = cidade1.area; valor1_c2 = cidade2.area; break;
        case 3: valor1_c1 = cidade1.pib; valor1_c2 = cidade2.pib; break;
        case 4: valor1_c1 = cidade1.pontos_turisticos; valor1_c2 = cidade2.pontos_turisticos; break;
        case 5: valor1_c1 = cidade1.populacao / cidade1.area; valor1_c2 = cidade2.populacao / cidade2.area; break;
    }
    
    switch (atributo2) {
        case 1: valor2_c1 = cidade1.populacao; valor2_c2 = cidade2.populacao; break;
        case 2: valor2_c1 = cidade1.area; valor2_c2 = cidade2.area; break;
        case 3: valor2_c1 = cidade1.pib; valor2_c2 = cidade2.pib; break;
        case 4: valor2_c1 = cidade1.pontos_turisticos; valor2_c2 = cidade2.pontos_turisticos; break;
        case 5: valor2_c1 = cidade1.populacao / cidade1.area; valor2_c2 = cidade2.populacao / cidade2.area; break;
    }
    
    // Exibe os valores
    printf("\nComparacao entre %s e %s:\n", cidade1.nome, cidade2.nome);
    printf("Atributo 1: Cidade 1 = %.2f, Cidade 2 = %.2f\n", valor1_c1, valor1_c2);
    printf("Atributo 2: Cidade 1 = %.2f, Cidade 2 = %.2f\n", valor2_c1, valor2_c2);
    
    // Soma os atributos
    float soma_c1 = valor1_c1 + valor2_c1;
    float soma_c2 = valor1_c2 + valor2_c2;
    
    printf("Soma dos atributos: Cidade 1 = %.2f, Cidade 2 = %.2f\n", soma_c1, soma_c2);
    
    // Determina o vencedor
    if (soma_c1 > soma_c2)
        printf("VOCÊ VENCEU!!: %s\n", cidade1.nome);
    else if (soma_c1 < soma_c2)
        printf("VOCÊ PERDEU!!: %s\n", cidade2.nome);
    else
        printf("Empate!\n");
}

int main() {
    srand(time(0));  // Inicializa o gerador de números aleatórios
    
    Cidade cidade1 = {"SP", "A01", "Sao Paulo", 0, 0.0, 0.0, 0, 0.0, 0.0, 0};
    Cidade cidade2 = {"RJ", "B02", "Rio de Janeiro", 0, 0.0, 0.0, 0, 0.0, 0.0, 0};
    
    // Gerar cidades aleatórias
    gerar_cidade_aleatoria(&cidade1);
    gerar_cidade_aleatoria(&cidade2);
    
    // Exemplo de nomes para as cidades
    printf("Cidade 1: %s, Estado: %s\n", cidade1.nome, cidade1.estado);
    printf("Cidade 2: %s, Estado: %s\n", cidade2.nome, cidade2.estado);

    int escolha1, escolha2;
    
    // Menu para escolher o primeiro atributo
    exibir_menu();
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &escolha1);
    
    do {
        exibir_menu();
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &escolha2);
    } while (escolha1 == escolha2);
    
    comparar_cidades(cidade1, cidade2, escolha1, escolha2);
    
    return 0;
}

