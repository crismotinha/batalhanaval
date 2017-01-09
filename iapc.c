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
    if (ponto.x != -1 && ponto.y != -1 && tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
        int ponto_impossivel = buscar_no_array(ponto, impossiveis, 225);
            if (ponto_impossivel == -1) {
                //printf(" peguei de prioritarios ");
                return ponto;
            }
    }

    ponto = buscar_ponto_valido(possiveis_alvos, tab);
    if (ponto.x != -1 && ponto.y != -1 && tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
        int ponto_impossivel = buscar_no_array(ponto, impossiveis, 225);
            if (ponto_impossivel == -1) {
               // printf(" peguei de possiveis alvos ");
                return ponto;
            }
    }

    //se ele não achar nada de bom nos possiveis alvos, ele sorteia random
    while(true){
        ponto.x = rand()%15;
        ponto.y = rand()%15;
        int ponto_impossivel = buscar_no_array(ponto, impossiveis, 225);
        if (ponto_impossivel == -1) {
            if (tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
                ponto_final.x = ponto.x ;
                ponto_final.y = ponto.y ;
               // printf(" chutando ");
                return ponto_final;
            }
        }
    }
}

po_t buscar_ponto_valido (po_t array[], int tab[15][15]){
    po_t ponto;
    int i;
    for (i=0; i < 225; i++) {
        if (array[i].x != -1 && array[i].y != -1){
            if (tab[array[i].y][array[i].x] != 2 && tab[array[i].y][array[i].x] != 3 &&
            tab[array[i].y][array[i].x] >=0 && tab[array[i].y][array[i].x] >=0 &&
            tab[array[i].y][array[i].x] <=14 && tab[array[i].y][array[i].x] <=14
            ){
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
            //printf("\n excluido array[%d]\n", i);
        }
    }
}
int criar_array(po_t array[], int tamanho){
    int i;
    for (i=0; i < tamanho; i++) {
        array[i].x = -1;
        array[i].y = -1;
    }
    return array;
}

void printar_possiveis_alvos(po_t array[], int tamanho){
    int i;
    for (i=0; i < tamanho; i++) {
        if (array[i].x != -1 && array[i].y != -1) {
           // printf("array[%d]= %c %d\n", i,str_eixo[array[i].y], array[i].x+1);
        }
    }
  //  printf("\nacabou\n");
}

int buscar_espaco_array(po_t array[]){
    int i,j;
    i = 0;
    j = 0;
    int sobrando;
    sobrando = 0;
    while (j<225){
        if (array[j].x != -1 && array[j].y != -1){
            sobrando+=1;
        }
        j++;
    }
    //printf("\nsobrando %d espaços\n", 225-sobrando);
    while (true){
        if (array[i].x == -1 && array[i].y == -1){
            return i;
        }
        i++;
    }
}

int buscar_no_array(po_t ponto, po_t array[], int tamanho){
    int i;
    for (i=0; i < tamanho; i++) {
        if (array[i].x == ponto.x && array[i].y == ponto.y){
            return i;
        }
    }
    return -1;
}

void adicionar_possiveis_alvos_oito (po_t ponto, po_t possiveis_alvos[], int tab[15][15]){
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
    po_t pontoNL; //nordeste
    po_t pontoNO; //noroeste
    po_t pontoSL; //sudeste
    po_t pontoSO; //sudoeste

    pontoNL.x = ponto.x+1;
    pontoNL.y = ponto.y - 1;
    pontoNO.x = ponto.x-1;
    pontoNO.y = ponto.y - 1;
    pontoSL.x = ponto.x + 1;
    pontoSL.y = ponto.y+1;
    pontoSO.x = ponto.x - 1;
    pontoSO.y = ponto.y+1;
    //printf("No ponto %c%d, adicionei os vizinhos:\n", str_eixo[ponto.y], ponto.x+1);
    if (tab[pontoN.y][pontoN.x] != 2 && tab[pontoN.y][pontoN.x] != 3 &&
            (pontoN.y <=14 ||pontoN.y >= 0) && (pontoN.x <=14 ||pontoN.x >= 0)) {
        if (buscar_no_array(pontoN, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoN;
        }
    }
    if (tab[pontoS.y][pontoS.x] != 2 && tab[pontoS.y][pontoS.x] != 3 &&
            (pontoS.y <=14 ||pontoS.y >= 0) && (pontoS.x <=14 ||pontoS.x >= 0)) {
        if (buscar_no_array(pontoS, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoS;
        }
    }
    if (tab[pontoL.y][pontoL.x] != 2 && tab[pontoL.y][pontoL.x] != 3 &&
            (pontoL.y <=14 ||pontoL.y >= 0) && (pontoL.x <=14 ||pontoL.x >= 0)) {
        if (buscar_no_array(pontoL, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoL;
        }
    }
    if (tab[pontoO.y][pontoO.x] != 2 && tab[pontoO.y][pontoO.x] != 3 &&
            (pontoO.y <=14 ||pontoO.y >= 0) && (pontoO.x <=14 ||pontoO.x >= 0)) {
        if (buscar_no_array(pontoO, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoO;
        }
    }
    //--x--
    if (tab[pontoNL.y][pontoNL.x] != 2 && tab[pontoNL.y][pontoNL.x] != 3 &&
            (pontoNL.y <=14 ||pontoNL.y >= 0) && (pontoNL.x <=14 ||pontoNL.x >= 0)) {
        if (buscar_no_array(pontoNL, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoNL;
        }
    }
    if (tab[pontoNO.y][pontoNO.x] != 2 && tab[pontoNO.y][pontoNO.x] != 3 &&
            (pontoNO.y <=14 ||pontoNO.y >= 0) && (pontoNO.x <=14 ||pontoNO.x >= 0)) {
        if (buscar_no_array(pontoNO, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoNO;
        }
    }
    if (tab[pontoSL.y][pontoSL.x] != 2 && tab[pontoSL.y][pontoSL.x] != 3 &&
            (pontoSL.y <=14 ||pontoSL.y >= 0) && (pontoSL.x <=14 ||pontoSL.x >= 0)) {
        if (buscar_no_array(pontoSL, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoSL;
        }
    }
    if (tab[pontoSO.y][pontoSO.x] != 2 && tab[pontoSO.y][pontoSO.x] != 3 &&
            (pontoSO.y <=14 ||pontoSO.y >= 0) && (pontoSO.x <=14 ||pontoSO.x >= 0)) {
        if (buscar_no_array(pontoSO, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoSO;
        }
    }
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
    //printf("No ponto %c%d, adicionei os vizinhos:\n", str_eixo[ponto.y], ponto.x+1);
    if (tab[pontoN.y][pontoN.x] != 2 && tab[pontoN.y][pontoN.x] != 3 &&
            (pontoN.y <=14 ||pontoN.y >= 0) && (pontoN.x <=14 ||pontoN.x >= 0)) {
        if (buscar_no_array(pontoN, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoN;
        }
    }
    if (tab[pontoS.y][pontoS.x] != 2 && tab[pontoS.y][pontoS.x] != 3 &&
            (pontoS.y <=14 ||pontoS.y >= 0) && (pontoS.x <=14 ||pontoS.x >= 0)) {
        if (buscar_no_array(pontoS, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoS;
        }
    }
    if (tab[pontoL.y][pontoL.x] != 2 && tab[pontoL.y][pontoL.x] != 3 &&
            (pontoL.y <=14 ||pontoL.y >= 0) && (pontoL.x <=14 ||pontoL.x >= 0)) {
        if (buscar_no_array(pontoL, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoL;
        }
    }
    if (tab[pontoO.y][pontoO.x] != 2 && tab[pontoO.y][pontoO.x] != 3 &&
            (pontoO.y <=14 ||pontoO.y >= 0) && (pontoO.x <=14 ||pontoO.x >= 0)) {
        if (buscar_no_array(pontoO, possiveis_alvos, 225)== -1){
            indice = buscar_espaco_array(possiveis_alvos);
            possiveis_alvos[indice] = pontoO;
        }
    }
}

void add_no_array(po_t ponto, po_t array[], int tamanho) {
    if (buscar_no_array(ponto, array, tamanho) == -1) {
        int indice;
        indice = buscar_espaco_array(array);
        array[indice] = ponto;
        //printf("\nadicionei!\n");
    }
}
void excluir_do_array(po_t ponto, po_t array[], int tamanho) {
    int indice;
    indice = buscar_no_array(ponto, array, tamanho);
    if (indice != -1) {
        array[indice].x = -1;
        array[indice].y = -1;
    }
}

po_t menor_do_array(po_t array[], int tab[15][15],po_t ex_prioritarios[]){
    int i;
    po_t menor;
    menor.x = -1;
    menor.y = -1;
    for (i=0;i<32;i++){
        if (menor.x == -1 && menor.y == -1){
            if(array[i].x == array[i+1].x) {
                menor.x = array[i].x;
                menor.y = array[i].y;
            }
            if(array[i].y == array[i+1].y) {
                menor.x = array[i].x;
                menor.y = array[i].y;
            }
        }
    }
    for (i=0;i<32;i++){

            if(array[i].x == menor.x) {
            int proximo;
            proximo = array[i].y;
            if (array[i].y < menor.y && array[i].y != -1){
                    menor.x = array[i].x;
                    menor.y = array[i].y;
            }

            }
            if(array[i].y == menor.y) {
                if (array[i].x < menor.x && array[i].x != -1) {
                    menor.x = array[i].x;
                    menor.y = array[i].y;
                }

            }

    }
    return menor;
}
po_t maior_do_array(po_t array[], int tab[15][15],po_t ex_prioritarios[], po_t menor){
    int i;
    po_t maior;
    maior.x = menor.x;
    maior.y = menor.y;

    for (i=0;i<32;i++){
//            printf("\n array[%d] = %c%d", i, str_eixo[array[i].y], array[i].x +1);
            if(array[i].x == maior.x) {
                if (array[i].y == maior.y+1 && maior.y+1 <15){
                    maior.x = array[i].x;
                    maior.y = array[i].y;
                }
            }
    }
    if (maior.y != menor.y){
        return maior;
    }
    for (i=0;i<32;i++){
            if(array[i].y == maior.y) {
                if (array[i].x == maior.x+1 && maior.x+1 <15){
                    maior.x = array[i].x;
                    maior.y = array[i].y;
                }
            }
        }
    return maior;
}

void limpar_vizinhos(int tab[15][15], po_t vizinhos[],po_t ex_prioritarios[]){
   // printf("\n Entrei em limpar \n");
    po_t maior;
    po_t menor;
    po_t ponto_exc1,ponto_exc2, ponto_1, ponto_2;
    int diferenca_x, diferenca_y, i;
    menor = menor_do_array(vizinhos, tab, ex_prioritarios);
    maior = maior_do_array(vizinhos, tab, ex_prioritarios, menor);
    diferenca_x = maior.x - menor.x;
    diferenca_y = maior.y - menor.y;
    //printf("o maior ponto foi: %c%d e o menor foi: %c%d. A diferenca do x foi %d e a do y foi %d",
//    str_eixo[maior.y], maior.x+1,str_eixo[menor.y], menor.x+1, diferenca_x, diferenca_y );
    if (diferenca_x == 0 && (diferenca_y == 1 || diferenca_y == 2 || diferenca_y == 3 || diferenca_y == 4)){
            ponto_1.x = maior.x;
            ponto_1.y = maior.y +1;
            ponto_2.x = menor.x;
            ponto_2.y = menor.y -1;
            if (tab[ponto_1.y][ponto_1.x] == 3 && tab[ponto_2.y][ponto_2.x] == 3 &&
            tab[ponto_1.y][ponto_1.x] >=0 && tab[ponto_2.y][ponto_2.x] >=0 &&
            tab[ponto_1.y][ponto_1.x] <=14 && tab[ponto_2.y][ponto_2.x] <=14){
                add_no_array(maior, ex_prioritarios,225);
                add_no_array(menor, ex_prioritarios,225);
                excluir_do_array(maior, vizinhos,32);
                excluir_do_array(menor, vizinhos,32);
                for (i=0; i<=diferenca_y; i++){
                    ponto_exc1.x = menor.x;
                    ponto_exc1.y = menor.y+i;

                    add_no_array(ponto_exc1, ex_prioritarios,225);
                    excluir_do_array(ponto_exc1, vizinhos,32);
                }
            }
        }
    else if ((diferenca_x == 1 || diferenca_x == 2 || diferenca_x == 3 || diferenca_x == 4) && diferenca_y == 0){
            ponto_1.x = maior.x+1;
            ponto_1.y = maior.y;
            ponto_2.x = menor.x-1;
            ponto_2.y = menor.y;
            if (tab[ponto_1.y][ponto_1.x] == 3 && tab[ponto_2.y][ponto_2.x] == 3 &&
            tab[ponto_1.y][ponto_1.x] >=0 && tab[ponto_2.y][ponto_2.x] >=0 &&
            tab[ponto_1.y][ponto_1.x] <=14 && tab[ponto_2.y][ponto_2.x] <=14){
                add_no_array(maior, ex_prioritarios,225);
                add_no_array(menor, ex_prioritarios,225);
                excluir_do_array(maior, vizinhos,32);
                excluir_do_array(menor, vizinhos,32);
                for (i=0; i<=diferenca_x; i++){
                    ponto_exc1.x = menor.x+i;
                    ponto_exc1.y = menor.y;

                    add_no_array(ponto_exc1, ex_prioritarios,225);
                    excluir_do_array(ponto_exc1, vizinhos,32);


                }
            }
    }
}



int tem_vizinhoNSLO(po_t pontoPrincipal, int tab[15][15], po_t vizinhos[]){
    int pontoX;
    int pontoY;
    int tem_vizinho;
    tem_vizinho = 0;
    pontoX = pontoPrincipal.x;
    pontoY = pontoPrincipal.y;
    po_t ponto_vizinho;
    if(pontoX < 15 && pontoX >=0 && pontoY < 15 && pontoY >=0){
    if (tab[pontoY-1][pontoX] == 2 && (pontoY-1 < 15 && pontoY-1 >=0) &&
    (pontoX < 15 && pontoX >=0 )) { //vizinho ao Norte
        ponto_vizinho.x = pontoX;
        ponto_vizinho.y = pontoY-1;
        tem_vizinho +=1;
        add_no_array(ponto_vizinho, vizinhos, 32);

    }
    if (tab[pontoY+1][pontoX] == 2 && (pontoY+1 < 15 && pontoY+1 >=0) &&
    (pontoX < 15 && pontoX >=0 )) { //vizinho ao Sul
        ponto_vizinho.x = pontoX;
        ponto_vizinho.y = pontoY+1;
        tem_vizinho +=1;
        add_no_array(ponto_vizinho, vizinhos, 32);
    }
    if (tab[pontoY][pontoX-1] == 2 && (pontoY < 15 && pontoY >=0) &&
    (pontoX-1 < 15 && pontoX-1 >=0 )) { //vizinho ao Leste
        ponto_vizinho.x = pontoX-1;
        ponto_vizinho.y = pontoY;
        tem_vizinho +=1;
        add_no_array(ponto_vizinho, vizinhos, 32);
    }
    if (tab[pontoY][pontoX+1] == 2 && (pontoY < 15 && pontoY >=0) &&
    (pontoX+1 < 15 && pontoX+1 >=0 )) { //vizinho ao Oeste
        ponto_vizinho.x = pontoX+1;
        ponto_vizinho.y = pontoY;
        tem_vizinho +=1;
        add_no_array(ponto_vizinho, vizinhos, 32);
    }
    }
//    ponto_vizinho.x = -1;
//    ponto_vizinho.y = -1;
//    add_no_array(ponto_vizinho, vizinhos, 32);
    if (tem_vizinho == 0){
        return -1;
    }
}

void criar_prioritarios (int tab[15][15], po_t possiveis_alvos[], po_t impossiveis[], po_t prioritarios[], po_t ex_prioritarios[]) {
    int i,j,k;
    k=0;
    po_t ponto_principal;
    po_t ponto_vizinho;
    po_t vizinhos[32];
    criar_array(vizinhos, 32);
    ponto_vizinho.x = -1;
    ponto_vizinho.y = -1;


    for (i=0; i<15; i++){
        for (j=0; j<15; j++){
            if (tab[j][i] == 2 && ponto_vizinho.x == -1 && ponto_vizinho.y == -1 ){
                ponto_principal.x = i;
                ponto_principal.y = j;
                if(buscar_no_array(ponto_principal, ex_prioritarios, 225) == -1) {
                    int vizinho;
                    vizinho = tem_vizinhoNSLO(ponto_principal, tab, vizinhos);
                    if (vizinho != -1) {
                        add_no_array(ponto_principal, vizinhos, 32);
                    }
                }
            }
        }
    }
    limpar_vizinhos(tab, vizinhos, ex_prioritarios);
    //printf("\nfim de add no vizinhos\n");
    printar_possiveis_alvos(vizinhos, 32);
    ponto_principal = menor_do_array(vizinhos, ex_prioritarios, tab);
    ponto_vizinho = maior_do_array(vizinhos,ex_prioritarios,tab, ponto_principal);

    //printf("ponto principal: %c%d \nponto vizinho: %c%d", str_eixo[ponto_principal.y], ponto_principal.x+1, str_eixo[ponto_vizinho.y], ponto_vizinho.x+1 );
    if (ponto_vizinho.x !=1 && ponto_vizinho.y !=-1) {
        int diferenca_x;
        int diferenca_y;
        po_t ponto_add1, ponto_add2, ponto_exc1, ponto_exc2, ponto_exc3, ponto_exc4;
        diferenca_x = ponto_vizinho.x - ponto_principal.x;
        diferenca_y = ponto_vizinho.y - ponto_principal.y;

        //add_no_array(ponto_principal, ex_prioritarios, 225);
        //add_no_array(ponto_vizinho, ex_prioritarios, 225);
       // printf("\ndiferencax = %d, diferenca y = %d\n", diferenca_x, diferenca_y);
        if (diferenca_x == 0 && (diferenca_y == 1 || diferenca_y == 2 || diferenca_y == 3 || diferenca_y == 4)) { // ponto 2 está abaixo do ponto 1
            ponto_add1.x = ponto_vizinho.x;
            ponto_add1.y = ponto_vizinho.y +1;
            ponto_add2.x = ponto_principal.x;
            ponto_add2.y = ponto_principal.y -1;
            if ((ponto_add1.y <=14 ||ponto_add1.y >= 0) && (ponto_add1.x <=14 ||ponto_add1.x >= 0)){
                add_no_array(ponto_add1, prioritarios, 225);
            }
            if ((ponto_add2.y <=14 ||ponto_add2.y >= 0) && (ponto_add2.x <=14 ||ponto_add2.x >= 0)){
                add_no_array(ponto_add2, prioritarios, 225);
            }


            for (i=0; i<=diferenca_y; i++){
                ponto_exc1.x = ponto_principal.x +1;
                ponto_exc1.y = ponto_principal.y+i;
                ponto_exc2.x = ponto_principal.x -1;
                ponto_exc2.y = ponto_principal.y+i;
                excluir_do_array(ponto_exc1, possiveis_alvos, 225);
                add_no_array(ponto_exc1, impossiveis, 225);
                excluir_do_array(ponto_exc2, possiveis_alvos, 225);
                add_no_array(ponto_exc2, impossiveis, 225);
            }
        }
        else if ((diferenca_x == 1 || diferenca_x == 2 || diferenca_x == 3 || diferenca_x == 4) && diferenca_y == 0) { // ponto 2 está a direita do ponto 1
            ponto_add1.x = ponto_vizinho.x+1;
            ponto_add1.y = ponto_vizinho.y;
            ponto_add2.x = ponto_principal.x-1;
            ponto_add2.y = ponto_principal.y;
            if ((ponto_add1.y <=14 ||ponto_add1.y >= 0) && (ponto_add1.x <=14 ||ponto_add1.x >= 0)){
                add_no_array(ponto_add1, prioritarios, 225);
            }
            if ((ponto_add2.y <=14 ||ponto_add2.y >= 0) && (ponto_add2.x <=14 ||ponto_add2.x >= 0)){
                add_no_array(ponto_add2, prioritarios, 225);
            }
             //printf("\nfim de add no prioritarios\n");


            for (i=0; i<=diferenca_x; i++){
                ponto_exc1.x = ponto_principal.x+i;
                ponto_exc1.y = ponto_principal.y+1;
                ponto_exc2.x = ponto_principal.x+i;
                ponto_exc2.y = ponto_principal.y-1;
                excluir_do_array(ponto_exc1, possiveis_alvos, 225);
                add_no_array(ponto_exc1, impossiveis, 225);
                excluir_do_array(ponto_exc2, possiveis_alvos, 225);
                add_no_array(ponto_exc2, impossiveis, 225);
            }



        }
    }
    //printf("\n VIZINHOS\n");
   // printar_possiveis_alvos(vizinhos, 32);
   // printf("\n");
}
