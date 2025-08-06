#include <stdio.h>

// Estrutura que representa uma carta do jogo com informações de uma cidade
struct Carta {
    char estado[3];
    char codigo[5];
    char cidade[50];
    unsigned long int populacao;
    double area;
    double pib;
    int turistico;
    double densidade;
    double per_capita;
    double super_power;
};

// Função que preenche os dados da carta (cidade) via entrada do usuário
void preencherCarta(struct Carta *carta){
    printf("Informe o Estado: ");
    scanf(" %2s", carta->estado);

    printf("Informe o Codigo: ");
    scanf(" %4s", carta->codigo);

    printf("Informe a Cidade: ");
    scanf(" %49[^\n]", carta->cidade);

    printf("Informe a Populacao: ");
    scanf("%lu", &carta->populacao);

    printf("Informe a Area em km: ");
    scanf("%lf", &carta->area);

    printf("Informe o Pib (em milhoes): ");
    scanf("%lf", &carta->pib);

    printf("Informe a quantidade de pontos turisticos: ");
    scanf("%d", &carta->turistico);

    printf(" \n");
}

// Calcula e armazena a densidade populacional (hab/km)
double calcDensidadePopulacional(struct Carta *carta){
    if (carta->area != 0.0){
        carta->densidade = carta->populacao / carta->area;
    } else {
        carta->densidade = 0.0;
        printf("Atenção: Area da cidade é zero! Densidade definida como 0.\n");
    }

    return carta->densidade;
}

// Calcula e armazena o PIB per capita (em reais por habitante)
double calcPib(struct Carta *carta){
    if (carta->populacao != 0){
        carta->per_capita = (carta->pib * 1e6) / carta->populacao;
    } else {
        carta->per_capita = 0.0;
        printf("Atenção: População da cidade é zero! PIB per capita definido como 0.\n");
    }
    
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
    printf("Area: %.2lf km\n", carta.area);
    printf("PIB: %.2lf milhoes de reais\n", carta.pib);
    printf("Numero de Pontos Turisticos: %d\n", carta.turistico);
    printf("Densidade Populacional: %.2lf hab/km\n", carta.densidade);
    printf("PIB per Capita: %.2lf reais\n", carta.per_capita);
    printf("Super Poder: %.2lf\n", carta.super_power);
    printf(" \n");
}

// Calcula o super poder baseado nos atributos
void calculaSuperPower(struct Carta *carta){
    if (carta == NULL) {
        printf("Erro: ponteiro nulo para carta!\n");
        return;
    }

    double invDensidade = 0.0;

    if (carta->densidade != 0.0){
        invDensidade = 1.0 / carta->densidade;
    } else {
        printf("Atenção: Densidade Populacional é zero! Inverso da Densidade definido como 0.\n");
    }

    carta->super_power =
        (double)carta->populacao +
        carta->area +
        (carta->pib * 1e6) +
        (double)carta->turistico +
        invDensidade +
        carta->per_capita;
}

// Compara as cartas com base no atributo selecionado
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
                printf("Empate! As cartas têm o mesmo valor no atributo escolhido!\n");
            }
            break;
        case 2:
            if (c1.area > c2.area){
                printf("Atributo: Area\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %.2lf km\n", c1.cidade, c1.estado, c1.area);
            } else if (c1.area < c2.area){
                printf("Atributo: Area\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %.2lf km\n", c2.cidade, c2.estado, c2.area);
            } else{
                printf("Empate! As cartas têm o mesmo valor no atributo escolhido!\n");
            }
            break;
        case 3:
            if (c1.pib > c2.pib){
                printf("Atributo: PIB\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %.2lf milhoes de reais\n", c1.cidade, c1.estado, c1.pib);
            } else if (c1.pib < c2.pib){
                printf("Atributo: PIB\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %.2lf milhoes de reais\n", c2.cidade, c2.estado, c2.pib);
            } else{
                printf("Empate! As cartas têm o mesmo valor no atributo escolhido!\n");
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
                printf("Empate! As cartas têm o mesmo valor no atributo escolhido!\n");
            }
            break;
        case 5:
            if (c1.densidade < c2.densidade){
                printf("Atributo: Densidade Populacional\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %.2lf hab/km\n", c1.cidade, c1.estado, c1.densidade);
            } else if (c1.densidade > c2.densidade){
                printf("Atributo: Densidade Populacional\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %.2lf hab/km\n", c2.cidade, c2.estado, c2.densidade);
            } else {
                printf("Empate! As cartas têm a mesma Densidade Populacional.\n");
            }
            break;
        case 6:
            if (c1.super_power > c2.super_power){
                printf("Atributo: Super Poder\n");
                printf("Carta 1 - %s venceu!\n", c1.cidade);
                printf("Carta 1 - %s (%s): %.2lf power\n", c1.cidade, c1.estado, c1.super_power);    
            } else if (c1.super_power < c2.super_power){
                printf("Atributo: Super Poder\n");
                printf("Carta 2 - %s venceu!\n", c2.cidade);
                printf("Carta 2 - %s (%s): %.2lf power\n", c2.cidade, c2.estado, c2.super_power);
            } else {
                printf("Empate! As cartas têm o mesmo poder.\n");
            }
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

// Função principal
int main() {
    struct Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    preencherCarta(&carta1);
    calcDensidadePopulacional(&carta1);
    calcPib(&carta1);
    calculaSuperPower(&carta1);

    printf("Cadastro da Carta 2:\n");
    preencherCarta(&carta2);
    calcDensidadePopulacional(&carta2);
    calcPib(&carta2);
    calculaSuperPower(&carta2);

    printf("=== Dados das Cartas Cadastradas ===\n\n");
    mostrarCarta(carta1, 1);
    mostrarCarta(carta2, 2);

    comparaAtributo(carta1, carta2);

    return 0;
}
