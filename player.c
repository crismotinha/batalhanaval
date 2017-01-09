#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "armas.h"
#include "player.h"

player_t criar_armas_player(player_t player){
    int i;
    for (i=0; i<4; i++){
        player.armas[i] = criar_arma(1); //submarinos
    }
    for (i=4; i<7; i++){
        player.armas[i] = criar_arma(2); //cruzador
    }
    for (i=7; i<10; i++){
        player.armas[i] = criar_arma(3); //hidroaviao
    }
    player.armas[10] = criar_arma(4);
    player.armas[11] = criar_arma(4);
    player.armas[12] = criar_arma(5);

    return player;
}

void printar_armas_disponiveis_player(arma_t armas[13]) {
    int num_submarino = 0;
    int num_cruzador = 0;
    int num_hidroaviao = 0;
    int num_encouracado = 0;
    int num_portaavioes = 0;
    int i;
    for (i=0; i<13; i++) {
        if (armas[i].usada == false) {
            if (armas[i].tipo_arma == 1) {
            num_submarino += 1;
            }
            else if (armas[i].tipo_arma == 2){
            num_cruzador += 1;
            }
            else if (armas[i].tipo_arma == 3){
            num_hidroaviao += 1;
            }
            else if (armas[i].tipo_arma == 4){
            num_encouracado += 1;
            }
            else if (armas[i].tipo_arma == 5){
            num_portaavioes += 1;
            }
        }
     }
     if (num_submarino + num_cruzador + num_hidroaviao + num_encouracado + num_portaavioes == 0) {
        printf("\nVocê nao possui mais armas\n");
     }
     else {
        printf("\nVoce tem:\n %d Submarinos\n %d Cruzadores\n %d Hidro-avioes\n %d Encouracados\n %d Porta-avioes",
     num_submarino, num_cruzador, num_hidroaviao, num_encouracado, num_portaavioes);
     }
}

void criar_tab_player(int tab[15][15], arma_t armas[13]){
    criar_tabuleiro(tab);
    int i;
    while(armas_usadas(armas) != 13){
        printf("\nEscolha uma peça para colocar no tabuleiro (submarino = 1, cruzador = 2, hidroaviao = 3, encouracado = 4, portaavioes = 5):\n");
        int peca_esc;
        scanf("%d", &peca_esc);
        int indice_arma;
        indice_arma = buscar_por_tipo(armas, peca_esc);
        if (indice_arma == -1) {
            printf("\nVoce nao possui mais armas desse tipo! Escolha outro tipo :) \n");
        }
        else {
        arma_t arma_buscada = armas[indice_arma];
        printf("Escolha a orientacao da arma (norte = 1, leste = 2, sul = 3, oeste = 4):\n");
        int orientacao;
        scanf("%d", &orientacao);
        arma_buscada = girar_arma(arma_buscada, orientacao);
        printf("Escolha a posicao no tabuleiro (digite 'xy', sendo x: A-O e y: 1-15):\n");
        char posicao_x; //"x" (o lance da matriz invertida etc)
        int posicao_y;
        scanf(" %[A-O, a-o] %d", &posicao_x, &posicao_y);
        po_t po_escolhido;
        po_escolhido.y = (buscar_ponto(posicao_x));
        po_escolhido.x = posicao_y-1; //contar de 0-14 pq o indice da matriz comeca com 0
        int colocar;
        colocar = colocar_peca(tab, arma_buscada, po_escolhido);
            if (colocar == 1) {
                armas[indice_arma].usada = true;
                exibir_tab_bonito(tab);
                printar_armas_disponiveis_player(armas);
            }
        }
    }
    exibir_tab_bonito(tab);
    printf("\n\n ==Todas as armas foram colocadas!==\n\n");
}

void criar_tab_pc(int tab[15][15], arma_t armas[13]) {
    criar_tabuleiro(tab);
    while(armas_usadas(armas) != 13){
        //escolhe peca:
        int peca_esc;
        peca_esc = (rand()%5) +1;
        //printf("esco: %d", peca_esc);
        int indice_arma;
        indice_arma = buscar_por_tipo(armas, peca_esc);
        //printf("indice: %d", indice_arma);
        if (indice_arma == -1) {
           // printf("\nVoce nao possui mais armas desse tipo! Escolha outro tipo :) \n");
        }
        else {
            arma_t arma_buscada = armas[indice_arma];
            //escolhe orientacao
            int orientacao;
            orientacao = (rand()%3) +1;
            arma_buscada = girar_arma(arma_buscada, orientacao);
            //escolhe posicao
            po_t po_escolhido;
            po_escolhido.y = (rand()%14);
            po_escolhido.x = (rand()%14); //contar de 0-14 pq o indice da matriz comeca com 0
            int colocar;
            colocar = colocar_peca(tab, arma_buscada, po_escolhido);
            if (colocar == 1) {
                armas[indice_arma].usada = true;
                //printf("\n coloquei o tipo %d, na direcao %d, na posicao %d %d\n", peca_esc, orientacao, po_escolhido.y, po_escolhido.x);


                //printar_armas_disponiveis_player(armas);

            }
        }
    }
    //exibir_tab_bonito(tab);
    //printf("\n\n ==Todas as armas do PC foram colocadas!==\n\n");
}


