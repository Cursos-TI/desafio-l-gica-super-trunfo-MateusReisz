#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa uma carta do jogo com informações de uma cidade
struct Carta {
    char estado[3];               // Sigla do estado (ex: "MG")
    char codigo[5];               
    char cidade[50];              
    unsigned long int populacao;  
    float area;                   
    float pib;                    
    int turistico;                
    float densidade;              
    float per_capita;
    float super_power;           
};

// Função que preenche os dados da carta (cidade) via entrada do usuário
void preencherCarta(struct Carta *carta){
    printf("Informe o Estado: ");
    scanf(" %2s", carta->estado); // Lê no máximo 2 caracteres (mais o '\0')

    printf("Informe o Codigo: ");
    scanf(" %4s", carta->codigo); // Lê no máximo 4 caracteres

    printf("Informe a Cidade: ");
    scanf(" %49[^\n]", carta->cidade); // Lê até 49 caracteres ou até '\n'

    printf("Informe a Populacao: ");
    scanf("%lu", &carta->populacao);

    printf("Informe a Area em km: ");
    scanf("%f", &carta->area);

    printf("Informe o Pib: ");
    scanf("%f", &carta->pib);

    printf("Informe a quantidade de pontos turisticos: ");
    scanf("%d", &carta->turistico);

    printf(" \n");
}

// Calcula e armazena a densidade populacional (hab/km²)
float calcDensidadePopulacional(struct Carta *carta){
    carta->densidade = carta->populacao / carta->area;
    return carta->densidade;
}

// Calcula e armazena o PIB per capita (em reais por habitante)
float calcPib(struct Carta *carta){
    // PIB está em milhões, então multiplica-se por 1 milhão
    carta->per_capita = (carta->pib * 1e6) / carta->populacao;
    return carta->per_capita;
}

// Exibe os dados completos de uma carta
void mostrarCarta(struct Carta carta, int numero){
    printf(" \n");
    printf("Carta %d:\n", numero);
    printf("Estado: %s\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("Populacao: %lu pessoas\n", carta.populacao);
    printf("Area: %.2f km\n", carta.area);
    printf("PIB: %.2f milhoes de reais\n", carta.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta.turistico);
    printf("Densidade Populacional: %.2f hab/km\n", carta.densidade);
    printf("PIB per Capita: %.2f reais\n", carta.per_capita);
    printf("Super Poder: %.2f\n", carta.super_power);
    printf(" \n");
}

// Calcula o super poder baseado nos atributos
void calculaSuperPower(struct Carta *carta){
    carta->super_power =
    (float)carta->populacao +
    carta->area +
    carta->pib +
    carta->turistico +
    (1.0f / carta->densidade) +
    carta->per_capita;
}

// Compara as cartas com base no atributo "densidade populacional"
void comparaAtributo(struct Carta c1, struct Carta c2){

    int opcao;
    printf("=== Comparacao de Cartas ====\n\n");
    printf("Atributos: \n");
    printf(" 1. -> Populacao\n");
    printf(" 2. -> Area\n");
    printf(" 3. -> PIB\n");
    printf(" 4. -> Numero de pontos turisticos\n");
    printf(" 5. -> Densidade demografica\n");
    printf(" 6. -> Super Poder\n");
    printf(" \n");
    printf("Informe sua opcao: \n");
    scanf("%d", &opcao);
    printf(" \n");
    printf("=== ~ === ~ ===\n");
    printf(" As cartas sao: \n");
    printf("Carta 1: %s\n", c1.cidade);
    printf("Carta 2: %s\n", c2.cidade);
    printf("=== ~ === ~ ===\n");
    printf(" \n");

    switch (opcao){
        case 1:
            if (c1.populacao > c2.populacao){
                printf("Atributo: Populacao\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %lu pessoas\n", c1.cidade, c1.estado, c1.populacao);
            } else if (c1.populacao < c2.populacao){
                printf("Atributo: Populacao\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %lu pessoas\n", c2.cidade, c2.estado, c2.populacao);
            } else {
                printf("Atributo: Populacao\n");
                printf("Empate! As cartas tem a mesmo valor no atributo escolhido!.\n");
            }
            break;
        case 2:
            if (c1.area > c2.area){
                printf("Atributo: Area\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %.2f km\n", c1.cidade, c1.estado, c1.area);
            } else if (c1.area < c2.area){
                printf("Atributo: Area\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %.2f km\n", c2.cidade, c2.estado, c2.area);
            } else{
                printf("Atributo: Area\n");
                printf("Empate! As cartas tem a mesmo valor no atributo escolhido!.\n");
            }
            break;
        case 3:
            if (c1.pib > c2.pib){
                printf("Atributo: PIB\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %.2f milhoes de reais\n", c1.cidade, c1.estado, c1.pib);
            } else if (c1.pib < c2.pib){
                printf("Atributo: PIB\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %.2f milhoes de reais\n", c2.cidade, c2.estado, c2.pib);
            } else{
                printf("Atributo: PIB\n");
                printf("Empate! As cartas tem a mesmo valor no atributo escolhido!.\n");
            }
            break;
        case 4:
            if (c1.turistico > c2.turistico){
                printf("Atributo: Ponto Turistico\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %d\n", c1.cidade, c1.estado, c1.turistico);
            } else if (c1.turistico < c2.turistico){
                printf("Atributo: Ponto Turistico\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %d\n", c2.cidade, c2.estado, c2.turistico);
            } else{
                printf("Atributo: Ponto Turistico\n");
                printf("Empate! As cartas tem a mesmo valor no atributo escolhido!.\n");
            }
            break;
        case 5:
            if (c1.densidade < c2.densidade){
                printf("Atributo: Densidade Populacional\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %.2f hab/km\n", c1.cidade, c1.estado, c1.densidade);
            } else if (c1.densidade > c2.densidade){
                printf("Atributo: Densidade Populacional\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %.2f hab/km\n", c2.cidade, c2.estado, c2.densidade);
            } else {
                printf("Atributo: Densidade Populacional\n");
                printf("Empate! As cartas têm a mesma Densidade Populacional.\n");
            }
        case 6:
            if (c1.super_power > c2.super_power){
                printf("Atributo: Super Poder\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %.2f power\n", c1.cidade, c1.estado, c1.super_power);    
            } else if (c1.densidade > c2.densidade){
                printf("Atributo: Super Poder\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %.2f power\n", c2.cidade, c2.estado, c2.super_power);
            } else {
                printf("Atributo: Super Poder\n");
                printf("Empate! As cartas têm a mesmo poder.\n");
            }
            break;
        default:
            printf("Opcao invalida!\n");
            break;  
        printf(" \n");
    }
}

// Função principal do programa
int main() {
    struct Carta carta1, carta2; // Declara duas cartas

    // Entrada de dados para a primeira carta
    printf("Cadastro da Carta 1:\n");
    preencherCarta(&carta1);
    calcDensidadePopulacional(&carta1);
    calcPib(&carta1);
    calculaSuperPower(&carta1);

    // Entrada de dados para a segunda carta
    printf("Cadastro da Carta 2:\n");
    preencherCarta(&carta2);
    calcDensidadePopulacional(&carta2);
    calcPib(&carta2);
    calculaSuperPower(&carta2);

    // Exibe todas as informações cadastradas
    printf("=== Dados das Cartas Cadastradas ===\n\n");
    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    // Faz a comparação entre as duas cartas
    comparaAtributo(carta1, carta2);

    return 0;
}