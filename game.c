#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "armas.h"
#include "player.h"

void exibir_tab_bonito(int tab[15][15]){
    int i,j;
    printf("                     0 1 2 3 4 5\n");
    printf("  1 2 3 4 5 6 7 8 9 1 1 1 1 1 1 \n");
    for (i=0; i<15; i++){
        printf("%c ", str_eixo[i]);
        for (j=0; j<15; j++){
            int peca;
            peca = tab[i][j];
            if(peca == 0) {
                printf("- ");
            }
            else if (peca == 1){
                printf("█ ");
            }
            else if (peca == 2){
                printf("x ");
            }
        }
        printf("\n");
    }
}
void exibir_tab_bonito_inimigo(int tab[15][15]){
    int i,j;
    printf("\n");
    printf("                     0 1 2 3 4 5\n");
    printf("  1 2 3 4 5 6 7 8 9 1 1 1 1 1 1 \n");
    for (i=0; i<15; i++){
        printf("%c ", str_eixo[i]);
        for (j=0; j<15; j++){
            int peca;
            peca = tab[i][j];
            if(peca == 0 || peca == 1) {
                printf("- ");
            }
            else if (peca == 3){
                printf("~ ");
            }
            else if (peca == 2){
                printf("x ");
            }
        }
        printf("\n");
    }
}


int atirar(int tab[15][15]) {
    po_t ponto;
    char pontoY;
    printf("Digite o ponto que você quer atirar:\n");
    scanf("%c %d", &pontoY, &ponto.x);
    ponto.x = (ponto.x -1);
    ponto.y =  (buscar_ponto(pontoY));
    int atingido;
    atingido = foi_atingido(ponto, tab);
    if (atingido == 1) {
        exibir_tab_bonito_inimigo(tab);
        return 1;
    }
    else {
        exibir_tab_bonito_inimigo(tab);
        return 0;
    }
}

int tudo_destruido(int tab[15][15]){
    int i,j;
    for (i=0; i<15; i++){
        for (j=0; j<15; j++){
            if (tab[i][j] == 1){
                return 0; //ainda tenho alguma arma
            }
        }
    }
    return 1; //nao tem mais arma inteira
}
