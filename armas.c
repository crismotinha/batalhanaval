#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "armas.h"
#include "game.h"
char str_eixo[17] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O'}; //Para printar o enum. O zero é só pra começar com A = 1
char* str_tipo_arma[6] = {"0","submarino", "cruzador", "hidroaviao", "encouracado", "porta avioes"}; //Para printar o enum. O zero é só pra começar com A = 1

int buscar_ponto(char buscado){
    int i;
    for(i=0; i<17; i++) {
        if(str_eixo[i] == buscado) {
            return i;
        }
    }
}

int criar_tabuleiro (int tab[15][15]){
    int i,j;
    for (i=0; i<15; i++){
        for (j=0; j<15; j++){
            tab[i][j] = 0;
        }
    }
    return tab;
}

int foi_atingido(po_t po, int tab[15][15]){
    int i,j;
    for (i=0; i<15; i++){
        if (i == po.x){
            for (j=0; j<15; j++){
                if (j == po.y) {
                    if (tab[j][i] == 1) {
                        tab[j][i] = 2;
                        printf("Foi atingido no ponto %c%d", str_eixo[j], i+1);
                        return 1;
                    }
                    else {
                        tab[j][i] = 3;
                        printf("Não foi atingido");
                        return 0;
                    }
                }
            }
        }
    }
}

