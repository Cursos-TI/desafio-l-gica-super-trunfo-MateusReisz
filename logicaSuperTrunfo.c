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

//escolhe atributo
int escolherAtributo(int excluido){
    int opcao;
    printf("\nEscolha um atributo:\n");
    if (excluido != 1) printf("1 - Populacao\n");
    if (excluido != 2) printf("2 - Area\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turisticos\n");
    if (excluido != 5) printf("5 - Densidade Demografica\n");
    if (excluido != 6) printf("6 - Super Poder\n");

    printf("Opcao: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 6 || opcao == excluido){
        printf("Opcao invalida! Tente novamente.\n");
        return escolherAtributo(excluido);
    }

    return opcao;
}

double pegarValor(struct Carta c, int atributo){
    switch(atributo){
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.turistico;
        case 5: return c.densidade; // menor vence
        case 6: return c.super_power;
        default: return 0;
    }
}

// Compara as cartas com base em 2 atributos selecionados
void compararDoisAtributos(struct Carta c1, struct Carta c2){
    int att1 = escolherAtributo(-1);
    int att2 = escolherAtributo(att1);

    double val1_att1 = pegarValor(c1, att1);
    double val2_att1 = pegarValor(c2, att1);
    double val1_att2 = pegarValor(c1, att2);
    double val2_att2 = pegarValor(c2, att2);

    // regra da densidade: menor vence
    double ponto1_att1 = (att1==5) ? ((val1_att1 < val2_att1) ? 1 : 0) : ((val1_att1 > val2_att1) ? 1 : 0);
    double ponto1_att2 = (att2==5) ? ((val1_att2 < val2_att2) ? 1 : 0) : ((val1_att2 > val2_att2) ? 1 : 0);

    double soma1 = val1_att1 + val1_att2;
    double soma2 = val2_att1 + val2_att2;

    printf("\n--- Resultado da Comparacao ---\n");
    printf("Carta 1: %s\n", c1.cidade);
    printf("Carta 2: %s\n", c2.cidade);
    printf("Atributos escolhidos: %d e %d\n", att1, att2);
    printf("Valores Carta 1: %.2lf, %.2lf | Soma: %.2lf\n", val1_att1, val1_att2, soma1);
    printf("Valores Carta 2: %.2lf, %.2lf | Soma: %.2lf\n", val2_att1, val2_att2, soma2);

    (soma1 > soma2) ? printf("Carta 1 venceu!\n") :
    (soma2 > soma1) ? printf("Carta 2 venceu!\n") :
                       printf("Empate!\n");
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

    compararDoisAtributos(carta1, carta2);

    return 0;
}