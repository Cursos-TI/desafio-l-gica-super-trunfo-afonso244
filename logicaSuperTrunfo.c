#include <stdio.h>

// Definição da estrutura para armazenar os atributos de cada cidade
typedef struct {
    char estado[2];
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
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Digite sua escolha: ");
}

void exibir_atributos(Cidade cidade) {
    printf("\n==================================\n");
    printf("       Atributos da Cidade       \n");
    printf("==================================\n");
    printf("Estado: %s\n", cidade.estado);
    printf("Código: %s\n", cidade.codigo);
    printf("Nome: %s\n", cidade.nome);
    printf("População: %d habitantes\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões de reais\n", cidade.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("PIB per Capita: %.2f\n", cidade.pib_per_capita);
    printf("Densidade: %.2f habitantes/km²\n", cidade.densidade);
    printf("Super Poder: %.2f\n", cidade.superpoder);
    printf("==================================\n");
}

void comparar_cidades(Cidade cidade1, Cidade cidade2, int escolha) {
    switch (escolha) {
        case 1: // Comparar População
            printf("\nComparando População:\n");
            printf("%s: %d habitantes\n", cidade1.nome, cidade1.populacao);
            printf("%s: %d habitantes\n", cidade2.nome, cidade2.populacao);
            if (cidade1.populacao > cidade2.populacao)
                printf("Vencedor: %s\n", cidade1.nome);
            else if (cidade1.populacao < cidade2.populacao)
                printf("Vencedor: %s\n", cidade2.nome);
            else
                printf("Empate!\n");
            break;

        case 2: // Comparar Área
            printf("\nComparando Área:\n");
            printf("%s: %.2f km²\n", cidade1.nome, cidade1.area);
            printf("%s: %.2f km²\n", cidade2.nome, cidade2.area);
            if (cidade1.area > cidade2.area)
                printf("Vencedor: %s\n", cidade1.nome);
            else if (cidade1.area < cidade2.area)
                printf("Vencedor: %s\n", cidade2.nome);
            else
                printf("Empate!\n");
            break;

        case 3: // Comparar PIB
            printf("\nComparando PIB:\n");
            printf("%s: %.2f bilhões de reais\n", cidade1.nome, cidade1.pib);
            printf("%s: %.2f bilhões de reais\n", cidade2.nome, cidade2.pib);
            if (cidade1.pib > cidade2.pib)
                printf("Vencedor: %s\n", cidade1.nome);
            else if (cidade1.pib < cidade2.pib)
                printf("Vencedor: %s\n", cidade2.nome);
            else
                printf("Empate!\n");
            break;

        case 4: // Comparar Pontos Turísticos
            printf("\nComparando Pontos Turísticos:\n");
            printf("%s: %d pontos turísticos\n", cidade1.nome, cidade1.pontos_turisticos);
            printf("%s: %d pontos turísticos\n", cidade2.nome, cidade2.pontos_turisticos);
            if (cidade1.pontos_turisticos > cidade2.pontos_turisticos)
                printf("Vencedor: %s\n", cidade1.nome);
            else if (cidade1.pontos_turisticos < cidade2.pontos_turisticos)
                printf("Vencedor: %s\n", cidade2.nome);
            else
                printf("Empate!\n");
            break;

        case 5: // Comparar Densidade Demográfica (menor valor vence)
            printf("\nComparando Densidade Demográfica:\n");
            printf("%s: %.2f habitantes/km²\n", cidade1.nome, cidade1.densidade);
            printf("%s: %.2f habitantes/km²\n", cidade2.nome, cidade2.densidade);
            if (cidade1.densidade < cidade2.densidade)
                printf("Vencedor: %s\n", cidade1.nome);
            else if (cidade1.densidade > cidade2.densidade)
                printf("Vencedor: %s\n", cidade2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Escolha um número entre 1 e 5.\n");
    }
}

int main() {
    Cidade cidade1, cidade2;
    int escolha;

    // Cadastro da primeira cidade
    printf("\n--- Cadastro da Primeira Cidade ---\n");
    printf("Digite o estado da primeira cidade (A-H): ");
    scanf(" %s", cidade1.estado);
    printf("Digite o código da primeira cidade (Ex: A01): ");
    scanf(" %s", cidade1.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %s", cidade1.nome);
    printf("Digite a população da cidade: ");
    scanf("%d", &cidade1.populacao);
    printf("Digite a área da cidade em km²: ");
    scanf("%f", &cidade1.area);
    printf("Digite o PIB da cidade em bilhões: ");
    scanf("%f", &cidade1.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade1.pontos_turisticos);

    cidade1.pib_per_capita = cidade1.pib / cidade1.populacao;
    cidade1.densidade = cidade1.populacao / cidade1.area;
    cidade1.superpoder = cidade1.populacao + cidade1.area + cidade1.pib + cidade1.pontos_turisticos + cidade1.pib_per_capita + (1 / cidade1.densidade);

    // Cadastro da segunda cidade
    printf("\n--- Cadastro da Segunda Cidade ---\n");
    printf("Digite o estado da segunda cidade (A-H): ");
    scanf(" %s", cidade2.estado);
    printf("Digite o código da segunda cidade (Ex: B02): ");
    scanf(" %s", cidade2.codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %s", cidade2.nome);
    printf("Digite a população da cidade: ");
    scanf("%f", &cidade2.populacao);
    printf("Digite a área da cidade em km²: ");
    scanf("%f", &cidade2.area);
    printf("Digite o PIB da cidade em bilhões: ");
    scanf("%f", &cidade2.pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade2.pontos_turisticos);

    cidade2.pib_per_capita = cidade2.pib / cidade2.populacao;
    cidade2.densidade = cidade2.populacao / cidade2.area;
    cidade2.superpoder = cidade2.populacao + cidade2.area + cidade2.pib + cidade2.pontos_turisticos + cidade2.pib_per_capita + (1 / cidade2.densidade);

    // Exibir atributos de ambas as cidades
    printf("\n--- Atributos da Primeira Cidade ---\n");
    exibir_atributos(cidade1);

    printf("\n--- Atributos da Segunda Cidade ---\n");
    exibir_atributos(cidade2);

    // Exibir menu e comparar as cartas
    exibir_menu();
    scanf("%d", &escolha);
    comparar_cidades(cidade1, cidade2, escolha);

    return 0;
}
