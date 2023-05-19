#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int contar_diamantes(char* sequence) {
    int tamanho = strlen(sequence);
    int total_diamantes = 0;
    int pilha = 0;

    for (int i = 0; i < tamanho; i++) {
        if (sequence[i] == '<') {
            pilha++;
        } else if (sequence[i] == '>' && pilha > 0) {
            pilha--;
            total_diamantes++;
        }
    }
    return total_diamantes;
}

int main() {
    int tamanho=100;
    int teste = 0;
    int j = 0;

    printf("Digite a quantidade de testes: \n");
    scanf("%d", &teste);

    char * sequence = (char *) malloc((tamanho + 1)* sizeof(char));

    srand(time(NULL));

do
{
    if (teste == 0){
        printf("Digite um valor maior que 0!\n\n");
        return main();
        }
    else{
        for (int i = 0; i < tamanho; i++) {
            int indice = rand() % 3; 

            if (indice == 0) {
                sequence[i] = '<';
            } else if (indice == 1) {
                sequence[i] = '>';
            } else {
                sequence[i] = '.';
            }
        }
        j++;    
        int total_diamantes = contar_diamantes(sequence);
        printf("Teste %d:Numero de diamantes: %d\n", j, total_diamantes);  
    }
} while (j < teste);

    free(sequence);
    return 0;
}   
