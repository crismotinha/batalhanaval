#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "armas.h"
#include "player.h"
#include "iapc.h"
#include "game.h"

po_t escolher_ponto_pc_esperto(int tab[15][15], po_t possiveis_alvos[], po_t impossiveis[], po_t prioritarios[]) {
    po_t ponto;
    po_t ponto_final;
    int i;


    ponto = buscar_ponto_valido(prioritarios, tab);
    if (ponto.x != -1 && ponto.y != -1) {
        int ponto_impossivel = buscar_no_array(ponto, impossiveis);
            if (ponto_impossivel == -1) {
                printf(" peguei de prioritarios ");
                return ponto;
            }
    }

    ponto = buscar_ponto_valido(possiveis_alvos, tab);
    if (ponto.x != -1 && ponto.y != -1) {
        int ponto_impossivel = buscar_no_array(ponto, impossiveis);
            if (ponto_impossivel == -1) {
                printf(" peguei de possiveis alvos ");
                return ponto;
            }
    }

    /*
    for (i=0; i < 225; i++) {
        ponto.x = prioritarios[i].x;
        ponto.y = prioritarios[i].y;
        if (ponto.x != -1 && ponto.y != -1) {
            if (tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
            ponto_final.x = ponto.x ;
            ponto_final.y = ponto.y;
            int ponto_impossivel = buscar_no_array(ponto_final, impossiveis);
                if (ponto_impossivel == -1) {
                    printf(" peguei de prioritarios ");
                    return ponto_final;
                }
            }
        }
    }

    for (i=0; i < 225; i++) {
        ponto.x = possiveis_alvos[i].x;
        ponto.y = possiveis_alvos[i].y;
        if (ponto.x != -1 && ponto.y != -1) {
            if (tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
            ponto_final.x = ponto.x ;
            ponto_final.y = ponto.y;
            int ponto_impossivel = buscar_no_array(ponto_final, impossiveis);
                if (ponto_impossivel == -1) {
                    printf(" peguei de possiveis alvos ");
                    return ponto_final;
                }
            }
            }
        }
        */
    //se ele não achar nada de bom nos possiveis alvos, ele sorteia random
    ponto.x = rand()%14;
    ponto.y = rand()%14;
    int ponto_impossivel = buscar_no_array(ponto, impossiveis);
    if (ponto_impossivel == -1) {
        if (tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
            ponto_final.x = ponto.x ;
            ponto_final.y = ponto.y ;
            printf(" chutando ");
            return ponto_final;
        }
    }
}

po_t buscar_ponto_valido (po_t array[], int tab[15][15]){
    po_t ponto;
    int i;
    for (i=0; i < 225; i++) {
        if (array[i].x != -1 && array[i].y != -1){
            if (tab[array[i].y][array[i].x] != 2 && tab[array[i].y][array[i].x] != 3){
                ponto.x = array[i].x;
                ponto.y = array[i].y;
                return ponto;
            }
        }
    }
    ponto.x = -1;
    ponto.y = -1;
    return ponto;
}

void limpar_array(po_t array[], int tab[15][15]) {
    int i;
    for (i=0; i < 225; i++) {
        if (tab[array[i].y][array[i].x] == 2 || tab[array[i].y][array[i].x] == 3) {
            array[i].x = -1;
            array[i].y = -1;
            printf("\n excluido array[%d]\n", i);
        }
    }
}
int criar_array(po_t array[]){
    int i;
    for (i=0; i < 225; i++) {
        array[i].x = -1;
        array[i].y = -1;
    }
    return array;
}

void printar_possiveis_alvos(po_t array[]){
    int i;
    for (i=0; i < 225; i++) {
        if (array[i].x != -1 && array[i].y != -1) {
            printf("array[%d]= %c %d\n", i,str_eixo[array[i].y], array[i].x+1);
        }
    }
    printf("\nacabou\n");
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
    printf("No ponto %c%d, adicionei os vizinhos:\n", str_eixo[ponto.y], ponto.x+1);
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
}

void add_no_array(po_t ponto, po_t array[]) {
    if (buscar_no_array(ponto, array) == -1) {
        int indice;
        indice = buscar_espaco_array(array);
        array[indice] = ponto;
    }
}
void excluir_do_array(po_t ponto, po_t array[]) {
    int indice;
    indice = buscar_no_array(ponto, array);
    array[indice].x = -1;
    array[indice].y = -1;
}

