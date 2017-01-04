#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "armas.h"
#include "player.h"
#include "iapc.h"

void exibir_tab_bonito(int tab[15][15]){
    int i,j;
    //printf("                     0 1 2 3 4 5\n");
    printf("  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15\n");
    for (i=0; i<15; i++){
        printf("%c ", str_eixo[i]);
        for (j=0; j<15; j++){
            int peca;
            peca = tab[i][j];
            if(peca == 0) {
                printf("-- ");
            }
            else if (peca == 1){
                printf("██ ");
            }
            else if (peca == 2){
                printf(" x ");
            }
        }
        printf("\n");
    }
}
void exibir_tab_bonito_inimigo(int tab[15][15]){
    int i,j;
    printf("\n");
   // printf("                     0 1 2 3 4 5\n");
    printf("  01 02 03 04 05 06 07 08 09 10 11 12 13 14 15\n");
    for (i=0; i<15; i++){
        printf("%c ", str_eixo[i]);
        for (j=0; j<15; j++){
            int peca;
            peca = tab[i][j];
            if(peca == 0 || peca == 1) {
                printf("-- ");
            }
            else if (peca == 3){
                printf("~~ "); //errou
            }
            else if (peca == 2){
                printf(" x "); //acertou
            }
        }
        printf("\n");
    }
}
po_t escolher_ponto_player() {
    po_t ponto;
    char pontoY;
    int pontoX;
    printf("Digite o ponto que você quer atirar:\n");
    scanf("%c%d", &pontoY, &pontoX);
    ponto.x = pontoX - 1;
    ponto.y =  (buscar_ponto(pontoY));
    getchar();
    return ponto;
}

po_t escolher_ponto_pc_burro(int tab[15][15]) {
    po_t ponto;
    while (true) {
        ponto.x = rand()%14;
        ponto.y = rand()%14;
        if (tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
            return ponto;
        }
    }
}


int atirar(int tab[15][15], po_t ponto) {
    int atingido;
    printf("\n -- atirando no ponto %c%d --\n", str_eixo[ponto.y], ponto.x+1);
    atingido = foi_atingido(ponto, tab);
    if (atingido == 1) {
        exibir_tab_bonito_inimigo(tab); //Foi atingido
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

void jogar_com_player(int tab_p1[15][15],int tab_p2[15][15]) {
    int vez_P1;
    int vez_P2;
    int acertou;
    vez_P1 = 0;
    vez_P2 = 0;
    po_t ponto;
    while (tudo_destruido(tab_p2) == 0 && tudo_destruido(tab_p1) == 0) {
        if (vez_P1 == 0 && vez_P2 == 0) { //primeira jogada, começa com P1
            printf("Player 1, é a sua vez de jogar. \n");
            getchar();
            ponto = escolher_ponto_player();
            acertou = atirar(tab_p2, ponto);
            if (acertou == 1) {
                printf("\nVocê acertou e continua jogando!\n");
                vez_P1 = 1;
                vez_P2 = 0;
            }
            if (acertou == 0) {
                printf("\nVocê errou... Passe o controle para o outro jogador!\n");
                vez_P1 = 0;
                vez_P2 = 1;
            }
        }
        if (vez_P1 == 1) {
            printf("Player 1, é a sua vez de jogar. \n");
            getchar();
            ponto = escolher_ponto_player();
            acertou = atirar(tab_p2, ponto);
            if (acertou == 1) {
                printf("\nVocê acertou e continua jogando!\n");
                vez_P1 = 1;
                vez_P2 = 0;
            }
            if (acertou == 0) {
                printf("\nVocê errou... Passe o controle para o outro jogador!\n");
                vez_P1 = 0;
                vez_P2 = 1;
            }

        }
        if (vez_P2 == 1) {
            printf("Player 2, é a sua vez de jogar. \n");
            ponto = escolher_ponto_player();
            acertou = atirar(tab_p1, ponto);
            if (acertou == 1) {
                printf("\nVocê acertou e continua jogando!\n");
                vez_P1 = 0;
                vez_P2 = 1;
            }
            if (acertou == 0) {
                printf("\nVocê errou... Passe o controle para o outro jogador!\n");
                vez_P1 = 1;
                vez_P2 = 0;
            }

        }
    }
}

void jogar_com_pc(int tab_p1[15][15],int tab_p2[15][15], po_t possiveis_alvos[225]) {
    int vez_P1;
    int vez_P2;
    int acertou;
    vez_P1 = 0;
    vez_P2 = 0;
    po_t ponto;
    criar_array_possiveis_alvos(possiveis_alvos);
    while (tudo_destruido(tab_p2) == 0 && tudo_destruido(tab_p1) == 0) {
        if (vez_P1 == 0 && vez_P2 == 0) { //primeira jogada, começa com P1
            printf("Player 1, é a sua vez de jogar. \n");
            getchar();
            ponto = escolher_ponto_player();
            acertou = atirar(tab_p2, ponto);
            if (acertou == 1) {
                printf("\nVocê acertou e continua jogando!\n");
                vez_P1 = 1;
                vez_P2 = 0;
            }
            if (acertou == 0) {
                printf("\nVocê errou... Passe o controle para o outro jogador!\n");
                vez_P1 = 0;
                vez_P2 = 1;
            }
        }
        if (vez_P1 == 1) {
            printf("Player 1, é a sua vez de jogar. \n");
            getchar();
            ponto = escolher_ponto_player();
            acertou = atirar(tab_p2, ponto);
            if (acertou == 1) {
                printf("\nVocê acertou e continua jogando!\n");
                vez_P1 = 1;
                vez_P2 = 0;
            }
            if (acertou == 0) {
                printf("\nVocê errou... Passe o controle para o outro jogador!\n");
                vez_P1 = 0;
                vez_P2 = 1;
            }

        }
        if (vez_P2 == 1) {
            printf("Player 2, é a sua vez de jogar. \n");
            ponto = escolher_ponto_pc_esperto(tab_p1, possiveis_alvos);
            acertou = atirar(tab_p1, ponto);
            if (acertou == 1) {
                printf("\nVocê acertou e continua jogando!\n");
                vez_P1 = 0;
                vez_P2 = 1;
                adicionar_possiveis_alvos(ponto, possiveis_alvos, tab_p1);
            }
            if (acertou == 0) {
                printf("\nVocê errou... Passe o controle para o outro jogador!\n");
                vez_P1 = 1;
                vez_P2 = 0;
            }

        }
    }
}

