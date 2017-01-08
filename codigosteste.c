 /* tabuleiro
    criar_tabuleiro(tab);
    printf("tabuleiro vazio: \n");
    printar_tabuleiro(tab);
    printf("\n");
    arma_t arma1;
    arma_t arma2;
    arma1.orient = 4;
    arma1.tipo_arma = 5;
    arma1.pontos[0].x = 0;
    arma1.pontos[0].y = 0;
    arma1.pontos[1].x = 1;
    arma1.pontos[1].y = 0;
    arma1.pontos[2].x = 2;
    arma1.pontos[2].y = 0;
    arma1.pontos[3].x = 3;
    arma1.pontos[3].y = 0;
    arma1.pontos[4].x = 4;
    arma1.pontos[4].y = 0;
    printar_pontos(arma1);
    printf("\nGirou:\n");
    arma1 = girar_arma(arma1, 3);
    printar_pontos(arma1);



    arma1 = criar_arma();

    po_t po1;
    po1.x = 7;
    po1.y = 7;

    colocar_peca(tab, arma1, po1);

    printar_tabuleiro(tab);

    --xx-- Armas que estavam sobrepondo
    arma_t arma1;
    arma1 = criar_arma(3);
    arma1 = girar_arma(arma1, 2);

    po_t po1;
    po1.x = 4;
    po1.y = 6;

    arma_t arma2;
    arma2 = criar_arma(3);
    arma2 = girar_arma(arma2, 3);

    po_t po2;
    po2.x = 2;
    po2.y = 9;

    colocar_peca(jogador1.tab, arma1, po1);
    colocar_peca(jogador1.tab, arma2, po2);
    --
    for (i=0; i<15; i++){
            for (j=0; j<15; j++){
                if (tab[j][i] == 2){ //já acertou em algum lugar
                   ponto.x = i+1;
                   ponto.y = j;
                   return ponto;
                }
            }
        }
    --- codigo da funcao--
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
            ponto_final.x = ponto.x + 1;
            ponto_final.y = ponto.y + 1;
            return ponto_final;
            }
        }
        i++;
    }
    //se ele não achar nada de bom nos possiveis alvos, ele sorteia random
    ponto.x = rand()%14;
    ponto.y = rand()%14;
    if (tab[ponto.y][ponto.x] != 2 && tab[ponto.y][ponto.x] != 3) {
        ponto_final.x = ponto.x + 1;
        ponto_final.y = ponto.y + 1;
        return ponto_final;
    }

}
--- tabuleiro do print --
jogador1.tab[2][3] = 2;
    jogador1.tab[2][4] = 2;
    jogador1.tab[2][5] = 2;
    jogador1.tab[2][6] = 2;



    jogador1.tab[6][11] = 2;

    jogador1.tab[13][8] = 2;


    jogador1.tab[0][1] = 3;
    jogador1.tab[0][2] = 3;
    jogador1.tab[0][7] = 3;
    jogador1.tab[1][3] = 3;
    jogador1.tab[1][4] = 3;
    jogador1.tab[1][7] = 3;
    jogador1.tab[1][10] = 3;
    jogador1.tab[1][11] = 3;
    jogador1.tab[2][8] = 3;
    jogador1.tab[3][3] = 3;
    jogador1.tab[3][4] = 3;
    jogador1.tab[3][9] = 3;
    jogador1.tab[4][2] = 3;
    jogador1.tab[4][8] = 3;
    jogador1.tab[5][1] = 3;
    jogador1.tab[5][11] = 3;
    jogador1.tab[6][5] = 3;
    jogador1.tab[6][10] = 3;
    jogador1.tab[6][12] = 3;
    jogador1.tab[7][11] = 3;
    jogador1.tab[8][10] = 3;
    jogador1.tab[9][5] = 3;
    jogador1.tab[9][12] = 3;
    jogador1.tab[10][10] = 3;
    jogador1.tab[12][1] = 3;
    jogador1.tab[12][6] = 3;
    jogador1.tab[12][8] = 3;
    jogador1.tab[12][10] = 3;
    jogador1.tab[13][1] = 3;
    jogador1.tab[13][9] = 3;
    jogador1.tab[13][7] = 3;
    jogador1.tab[14][8] = 3;
int arma_destruida(int tab[15][15], po_t ponto,  po_t impossiveis[]){
    po_t vizinhos[32];
    criar_array(vizinhos, 32);
    po_t ponto_principal;
    po_t ponto_vizinho;
    int i;
    if (tab[ponto.y][ponto.x] == 2) {
        if (tab[ponto.y-1][ponto.x] == 3 && tab[ponto.y+1][ponto.x] == 3
            && tab[ponto.y][ponto.x-1] == 3 && tab[ponto.y][ponto.x+1] == 3) { //cercada
                    return 1;
            }
        int vizinho;
        vizinho = tem_vizinhoNSLO(ponto, tab, vizinhos);
        if (vizinho != -1) {
            add_no_array(ponto, vizinhos, 32);
        }
    }
    ponto_principal = menor_do_array(vizinhos);
    ponto_vizinho = maior_do_array(vizinhos);
    int pontos_p_destruidos; //ver se os pontos prioritários dele foram destruidos
    int pontos_l_destruidos; //ver se os pontos laterais foram destruidos
    if (ponto_vizinho.x !=1 && ponto_vizinho.y !=-1) {
        int diferenca_x;
        int diferenca_y;
        po_t ponto_1, ponto_2, ponto_l1, ponto_l2;
        diferenca_x = ponto_vizinho.x - ponto_principal.x;
        diferenca_y = ponto_vizinho.y - ponto_principal.y;

        if (diferenca_x == 0 && (diferenca_y == 1 || diferenca_y == 2 || diferenca_y == 3 || diferenca_y == 4)) { // ponto 2 está abaixo do ponto 1
            ponto_1.x = ponto_vizinho.x;
            ponto_1.y = ponto_vizinho.y +1;
            ponto_2.x = ponto_principal.x;
            ponto_2.y = ponto_principal.y -1;
            if (tab[ponto_1.y][ponto_1.x] == 3 && tab[ponto_2.y][ponto_2.x] == 3){
                pontos_p_destruidos = 1;
            }


            for (i=0; i<=diferenca_y; i++){
                ponto_l1.x = ponto_principal.x +1;
                ponto_l1.y = ponto_principal.y+i;
                ponto_l2.x = ponto_principal.x -1;
                ponto_l2.y = ponto_principal.y+i;
                if (buscar_no_array(ponto_l1, impossiveis, 225) != -1 &&
                buscar_no_array(ponto_l2, impossiveis, 225)!= -1){
                    pontos_l_destruidos +=1;
                }
            }
        }
        else if ((diferenca_x == 1 || diferenca_x == 2 || diferenca_x == 3 || diferenca_x == 4) && diferenca_y == 0) { // ponto 2 está a direita do ponto 1
            ponto_1.x = ponto_vizinho.x+1;
            ponto_1.y = ponto_vizinho.y;
            ponto_2.x = ponto_principal.x-1;
            ponto_2.y = ponto_principal.y;
            if (tab[ponto_1.y][ponto_1.x] == 3 && tab[ponto_2.y][ponto_2.x] == 3){
                pontos_p_destruidos = 1;
            }

            for (i=0; i<=diferenca_x; i++){
                ponto_l1.x = ponto_principal.x+i;
                ponto_l1.y = ponto_principal.y+1;
                ponto_l2.x = ponto_principal.x+i;
                ponto_l2.y = ponto_principal.y-1;
                if (buscar_no_array(ponto_l1, impossiveis, 225) != -1 &&
                buscar_no_array(ponto_l2, impossiveis, 225)!= -1){
                    pontos_l_destruidos +=1;
                }
            }
        }
        if (pontos_l_destruidos != 0 && pontos_p_destruidos != 0){
            return 1;
        }
        else {
            return 0;
        }
    }

}

    */