po_t tem_vizinhoNSLO(po_t pontoPrincipal, int tab[15][15]){
    int pontoX;
    int pontoY;
    pontoX = pontoPrincipal.x;
    pontoY = pontoPrincipal.y;
    po_t ponto_vizinho;
    if (tab[pontoY-1][pontoX] == 2) { //vizinho ao Norte
        ponto_vizinho.x = pontoX;
        ponto_vizinho.y = pontoY-1;
        return ponto_vizinho;
    }
    if (tab[pontoY+1][pontoX] == 2) { //vizinho ao Sul
        ponto_vizinho.x = pontoX;
        ponto_vizinho.y = pontoY+1;
        return ponto_vizinho;
    }
    if (tab[pontoY][pontoX-1] == 2) { //vizinho ao Leste
        ponto_vizinho.x = pontoX-1;
        ponto_vizinho.y = pontoY;
        return ponto_vizinho;
    }
    if (tab[pontoY][pontoX+1] == 2) { //vizinho ao Oeste
        ponto_vizinho.x = pontoX+1;
        ponto_vizinho.y = pontoY;
        return ponto_vizinho;
    }
    ponto_vizinho.x = -1;
    ponto_vizinho.y = -1;
    return ponto_vizinho;
}

void criar_prioritarios (int tab[15][15], po_t possiveis_alvos[], po_t impossiveis[], po_t prioritarios[]) {
    int i,j;
    po_t ponto_principal;
    po_t ponto_vizinho;
    ponto_vizinho.x = -1;
    ponto_vizinho.y = -1;


    for (i=0; i<15; i++){
        for (j=0; j<15; j++){
            if (tab[j][i] == 2 && ponto_vizinho.x == -1 && ponto_vizinho.y == -1){
                ponto_principal.x = i;
                ponto_principal.y = j;
                ponto_vizinho = tem_vizinhoNSLO(ponto_principal, tab);
            }
        }
    }
    if (ponto_vizinho.x !=1 && ponto_vizinho.y !=-1) {
        int diferenca_x;
        int diferenca_y;
        po_t ponto_add1, ponto_add2, ponto_exc1, ponto_exc2, ponto_exc3, ponto_exc4;
        diferenca_x = ponto_vizinho.x - ponto_principal.x;
        diferenca_y = ponto_vizinho.y - ponto_principal.y;
        printf("ponto principal: %c%d \nponto vizinho: %c%d", str_eixo[ponto_principal.y], ponto_principal.x, str_eixo[ponto_vizinho.y], ponto_vizinho.x );
        printf("\ndiferencax = %d, diferenca y = %d\n", diferenca_x, diferenca_y);
        if (diferenca_x == 0 && diferenca_y == 1) { // ponto 2 está abaixo do ponto 1
            ponto_add1.x = ponto_principal.x;
            ponto_add1.y = ponto_principal.y +2;
            ponto_add2.x = ponto_principal.x;
            ponto_add2.y = ponto_principal.y -1;
            add_no_array(ponto_add1, prioritarios);
            add_no_array(ponto_add2, prioritarios);

            ponto_exc1.x = ponto_principal.x +1;
            ponto_exc1.y = ponto_principal.y;
            ponto_exc2.x = ponto_principal.x -1;
            ponto_exc2.y = ponto_principal.y;
            ponto_exc3.x = ponto_vizinho.x +1;
            ponto_exc3.y = ponto_vizinho.y;
            ponto_exc4.x = ponto_vizinho.x -1;
            ponto_exc4.y = ponto_vizinho.y;
            excluir_do_array(ponto_exc1, possiveis_alvos);
            add_no_array(ponto_exc1, impossiveis);
            excluir_do_array(ponto_exc2, possiveis_alvos);
            add_no_array(ponto_exc2, impossiveis);
            excluir_do_array(ponto_exc3, possiveis_alvos);
            add_no_array(ponto_exc3, impossiveis);
            excluir_do_array(ponto_exc4, possiveis_alvos);
            add_no_array(ponto_exc4, impossiveis);

        }
        else if (diferenca_x == 0 && diferenca_y == -1) { // ponto 2 está acima do ponto 1
            ponto_add1.x = ponto_principal.x;
            ponto_add1.y = ponto_principal.y -2;
            ponto_add2.x = ponto_principal.x;
            ponto_add2.y = ponto_principal.y +1;
            add_no_array(ponto_add1, prioritarios);
            add_no_array(ponto_add2, prioritarios);

            ponto_exc1.x = ponto_principal.x +1;
            ponto_exc1.y = ponto_principal.y;
            ponto_exc2.x = ponto_principal.x -1;
            ponto_exc2.y = ponto_principal.y;
            ponto_exc3.x = ponto_vizinho.x +1;
            ponto_exc3.y = ponto_vizinho.y;
            ponto_exc4.x = ponto_vizinho.x -1;
            ponto_exc4.y = ponto_vizinho.y;
            excluir_do_array(ponto_exc1, possiveis_alvos);
            add_no_array(ponto_exc1, impossiveis);
            excluir_do_array(ponto_exc2, possiveis_alvos);
            add_no_array(ponto_exc2, impossiveis);
            excluir_do_array(ponto_exc3, possiveis_alvos);
            add_no_array(ponto_exc3, impossiveis);
            excluir_do_array(ponto_exc4, possiveis_alvos);
            add_no_array(ponto_exc4, impossiveis);

        }
        else if (diferenca_x == 1 && diferenca_y == 0) { // ponto 2 está a direita do ponto 1
            ponto_add1.x = ponto_principal.x+2;
            ponto_add1.y = ponto_principal.y;
            ponto_add2.x = ponto_principal.x-1;
            ponto_add2.y = ponto_principal.y;
            add_no_array(ponto_add1, prioritarios);
            add_no_array(ponto_add2, prioritarios);

            ponto_exc1.x = ponto_principal.x;
            ponto_exc1.y = ponto_principal.y+1;
            ponto_exc2.x = ponto_principal.x;
            ponto_exc2.y = ponto_principal.y-1;
            ponto_exc3.x = ponto_vizinho.x;
            ponto_exc3.y = ponto_vizinho.y+1;
            ponto_exc4.x = ponto_vizinho.x;
            ponto_exc4.y = ponto_vizinho.y-1;
            excluir_do_array(ponto_exc1, possiveis_alvos);
            add_no_array(ponto_exc1, impossiveis);
            excluir_do_array(ponto_exc2, possiveis_alvos);
            add_no_array(ponto_exc2, impossiveis);
            excluir_do_array(ponto_exc3, possiveis_alvos);
            add_no_array(ponto_exc3, impossiveis);
            excluir_do_array(ponto_exc4, possiveis_alvos);
            add_no_array(ponto_exc4, impossiveis);

        }
        else if (diferenca_x == -1 && diferenca_y == 0) { // ponto 2 está a esquerda do ponto 1
            ponto_add1.x = ponto_principal.x-2;
            ponto_add1.y = ponto_principal.y;
            ponto_add2.x = ponto_principal.x+1;
            ponto_add2.y = ponto_principal.y;
            add_no_array(ponto_add1, prioritarios);
            add_no_array(ponto_add2, prioritarios);

            ponto_exc1.x = ponto_principal.x;
            ponto_exc1.y = ponto_principal.y+1;
            ponto_exc2.x = ponto_principal.x;
            ponto_exc2.y = ponto_principal.y-1;
            ponto_exc3.x = ponto_vizinho.x;
            ponto_exc3.y = ponto_vizinho.y+1;
            ponto_exc4.x = ponto_vizinho.x;
            ponto_exc4.y = ponto_vizinho.y-1;
            excluir_do_array(ponto_exc1, possiveis_alvos);
            add_no_array(ponto_exc1, impossiveis);
            excluir_do_array(ponto_exc2, possiveis_alvos);
            add_no_array(ponto_exc2, impossiveis);
            excluir_do_array(ponto_exc3, possiveis_alvos);
            add_no_array(ponto_exc3, impossiveis);
            excluir_do_array(ponto_exc4, possiveis_alvos);
            add_no_array(ponto_exc4, impossiveis);

        }
    }

}
