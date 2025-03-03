#include <stdio.h>
#include <string.h>

//Declarando variáveis
typedef struct {
    char estado, codigo[32], cidade[100];
    int num_poi;
    float area, pib, dens_pop, pib_capita, super_poder;
    unsigned long int populacao;
} Carta;

//Entrada de dados
void cadastroCarta(Carta *carta){
    printf("Digite a letra representante do estado (entre A a H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta (letra do estado mais um número de 01 a 04): ");
    scanf("%s", &carta->codigo);
    //Para remover o caractere de quebra de linha antes da chamada da função fgets e
    //evitar que seja incluído na próxima entrada de dados
    getchar();

    printf("Digite o nome da cidade: ");
    //Utilizando a função fgets para permitir a entrada de dados de textos com espaços
    //e strcspn para remover o caractere de quebra de linha que fgets pode incluir
    fgets(carta->cidade, 100, stdin);
    carta->cidade[strcspn(carta->cidade, "\n")] = 0;
    
    printf("Digite o número de habitantes: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o Produto Interno Bruto: ");
    scanf("%f", &carta->pib);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%i", &carta->num_poi);

    carta->dens_pop = (float) carta->populacao / carta->area;
    carta->pib_capita = carta->pib / (float) carta->populacao;

    carta->dens_pop = 1/carta->dens_pop;
    carta->super_poder = (float) carta->populacao + carta->area + carta->pib + (float) carta->num_poi + carta->pib_capita + carta->dens_pop;
}

//Apresentando os dados inseridos
void printCarta(const Carta *carta){
    printf("\nEstado: %c\nCódigo: %s\n", carta->estado, carta->codigo);
    printf("Nome da cidade: %s\nPopulação: %lu\nÁrea: %.2f km²\n", carta->cidade, carta->populacao, carta->area);
    printf("PIB: R$ %.2f\nNúmero de pontos turísticos: %i\n", carta->pib, carta->num_poi);
    printf("Densidade populacional: %.2f hab/km²\nPIB per Capita: R$ %.2f\n", carta->dens_pop, carta->pib_capita);
}

//Comparação para decidir qual carta é a mais forte
void compararCartas(const Carta *carta1, const Carta *carta2){
    printf("\nComparação de Cartas:\n");
    printf("Onde 1 corresponde à vitória da Carta 1 e 0 à vitória da Carta 2.\n");

    printf("\nPopulação: %d\n", carta1->populacao > carta2->populacao);
    printf("Área: %d\n", carta1->area > carta2->area);
    printf("PIB: %d\n", carta1->pib > carta2->pib);
    printf("Número de pontos turísticos: %d\n", carta1->num_poi > carta2->num_poi);
    printf("Densidade Populacional: %d\n", carta1->dens_pop < carta2->dens_pop);
    printf("PIB per Capita: %d\n", carta1->pib_capita > carta2->pib_capita);
    printf("Super Poder: %d\n", carta1->super_poder > carta2->super_poder);
}

//Função principal
int main(){
    printf("Bem-vindo ao Super Trunfo! Um jogo de cartas com o objetivo de determinar qual a mais forte entre os jogadores.\n");
    printf("Neste jogo, o tema é países, onde cada carta representa uma cidade de um estado.\n");
    printf("Cadastre duas cartas a seguir e receba o resultado da comparação entre elas.\n");

    Carta carta1, carta2;

    printf("\nCarta 1: \n");
    cadastroCarta(&carta1);

    printf("\nCarta 2: \n");
    cadastroCarta(&carta2);

    compararCartas(&carta1, &carta2);

    /*printCarta(&carta1);
    printCarta(&carta2);*/
}