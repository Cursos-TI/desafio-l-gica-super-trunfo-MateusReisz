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
    printf(" \n");
}

// Compara as cartas com base no atributo "densidade populacional"
void comparaAtributo(struct Carta c1, struct Carta c2){
    printf("Comparacao de cartas (Atributo: Densidade)\n");
    printf("Carta 1 - %s (%s): %.2f hab/km\n", c1.cidade, c1.estado, c1.densidade);
    printf("Carta 2 - %s (%s): %.2f hab/km\n", c2.cidade, c2.estado, c2.densidade);
    printf(" \n");

    if (c1.densidade < c2.densidade){
        printf("Carta 1 (%s) venceu!\n", c1.cidade);
    } else if (c1.densidade > c2.densidade){
        printf("Carta 2 (%s) venceu!\n", c2.cidade);
    } else {
        printf("Empate! As cartas têm a mesma Densidade Populacional.\n");
    }
    printf(" \n");
}

// Função principal do programa
int main() {
    struct Carta carta1, carta2; // Declara duas cartas

    // Entrada de dados para a primeira carta
    printf("Cadastro da Carta 1:\n");
    preencherCarta(&carta1);
    calcDensidadePopulacional(&carta1);
    calcPib(&carta1);

    // Entrada de dados para a segunda carta
    printf("Cadastro da Carta 2:\n");
    preencherCarta(&carta2);
    calcDensidadePopulacional(&carta2);
    calcPib(&carta2);

    // Exibe todas as informações cadastradas
    printf("=== Dados das Cartas Cadastradas ===\n\n");
    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    // Faz a comparação entre as duas cartas
    printf("=== Comparando as Cartas ===\n\n");
    comparaAtributo(carta1, carta2);

    return 0;
}