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


    */

