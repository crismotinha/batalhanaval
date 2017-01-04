#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "armas.h"
#include "player.h"
#include "game.h"

po_t escolher_ponto_pc_esperto(int tab[15][15], po_t possiveis_alvos[]) {
    po_t ponto;
    po_t ponto_final; //ajuste de 0-14 para 1-15
    int i;
    for (i=0; i < 225; i++) {
        ponto.x = possiveis_alvos[i].x;
        ponto.y = possiveis_alvos[i].y;
        printf("teste ponto indice %d: %c%d", i, str_eixo[ponto.y+1],(ponto.x + 1));
        if (ponto.x != -1 && ponto.y != -1) {
            if (tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
            ponto_final.x = ponto.x ;
            ponto_final.y = ponto.y;
            return ponto_final;
            }
        }
    }
    //se ele não achar nada de bom nos possiveis alvos, ele sorteia random
    ponto.x = rand()%14;
    ponto.y = rand()%14;
    if (tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
        ponto_final.x = ponto.x ;
        ponto_final.y = ponto.y ;
        return ponto_final;
    }

}

int criar_array_possiveis_alvos(po_t array[225]){
    int i;
    for (i=0; i < 225; i++) {
        array[i].x = -1;
        array[i].y = -1;
    }
    return array;
}

void printar_possiveis_alvos(po_t array[225]){
    int i;
    for (i=0; i < 225; i++) {
        if (array[i].x != -1 && array[i].y != -1) {
            printf("array[%d].x = %d \narray[%d].y = %d\n", i, array[i].x, i, array[i].y);
        }
    }
    printf("acabou");
}

int buscar_espaco_array(po_t array[]){
    int i;
    i = 0;
    while (true){
        if (array[i].x == -1 && array[i].y == -1){
            return i;
        }
        i++;
    }
}

int buscar_no_array(po_t ponto, po_t array[]){
    int i;
    for (i=0; i < 225; i++) {
        if (array[i].x == ponto.x && array[i].y == ponto.y){
            return i;
        }
    }
    return -1;
}


void adicionar_possiveis_alvos(po_t ponto, po_t possiveis_alvos[], int tab[15][15]){
    int indice;
    indice = buscar_espaco_array(possiveis_alvos);
    po_t pontoN; //acima
    po_t pontoS; //abaixo
    po_t pontoL; //a direita
    po_t pontoO; //a esquerda
    pontoN.x = ponto.x;
    pontoN.y = ponto.y - 1;
    pontoS.x = ponto.x;
    pontoS.y = ponto.y + 1;
    pontoL.x = ponto.x + 1;
    pontoL.y = ponto.y;
    pontoO.x = ponto.x - 1;
    pontoO.y = ponto.y;
    printf("No ponto %c%d, adicionei os vizinhos:\n", str_eixo[ponto.y+1], ponto.x);
    if (tab[pontoN.y][pontoN.x] != 2 && tab[pontoN.y][pontoN.x] != 3) {
        if (buscar_no_array(pontoN, possiveis_alvos)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoN;
        }
    }
    if (tab[pontoS.y][pontoS.x] != 2 && tab[pontoS.y][pontoS.x] != 3) {
        if (buscar_no_array(pontoS, possiveis_alvos)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoS;
        }
    }
    if (tab[pontoL.y][pontoL.x] != 2 && tab[pontoL.y][pontoL.x] != 3) {
        if (buscar_no_array(pontoL, possiveis_alvos)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoL;
        }
    }
    if (tab[pontoO.y][pontoO.x] != 2 && tab[pontoO.y][pontoO.x] != 3) {
        if (buscar_no_array(pontoO, possiveis_alvos)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoO;
        }
    }
    printar_possiveis_alvos(possiveis_alvos);
}
