#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "armas.h"
#include "player.h"
#include "iapc.h"
#include "game.h"

int tab[15][15];

int main()
{

    srand(time(NULL));


    //testes de IA
    po_t possiveis_alvos[225];
    po_t ex_prioritarios[225];
    po_t impossiveis[225];
    criar_array(possiveis_alvos, 225);
    criar_array(ex_prioritarios, 225);
    criar_array(impossiveis, 225);

    player_t jogador1;
    criar_tabuleiro(jogador1.tab);
    jogador1 = criar_armas_player(jogador1);

    jogador1.tab[2][1] = 2;
    jogador1.tab[2][2] = 2;

    jogador1.tab[4][6] = 2;
//===x===
    po_t po1;
    po1.x = 11;
    po1.y = 7;
    po_t po2;
    po2.x = 11;
    po2.y = 8;
    po_t po3;
    po3.x = 11;
    po3.y = 9;
    po_t po4;
    po4.x = 11;
    po4.y = 10;

    po_t po5;
    po5.x = 10;
    po5.y = 6;
    po_t po6;
    po6.x = 10;
    po6.y = 5;
    po_t po7;
    po7.x = 10;
    po7.y = 4;
    po_t po8;
    po8.x = 10;
    po8.y = 3;

    jogador1.tab[6][11] = 3;
    jogador1.tab[11][11] = 3;
//    jogador1.tab[9][11] = 2;
//    jogador1.tab[10][11] = 2;
    exibir_tab_bonito(jogador1.tab);
    add_no_array(po1, impossiveis, 225);
    add_no_array(po2, impossiveis, 225);
    add_no_array(po3, impossiveis, 225);
    add_no_array(po4, impossiveis, 225);
    add_no_array(po5, impossiveis, 225);
    add_no_array(po6, impossiveis, 225);
    add_no_array(po7, impossiveis, 225);
    add_no_array(po8, impossiveis, 225);

    po_t maior;
    po_t menor;

    printar_possiveis_alvos(impossiveis);

    maior = maior_do_array(impossiveis, jogador1.tab, ex_prioritarios);
    menor = menor_do_array(impossiveis, jogador1.tab, ex_prioritarios);

    printf("\nmenor: %c%d", str_eixo[menor.y], menor.x+1 );
    printf("\nmaior: %c%d", str_eixo[maior.y], maior.x+1 );
    printf("\n\n");
    limpar_prioritarios(jogador1.tab, impossiveis, ex_prioritarios);
    maior = maior_do_array(impossiveis, jogador1.tab, ex_prioritarios);
    menor = menor_do_array(impossiveis, jogador1.tab, ex_prioritarios);
    printf("\n\n printando os ex prioritarios\n");
    printar_possiveis_alvos(ex_prioritarios);

    printf("\n\n printando os prioritarios atuais\n");
    printar_possiveis_alvos(impossiveis);


    printf("\nmenor: %c%d", str_eixo[menor.y], menor.x+1 );
    printf("\nmaior: %c%d", str_eixo[maior.y], maior.x+1 );
////    ===x===

//    jogador1.tab[3][2] = 3;
//    jogador1.tab[2][3] = 3;
//
//    jogador1.tab[3][6] = 3;
//    jogador1.tab[5][6] = 3;
//
//
//
//    exibir_tab_bonito_inimigo(jogador1.tab);
//                printf("\n PRIORITARIOS:\n");
//                printar_possiveis_alvos(prioritarios);
//
//                printf("\n pontos possiveis:\n");
//                printar_possiveis_alvos(possiveis_alvos);
//
//                printf("\n pontos impossiveis:\n");
//                printar_possiveis_alvos(impossiveis);
//
//                //criar_prioritarios(jogador1.tab, possiveis_alvos, impossiveis, prioritarios);
//
//                printf("\n PRIORITARIOS:\n");
//                printar_possiveis_alvos(prioritarios);
//
//                printf("\n pontos possiveis:\n");
//                printar_possiveis_alvos(possiveis_alvos);
//
//                printf("\n pontos impossiveis:\n");
//                printar_possiveis_alvos(impossiveis);
//
//jogador1.tab[4][7] = 2;
//exibir_tab_bonito_inimigo(jogador1.tab);
//
//criar_prioritarios(jogador1.tab, possiveis_alvos, impossiveis, prioritarios);
//
//printf("\n PRIORITARIOS:\n");
//                printar_possiveis_alvos(prioritarios);
//
//                printf("\n pontos possiveis:\n");
//                printar_possiveis_alvos(possiveis_alvos);
//
//                printf("\n pontos impossiveis:\n");
//                printar_possiveis_alvos(impossiveis);

//    printf("==== Batalha Naval ====\n");
//    printf("\nLegenda:\n ██ => 1 pedaço de navio\n  x => Atirou e acertou\n ww => Atirou e errou\n -- => Não atirou\n");
//    printf("\nPara sair a qualquer momento, aperte ctrl+c\n")/
//    printf("\n\nJogador 1, seu oponente será um humano (1) ou o PC (2)?\n");
//    int p2;
//    p2 = 2;
//    //scanf("%d", &p2);
//    //printf("Okay então! \nAgora vamos montar seu tabuleiro, Jogador 1!");
//
//    player_t jogador1;
//    player_t jogador2;
//    po_t possiveis_alvos[225];
//    po_t prioritarios[225];
//    po_t impossiveis[225];
//    po_t ex_prioritarios[225];
//
//    criar_tabuleiro(jogador1.tab);
//    criar_tabuleiro(jogador2.tab);
//    jogador1 = criar_armas_player(jogador1);
//    jogador2 = criar_armas_player(jogador2);
//
//
//    //printf("Voce possui essas armas para colocar:\n");
//    //printar_armas_disponiveis_player(jogador1.armas);
//    printf("\n");
//    criar_tab_pc(jogador1.tab, jogador1.armas);
//   // printf("Agora e a vez do Jogador 2 escolher seu tabuleiro!\n");
//    if (p2 == 1){
//        printf("Voce possui essas armas para colocar:\n");
//        printar_armas_disponiveis_player(jogador2.armas);
//        printf("\n");
//        criar_tab_player(jogador2.tab, jogador2.armas);
//    }
//    else {
//        criar_tab_pc(jogador2.tab, jogador2.armas);
//    }
//    printf("Tabuleiro P1:\n");
//    exibir_tab_bonito(jogador1.tab);
//    printf("Tabuleiro P2:\n");
//    exibir_tab_bonito(jogador2.tab);
//    printf("\nTabuleiros criados! Agora vamos começar a jogar!! \n");
//    printf("\nJogador 1, você começa!\n");
//    jogar_com_pc(jogador1.tab, jogador2.tab, possiveis_alvos, impossiveis, prioritarios, ex_prioritarios);
//    printf("\n ===ACABOU=== \n");



    return 0;
}