void printar_pontos (arma_t arma){
    int i;
    for (i=0; i<5; i++){
        printf("x = %d, y= %d \n", arma.pontos[i].x , arma.pontos[i].y );
    }
}
void printar_tabuleiro (int tab[15][15]){
    int i,j;
    for (i=0; i<15; i++){
        for (j=0; j<15; j++){
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

arma_t girar_arma(arma_t arma, int orient){
    int mudanca = arma.orient - orient;
    int i;
    arma_t nova_arma;
    nova_arma.tipo_arma = arma.tipo_arma;
    nova_arma.orient = orient;
    po_t pontos[5];
    if (mudanca == 0) {
        return arma;
    }
    else if (mudanca == -3 || mudanca == 1) { //girou 90 horario (lembrando que o y da matriz cresce pra baixo)
        for (i=0; i<5; i++){
                pontos[i].x = (arma.pontos[i].y);
                pontos[i].y = -(arma.pontos[i].x);
                nova_arma.pontos[i].x = pontos[i].x;
                nova_arma.pontos[i].y = pontos[i].y;
        }
        return nova_arma;
    }
    else if (mudanca == -1 || mudanca == 3) { //girou 90 anti horario
        for (i=0; i<5; i++){
                pontos[i].x = -(arma.pontos[i].y);
                pontos[i].y = (arma.pontos[i].x);
                nova_arma.pontos[i].x = pontos[i].x;
                nova_arma.pontos[i].y = pontos[i].y;
        }
        return nova_arma;
    }
    else if (mudanca == 2 && (arma.orient == 1 || arma.orient == 3) ) {// se era norte e virou sul ou vice versa - espelho horizontal
        for (i=0; i<5; i++){
                pontos[i].x = (arma.pontos[i].x);
                pontos[i].y = -(arma.pontos[i].y);
                nova_arma.pontos[i].x = pontos[i].x;
                nova_arma.pontos[i].y = pontos[i].y;
        }
        return nova_arma;
    }
    else if (mudanca == 2 && (arma.orient == 2 || arma.orient == 4)) {// se era oeste e virou leste ou vice versa - espelho vertical
        for (i=0; i<5; i++){
                pontos[i].x = -(arma.pontos[i].x);
                pontos[i].y = -(arma.pontos[i].y);
                nova_arma.pontos[i].x = pontos[i].x;
                nova_arma.pontos[i].y = pontos[i].y;
        }
        return nova_arma;
    }
}

arma_t criar_arma (int tipo_escolhido){
    arma_t nova_arma;
    nova_arma.orient = 4;
    nova_arma.usada = false;
    po_t pontos[5];
    //Definindo os pontos VIRADOS PARA O OESTE (default):
    //primeiro ponto é sempre 0,0
        pontos[0].x = 0;
        pontos[0].y = 0;
    //a partir do segundo:
    int i;
        if (tipo_escolhido == submarino) {
            for (i=1; i<5; i++){
                pontos[i].x = 0;
                pontos[i].y = 0;
            }
        }
        else if (tipo_escolhido == cruzador) {
            pontos[1].x = 1;
            pontos[1].y = 0;
            for (i=2; i<5; i++){
                pontos[i].x = 0;
                pontos[i].y = 0;
            }
        } else if (tipo_escolhido == hidroaviao) {
            pontos[1].x = 1;
            pontos[1].y = 1;
            pontos[2].x = 1;
            pontos[2].y = -1;
            for (i=3; i<5; i++){
                pontos[i].x = 0;
                pontos[i].y = 0;
            }
        }
        else if (tipo_escolhido == encouracado) {
            pontos[1].x = 1;
            pontos[1].y = 0;
            pontos[2].x = 2;
            pontos[2].y = 0;
            pontos[3].x = 3;
            pontos[3].y = 0;
            pontos[4].x = 0;
            pontos[4].y = 0;
        }
        else if (tipo_escolhido == portaavioes) {
            pontos[1].x = 1;
            pontos[1].y = 0;
            pontos[2].x = 2;
            pontos[2].y = 0;
            pontos[3].x = 3;
            pontos[3].y = 0;
            pontos[4].x = 4;
            pontos[4].y = 0;
        }

    nova_arma.tipo_arma = tipo_escolhido;
    for (i=0; i<5; i++){
        nova_arma.pontos[i].x = pontos[i].x;
        nova_arma.pontos[i].y = pontos[i].y;
    }
    return nova_arma;
}

int contida_tab(int tab[15][15], arma_t arma, po_t p_origem){
    int i;
    int contida;
    contida = 0;
    for (i=0; i<5; i++){
        int pontoX = arma.pontos[i].x + p_origem.x;
        int pontoY = arma.pontos[i].y + p_origem.y;
        if(pontoX < 15 && pontoX >=0 && pontoY < 15 && pontoY >=0){
            contida +=1;
        }
    }
    if (contida == 5) { //OU SEJA, todos os pontos estão dentro
        return 1;
    }
    else {
        return 0;
    }

}
int toca_outra_fig(int tab[15][15], arma_t arma, po_t p_origem){
    int i;
    int vizinhos = 0;
    for (i=0; i<5; i++){
            /*Matriz: mat[n_linhas][n_colunas]. Logo, meu n_linhas é o "vetor" y, e o
        n_colunas é o "vetor" x do tabuleiro. Sendo assim, tab[y][x], e não tab[x][y]. */
        int pontoX = arma.pontos[i].x + p_origem.x; //tab[pontoY][pontoX]
        int pontoY = arma.pontos[i].y + p_origem.y;
        int maxTamanho = 14;

        // vizinho a direita
            if (pontoX+1 <= maxTamanho){
                vizinhos += tab[pontoY][pontoX+1];
            }
            // vizinho a esquerda
            if (pontoX-1 >= 0){
                vizinhos += tab[pontoY][pontoX-1];
            }
            // vizinho abaixo (funcao cresce p baixo)
            if (pontoY+1 <= maxTamanho){
                vizinhos += tab[pontoY+1][pontoX];
            }
            // vizinho acima
            if (pontoY-1 >= 0){
                vizinhos +=tab[pontoY-1][pontoX];
            }
            // vizinho abaixo - esquerda
            if ((pontoX-1 >= 0) && (pontoY+1 < maxTamanho)){
                vizinhos += tab[pontoY+1][pontoX-1];
            }
            // vizinho abaixo - direita
            if ((pontoX+1 <= maxTamanho)&&(pontoY+1 <= maxTamanho)){
                vizinhos += tab[pontoY+1][pontoX+1];
            }
            // vizinho cima - esquerda
            if ((pontoX-1 >= 0) && (pontoY-1 >= 0)){
                vizinhos += tab[pontoY-1][pontoX-1];
            }
            // vizinho cima - direita
            if ((pontoX+1 <= maxTamanho) && (pontoY-1 >= 0)){
                vizinhos +=tab[pontoY-1][pontoX+1];
            }

            if (vizinhos != 0) {
                return 0;
            }

    }
    return 1;
}
int intersecta_outra_fig (int tab[15][15], arma_t arma, po_t p_origem){
    int i;
    for (i=0; i<5; i++){
       int pontoX = arma.pontos[i].x + p_origem.x;
       int pontoY = arma.pontos[i].y + p_origem.y;
       if (tab[pontoY][pontoX] != 0){
            return 0; //intersecta
       }
    }
    return 1;
}

int posicao_valida(int tab[15][15], arma_t arma, po_t p_origem){
    int esta_contida = contida_tab(tab, arma, p_origem);
    int nao_toca_outra = toca_outra_fig(tab, arma, p_origem);
    int nao_intersecta = intersecta_outra_fig(tab, arma, p_origem);
    int total = esta_contida + nao_toca_outra + nao_intersecta;
    if (total == 3) {//ou seja, obedece todos os requisitos
        return 1;
    }
    else {
        return 0;
    }
}

int buscar_por_tipo(arma_t armas[13], int tipo){
    int i;
    for(i=0; i<13;i++){
        if ((armas[i].tipo_arma == tipo) && (armas[i].usada == false)){
            return i;
        }
    }
    return -1;
}
int armas_usadas(arma_t armas[13]){
    int i;
    int usadas = 0;
    for(i=0; i<13;i++){
        if (armas[i].usada == true){
            usadas += 1;
        }
    }
    return usadas;
}

int colocar_peca (int tab[15][15], arma_t arma, po_t p_origem) {
    int posicao_ok = posicao_valida(tab, arma, p_origem);
    if (posicao_ok == 1) {
        int i;
        for (i=0; i<5; i++){
        /*Matriz: mat[n_linhas][n_colunas]. Logo, meu n_linhas é o "vetor" y, e o
        n_colunas é o "vetor" x do tabuleiro. Sendo assim, tab[y][x], e não tab[x][y]. */
            tab[p_origem.y+arma.pontos[i].y][p_origem.x+arma.pontos[i].x] = 1;
        }
    }
    else {
        //printf("\nPosicao invalida\n");
        return 0;
    }
//    exibir_tab_bonito(tab);
    //printar_tabuleiro(tab);
    return 1;
}

int colocar_peca_sem_print (int tab[15][15], arma_t arma, po_t p_origem) {
    int posicao_ok = posicao_valida(tab, arma, p_origem);
    if (posicao_ok == 1) {
        int i;
        for (i=0; i<5; i++){
        /*Matriz: mat[n_linhas][n_colunas]. Logo, meu n_linhas é o "vetor" y, e o
        n_colunas é o "vetor" x do tabuleiro. Sendo assim, tab[y][x], e não tab[x][y]. */
            tab[p_origem.y+arma.pontos[i].y][p_origem.x+arma.pontos[i].x] = 1;
        }
    }
    else {
        return 0;
    }
    return 1;
}

