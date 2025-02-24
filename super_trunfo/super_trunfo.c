//Desafio Nível Novato - Jennifer Lima

//Inclusão de bibliotecas
#include <stdio.h>
#include <string.h>

int main(){
    //Declarando variáveis
    char estado, codigo[32], cidade[100];
    int populacao, num_poi;
    float area, pib;

    //Entrada de dados
    printf("Digite a letra representante do estado (entre A a H): ");
    scanf("%c", &estado);

    printf("Digite o código da carta (letra mais um número de 01 a 04): ");
    scanf("%s", codigo);
    //Para remover o caractere de quebra de linha antes da chamada da função fgets e
    //evitar que seja incluído na entrada de dados
    getchar();

    printf("Digite o nome da cidade: ");
    //Utilizando a função fgets para permitir a entrada de dados de textos com espaços
    //e strcspn para remover o caractere de quebra de linha que fgets pode incluir
    fgets(cidade, 100, stdin);
    cidade[strcspn(cidade, "\n")] = 0;
    
    printf("Digite o número de habitantes: ");
    scanf("%d", &populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &area);

    printf("Digite o Produto Interno Bruto: ");
    scanf("%f", &pib);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%i", &num_poi);

    //Apresentando os dados inseridos
    printf("\nCarta: \nEstado: %c\nCódigo: %s\n", estado, codigo);
    printf("Nome da cidade: %s\nPopulação: %d\nÁrea: %.2f km²\n", cidade, populacao, area);
    printf("PIB: R$ %.2f\nNúmero de pontos turísticos: %i", pib, num_poi);
}