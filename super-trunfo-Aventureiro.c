#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char estado[30];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular os atributos derivados de uma carta
void calcularAtributos(Carta *c) {
    if (c->area != 0) {
        c->densidade_populacional = c->populacao / c->area;
    } else {
        c->densidade_populacional = 0;
    }
    if (c->populacao != 0) {
        c->pib_per_capita = c->pib / c->populacao;
    } else {
        c->pib_per_capita = 0; 
    }
}

// Função para ler os dados da carta
void lerCarta(Carta *c) {
    printf("Digite o estado: ");
    fgets(c->estado, sizeof(c->estado), stdin);
    c->estado[strcspn(c->estado, "\n")] = 0;
    
    printf("Digite o código da carta: ");
    fgets(c->codigo, sizeof(c->codigo), stdin);
    c->codigo[strcspn(c->codigo, "\n")] = 0;
    
    printf("Digite o nome da cidade: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    c->nome[strcspn(c->nome, "\n")] = 0;
    
    printf("Digite a população: ");
    scanf("%d", &c->populacao);
    
    printf("Digite a área em km²: ");
    scanf("%f", &c->area);
    
    printf("Digite o PIB em bilhões de reais: ");
    scanf("%f", &c->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);
    
    getchar(); // Limpa o buffer de entrada
    calcularAtributos(c);
}

// Função para comparar duas cartas com base em um atributo escolhido
void compararCartas(Carta c1, Carta c2, int opcao) {
    float valor1, valor2;
    int menorVence = 0; // Indica se o menor valor vence
    char atributo[30];
    
    switch (opcao) {
        case 1:
            strcpy(atributo, "População");
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            break;
        case 2:
            strcpy(atributo, "Área");
            valor1 = c1.area;
            valor2 = c2.area;
            break;
        case 3:
            strcpy(atributo, "PIB");
            valor1 = c1.pib;
            valor2 = c2.pib;
            break;
        case 4:
            strcpy(atributo, "Densidade Populacional");
            valor1 = c1.densidade_populacional;
            valor2 = c2.densidade_populacional;
            menorVence = 1;
            break;
        case 5:
            strcpy(atributo, "PIB per Capita");
            valor1 = c1.pib_per_capita;
            valor2 = c2.pib_per_capita;
            break;
        case 6:
            strcpy(atributo, "Pontos Turísticos");
            valor1 = c1.pontos_turisticos;
            valor2 = c2.pontos_turisticos;
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }
    
    printf("\nComparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.nome, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nome, c2.estado, valor2);
    
    if ((valor1 > valor2 && !menorVence) || (valor1 < valor2 && menorVence)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else if ((valor2 > valor1 && !menorVence) || (valor2 < valor1 && menorVence)) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    int continuar;
    do {
        Carta carta1, carta2;
        int opcao;
        
        printf("Cadastro da primeira carta:\n");
        lerCarta(&carta1);
        
        printf("\nCadastro da segunda carta:\n");
        lerCarta(&carta2);
        
        printf("\nEscolha o atributo para comparação:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Densidade Populacional\n");
        printf("5 - PIB per Capita\n");
        printf("6 - Pontos Turísticos\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        compararCartas(carta1, carta2, opcao);
        
        printf("\nDeseja jogar novamente? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
        getchar(); // Limpa buffer
    } while (continuar == 1);
    
    return 0;
}
