#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// função para limpar o buffer de entrada do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// função para limpar a tela do console
void limpar_tela() {
    system("cls || clear");
}

int main() {
    // variáveis das cartas
    char estado_1, estado_2, codigo_1[4], codigo_2[4], cidade_1[33], cidade_2[33];
    unsigned long int populacao_1, populacao_2;
    int pontos_turisticos_1, pontos_turisticos_2;
    float area_1, area_2, pib_1, pib_2, densidade_populacional_1, densidade_populacional_2, pib_per_capita_1, pib_per_capita_2, super_poder_1, super_poder_2;

    // entrada de dados da carta 1
    printf("Carta 1:\n");
    printf("Digite a letra do Estado (A-H): ");
    scanf(" %c", &estado_1);
    limpar_buffer();
    
    printf("Digite o código (ex: A01) da carta: ");
    scanf("%s", codigo_1);
    limpar_buffer();
    
    printf("Digite o nome da cidade: ");
    fgets(cidade_1, sizeof(cidade_1), stdin);
    cidade_1[strcspn(cidade_1, "\n")] = 0; // remove a nova linha
    
    printf("Digite o número de habitantes da cidade: ");
    scanf("%lu", &populacao_1); // modificador %lu para unsigned long int
    limpar_buffer();
    
    printf("Digite a área em quilômetros quadrados: ");
    scanf("%f", &area_1);
    limpar_buffer();
    
    printf("Digite o Produto Interno Bruto da cidade: ");
    scanf("%f", &pib_1);
    limpar_buffer();
    
    printf("Digite a quantidade de pontos turísticos na cidade: ");
    scanf("%d", &pontos_turisticos_1); // modificador %d para int
    limpar_buffer();

    limpar_tela();

    // entrada de dados da carta 2
    printf("Carta 2:\n");
    printf("Digite a letra do Estado (A-H): ");
    scanf(" %c", &estado_2);
    limpar_buffer();

    printf("Digite o código (ex: B02) da carta: ");
    scanf("%s", codigo_2);
    limpar_buffer();

    printf("Digite o nome da cidade: ");
    fgets(cidade_2, sizeof(cidade_2), stdin);
    cidade_2[strcspn(cidade_2, "\n")] = 0; // remove a nova linha

    printf("Digite o número de habitantes da cidade: ");
    scanf("%lu", &populacao_2); // modificador %lu para unsigned long int
    limpar_buffer();

    printf("Digite a área em quilômetros quadrados: ");
    scanf("%f", &area_2);
    limpar_buffer();

    printf("Digite o Produto Interno Bruto da cidade: ");
    scanf("%f", &pib_2);
    limpar_buffer();

    printf("Digite a quantidade de pontos turísticos na cidade: ");
    scanf("%d", &pontos_turisticos_2); // modificador %d para int
    limpar_buffer();

    limpar_tela();
    
    // cálculo da densidade populacional
    densidade_populacional_1 = (float)populacao_1 / area_1;
    densidade_populacional_2 = (float)populacao_2 / area_2;
    
    // cálculo do pib per capita
    pib_per_capita_1 = (pib_1 * 1000000000) / populacao_1;
    pib_per_capita_2 = (pib_2 * 1000000000) / populacao_2;

    // cálculo do super poder
    super_poder_1 = (float)populacao_1 + area_1 + pib_1 + (float)pontos_turisticos_1 + pib_per_capita_1 + (1 / densidade_populacional_1);
    super_poder_2 = (float)populacao_2 + area_2 + pib_2 + (float)pontos_turisticos_2 + pib_per_capita_2 + (1 / densidade_populacional_2);
    
    // saída de dados da carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado_1);
    printf("Código: %s\n", codigo_1);
    printf("Nome da Cidade: %s\n", cidade_1);
    printf("População: %lu\n", populacao_1);
    printf("Área: %.2f km²\n", area_1);
    printf("PIB: %.2f bilhões de reais\n", pib_1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos_1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional_1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita_1);
    printf("Super Poder: %.2f\n\n", super_poder_1);

    // saída de dados da carta 2
    printf("CARTA 2:\n");
    printf("Estado: %c\n", estado_2);
    printf("Código: %s\n", codigo_2);
    printf("Nome da Cidade: %s\n", cidade_2);
    printf("População: %lu\n", populacao_2);
    printf("Área: %.2f km²\n", area_2);
    printf("PIB: %.2f bilhões de reais\n", pib_2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos_2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional_2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita_2);
    printf("Super Poder: %.2f\n\n", super_poder_2);
    
    printf("Comparação de Cartas:\n");
    // comparação de população (maior vence)
    int vitoria_populacao = populacao_1 > populacao_2;
    printf("População: Carta %d venceu (%d)\n", vitoria_populacao ? 1 : 2, vitoria_populacao);

    // comparação de área (maior vence)
    int vitoria_area = area_1 > area_2;
    printf("Área: Carta %d venceu (%d)\n", vitoria_area ? 1 : 2, vitoria_area);

    // comparação de pib (maior vence)
    int vitoria_pib = pib_1 > pib_2;
    printf("PIB: Carta %d venceu (%d)\n", vitoria_pib ? 1 : 2, vitoria_pib);

    // comparação de pontos turísticos (maior vence)
    int vitoria_pontos = pontos_turisticos_1 > pontos_turisticos_2;
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", vitoria_pontos ? 1 : 2, vitoria_pontos);

    // comparação de densidade populacional (menor vence)
    int vitoria_densidade = densidade_populacional_1 < densidade_populacional_2;
    printf("Densidade Populacional: Carta %d venceu (%d)\n", vitoria_densidade ? 1 : 2, vitoria_densidade);

    // comparação de pib per capita (maior vence)
    int vitoria_pib_per_capita = pib_per_capita_1 > pib_per_capita_2;
    printf("PIB per Capita: Carta %d venceu (%d)\n", vitoria_pib_per_capita ? 1 : 2, vitoria_pib_per_capita);

    // comparação de super poder (maior vence)
    int vitoria_super_poder = super_poder_1 > super_poder_2;
    printf("Super Poder: Carta %d venceu (%d)\n", vitoria_super_poder ? 1 : 2, vitoria_super_poder);

    return 0;
}
