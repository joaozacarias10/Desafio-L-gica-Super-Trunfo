#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    int codigo;
    char cidade[50];
    long populacao;
    float area;
    double pib;
    int pontos_turisticos;
} Carta;

// =====================================================
// NÍVEL NOVATO
// =====================================================
void nivelNovato() {
    Carta carta1, carta2;
    
    printf("=== Nivel Novato ===\n");
    printf("Cadastro da Carta 1:\n");
    printf("Estado: "); scanf("%s", carta1.estado);
    printf("Código: "); scanf("%d", &carta1.codigo);
    printf("Cidade: "); scanf("%s", carta1.cidade);
    printf("População: "); scanf("%ld", &carta1.populacao);
    printf("Área: "); scanf("%f", &carta1.area);
    printf("PIB: "); scanf("%lf", &carta1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta1.pontos_turisticos);

    printf("\nCadastro da Carta 2:\n");
    printf("Estado: "); scanf("%s", carta2.estado);
    printf("Código: "); scanf("%d", &carta2.codigo);
    printf("Cidade: "); scanf("%s", carta2.cidade);
    printf("População: "); scanf("%ld", &carta2.populacao);
    printf("Área: "); scanf("%f", &carta2.area);
    printf("PIB: "); scanf("%lf", &carta2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &carta2.pontos_turisticos);

    // Comparação de um atributo fixo: População
    printf("\nComparando População...\n");
    if(carta1.populacao > carta2.populacao)
        printf("Carta 1 (%s) vence!\n", carta1.cidade);
    else if(carta2.populacao > carta1.populacao)
        printf("Carta 2 (%s) vence!\n", carta2.cidade);
    else
        printf("Empate!\n");
}

// =====================================================
// NÍVEL AVENTUREIRO
// =====================================================
void nivelAventureiro() {
    Carta carta1, carta2;
    int opcao;

    printf("=== Nivel Aventureiro ===\n");

    // Cadastro rápido (simples)
    strcpy(carta1.cidade, "CidadeA"); carta1.populacao=100000; carta1.area=250.5; carta1.pib=5000; carta1.pontos_turisticos=10;
    strcpy(carta2.cidade, "CidadeB"); carta2.populacao=90000;  carta2.area=300.2; carta2.pib=4500; carta2.pontos_turisticos=15;

    printf("Escolha o atributo para comparar:\n1-População\n2-Área\n3-PIB\n4-Pontos Turísticos\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Comparando População...\n");
            if(carta1.populacao > carta2.populacao)
                printf("Carta 1 (%s) vence!\n", carta1.cidade);
            else if(carta2.populacao > carta1.populacao)
                printf("Carta 2 (%s) vence!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 2:
            printf("Comparando Área...\n");
            if(carta1.area > carta2.area)
                printf("Carta 1 (%s) vence!\n", carta1.cidade);
            else if(carta2.area > carta1.area)
                printf("Carta 2 (%s) vence!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 3:
            printf("Comparando PIB...\n");
            if(carta1.pib > carta2.pib)
                printf("Carta 1 (%s) vence!\n", carta1.cidade);
            else if(carta2.pib > carta1.pib)
                printf("Carta 2 (%s) vence!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        case 4:
            printf("Comparando Pontos Turísticos...\n");
            if(carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Carta 1 (%s) vence!\n", carta1.cidade);
            else if(carta2.pontos_turisticos > carta1.pontos_turisticos)
                printf("Carta 2 (%s) vence!\n", carta2.cidade);
            else
                printf("Empate!\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

// =====================================================
// NÍVEL MESTRE
// =====================================================
void nivelMestre() {
    Carta carta1, carta2;
    int attr1, attr2;

    printf("=== Nivel Mestre ===\n");

    // Cadastro rápido
    strcpy(carta1.cidade, "CidadeX"); carta1.populacao=120000; carta1.area=500.5; carta1.pib=8000; carta1.pontos_turisticos=20;
    strcpy(carta2.cidade, "CidadeY"); carta2.populacao=115000; carta2.area=480.2; carta2.pib=7500; carta2.pontos_turisticos=25;

    printf("Escolha dois atributos para comparação (1-Pop,2-Área,3-PIB,4-Pontos): ");
    scanf("%d %d", &attr1, &attr2);

    // Comparação usando ternário
    int pontos1 = 0, pontos2 = 0;

    pontos1 += (attr1==1 ? (carta1.populacao>carta2.populacao) : (carta1.populacao<carta2.populacao));
    pontos2 += (attr1==1 ? (carta2.populacao>carta1.populacao) : (carta2.populacao<carta1.populacao));
    
    pontos1 += (attr2==2 ? (carta1.area>carta2.area) : (carta1.area<carta2.area));
    pontos2 += (attr2==2 ? (carta2.area>carta1.area) : (carta2.area<carta1.area));

    pontos1 += (attr1==3 || attr2==3 ? (carta1.pib>carta2.pib) : 0);
    pontos2 += (attr1==3 || attr2==3 ? (carta2.pib>carta1.pib) : 0);

    pontos1 += (attr1==4 || attr2==4 ? (carta1.pontos_turisticos>carta2.pontos_turisticos) : 0);
    pontos2 += (attr1==4 || attr2==4 ? (carta2.pontos_turisticos>carta1.pontos_turisticos) : 0);

    printf("\nResultado Final:\n");
    pontos1 > pontos2 ? printf("Carta 1 (%s) vence!\n", carta1.cidade) :
    pontos2 > pontos1 ? printf("Carta 2 (%s) vence!\n", carta2.cidade) :
    printf("Empate!\n");
}

// =====================================================
// MAIN
// =====================================================
int main() {
    nivelNovato();
    nivelAventureiro();
    nivelMestre();
    return 0;
}
