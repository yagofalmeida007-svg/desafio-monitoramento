#include <stdio.h>

int main() {

    float limite;
    float temperatura;
    float soma = 0;
    float maior, menor;
    float media;
    float percentual;

    int quantidade = 0;
    int acimaLimite = 0;
    int consecutivas = 0;

    // Solicita e valida o limite de temperatura
    do {
        printf("Digite o limite de temperatura (-50 a 100): ");
        scanf("%f", &limite);

        if (limite < -50 || limite > 100) {
            printf("Valor invalido! Digite uma temperatura entre -50 e 100.\n");
        }

    } while (limite < -50 || limite > 100);

    printf("\n=== MONITORAMENTO DE TEMPERATURA ===\n");
    printf("Digite temperaturas entre -50 e 100 graus.\n");
    printf("O monitoramento termina apos 3 temperaturas consecutivas acima do limite.\n");
    printf("Digite -999 para encerrar manualmente.\n\n");

    // Primeira leitura
    printf("Digite a temperatura: ");
    scanf("%f", &temperatura);

    while (temperatura != -999) {

        // Validação da temperatura
        if (temperatura < -50 || temperatura > 100) {
            printf("Temperatura invalida! Digite um valor entre -50 e 100.\n");
        }
        else {

            // Atualiza quantidade e soma
            quantidade++;
            soma += temperatura;

            // Define maior e menor na primeira leitura válida
            if (quantidade == 1) {
                maior = temperatura;
                menor = temperatura;
            }
            else {
                if (temperatura > maior) {
                    maior = temperatura;
                }

                if (temperatura < menor) {
                    menor = temperatura;
                }
            }

            // Verifica se a temperatura está acima do limite
            if (temperatura > limite) {
                acimaLimite++;
                consecutivas++;

                printf("Temperatura acima do limite!\n");

                // Verifica se existem 3 temperaturas consecutivas acima
                if (consecutivas == 3) {
                    printf("\nALERTA: 3 temperaturas consecutivas acima do limite!\n");
                    break;
                }
            }
            else {
                // Reinicia o contador quando a temperatura não está acima
                consecutivas = 0;
            }
        }

        printf("\nDigite a temperatura: ");
        scanf("%f", &temperatura);
    }

    // Verifica se houve alguma leitura válida
    if (quantidade > 0) {

        media = soma / quantidade;
        percentual = (acimaLimite * 100.0) / quantidade;

        printf("\n====================================\n");
        printf("       RELATORIO FINAL\n");
        printf("====================================\n");

        printf("Limite definido: %.2f C\n", limite);
        printf("Quantidade de temperaturas: %d\n", quantidade);
        printf("Media: %.2f C\n", media);
        printf("Maior temperatura: %.2f C\n", maior);
        printf("Menor temperatura: %.2f C\n", menor);
        printf("Acima do limite: %d\n", acimaLimite);
        printf("Percentual acima do limite: %.2f%%\n", percentual);

    }
    else {
        printf("\nNenhuma temperatura valida foi registrada.\n");
    }

    return 0;
}