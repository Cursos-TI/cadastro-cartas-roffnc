/**
 * author:         Rodolfo Francisco <github.com/roffnc>
 * created:        26.09.2025
 * modified:       04.10.2025
 * course:         DGT0232
 * challenge:      Cartas Super Trunfo
 * level:          Mestre
 * version:        1.0.0
 * description:    Compara os atributos de duas cartas
 *
 * --------------------------------------------------------------------------------
 * 
 * MIT License
 * 
 * Copyright (c) 2025 Rodolfo Francisco
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
**/

// bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// constantes
#define TAMANHO_CODIGO 4
#define TAMANHO_CIDADE 33

// estrutura para representar uma carta
typedef struct {
    char estado, codigo[TAMANHO_CODIGO], cidade[TAMANHO_CIDADE];
    unsigned long populacao;
    int pontos_turisticos;
    float area, pib, densidade_populacional, pib_per_capita, super_poder;
} Carta;

// limpa o buffer de entrada
void limpar_buffer(void) {
    // consome caracteres restantes no buffer de entrada até a nova linha
    scanf("%*[^\n]");
    scanf("%*c");
}

// limpa a tela do console
void limpar_tela(void) {
    printf("\x1b[2J\x1b[H");
}

// ler os dados de uma carta
void ler_dados_carta(Carta *carta, int numero_carta) {
    printf("Carta %d:\n", numero_carta);

    printf("Digite a letra do Estado (A-H): ");
    scanf(" %c", &carta->estado);
    limpar_buffer();

    printf("Digite o código (ex: A01) da carta: ");
    scanf("%3s", carta->codigo); // usa %3s para evitar buffer overflow
    limpar_buffer();

    printf("Digite o nome da cidade: ");
    fgets(carta->cidade, TAMANHO_CIDADE, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = '\0'; // remove a nova linha

    printf("Digite o número de habitantes da cidade: ");
    scanf("%lu", &carta->populacao);
    limpar_buffer();

    printf("Digite a área em quilômetros quadrados: ");
    scanf("%f", &carta->area);
    limpar_buffer();

    printf("Digite o PIB em bilhões de reais: ");
    scanf("%f", &carta->pib);
    limpar_buffer();

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// calcula os atributos derivados de uma carta
void calcular_atributos_carta(Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->pib * 1e9) / carta->populacao;
    carta->super_poder = (carta->pib_per_capita * carta->pontos_turisticos) / carta->densidade_populacional;
}

// imprime os dados de uma carta
void imprimir_carta(const Carta *carta, int numero_carta) {
    printf("Carta %d:\n", numero_carta);
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->cidade);
    printf("População: %lu\n", carta->populacao);
    printf("Área: %.2f km²\n", carta->area);
    printf("PIB: R$ %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta->densidade_populacional);
    printf("PIB per Capita: R$ %.2f reais\n", carta->pib_per_capita);
    printf("Super Poder: %.2f\n\n", carta->super_poder);
}

// compara as cartas e anuncia os vencedores de cada categoria
void comparar_cartas(const Carta *carta1, const Carta *carta2) {
    printf("Comparação de Cartas:\n");

    const char* vencedores[] = {"Carta 2 venceu", "Carta 1 venceu"};

    // comparações que utilizam o resultado de uma expressão booleana (0 ou 1)
    // como índice para selecionar a string do vencedor
    printf("População: %s\n", vencedores[carta1->populacao > carta2->populacao]);
    printf("Área: %s\n", vencedores[carta1->area > carta2->area]);
    printf("PIB: %s\n", vencedores[carta1->pib > carta2->pib]);
    printf("Pontos Turísticos: %s\n", vencedores[carta1->pontos_turisticos > carta2->pontos_turisticos]);
    printf("Densidade Populacional: %s\n", vencedores[carta1->densidade_populacional < carta2->densidade_populacional]);
    printf("PIB per Capita: %s\n", vencedores[carta1->pib_per_capita > carta2->pib_per_capita]);
    printf("Super Poder: %s\n", vencedores[carta1->super_poder > carta2->super_poder]);
}

// função principal
int main(void) {
    Carta carta1, carta2;

    ler_dados_carta(&carta1, 1);
    limpar_buffer(); // limpa o buffer após a última leitura da carta 1
    limpar_tela(); // limpa a tela após a leitura da carta 1

    ler_dados_carta(&carta2, 2);
    limpar_buffer(); // limpa o buffer após a última leitura da carta 2
    limpar_tela(); // limpa a tela após a leitura da carta 2

    calcular_atributos_carta(&carta1);
    calcular_atributos_carta(&carta2);

    imprimir_carta(&carta1, 1);
    imprimir_carta(&carta2, 2);

    comparar_cartas(&carta1, &carta2);

    return EXIT_SUCCESS;
}