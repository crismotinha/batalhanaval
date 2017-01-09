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

    //======Scripts de testes:======
    /*As funções possuem printfs de teste, quase todas elas. Para alterar o modo de jogo com o pc,
    botando ele para jogar sozinho por exemplo (como eu fiz com os testes de "eficiência"), estão indicadas
    as linhas a se descomentar e comentar no game.c (e usar o script abaixo, que cria tudo sozinho pro P1)
    Todos os testes abaixo supõem que você queira jogar com o PC*/

    //Para não montar seu tabuleiro (pc sortear sozinho os 2) e exibi-los no final:

//    printf("==== Batalha Naval ====\n");
//    printf("\nLegenda:\n ██ => 1 pedaço de navio\n  x => Atirou e acertou\n ww => Atirou e errou\n -- => Não atirou\n");
//    printf("\nPara sair a qualquer momento, aperte ctrl+c\n")/
//    printf("\n\nJogador 1, seu oponente será um humano (1) ou o PC (2)?\n");
//    int p2;
//    p2 = 2;
//    printf("Okay então! \nAgora vamos montar seu tabuleiro, Jogador 1!");
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
//
//    printf("\n");
//    criar_tab_pc(jogador1.tab, jogador1.armas);
//    printf("Agora e a vez do Jogador 2 escolher seu tabuleiro!\n");
//    if (p2 == 1){
//        printf("Voce possui essas armas para colocar:\n");
//        printar_armas_disponiveis_player(jogador2.armas);
//        printf("\n");
//        criar_tab_pc(jogador2.tab, jogador2.armas);
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
//    if (p2 == 1) {
//        jogar_com_player(jogador1.tab, jogador2.tab);
//    }
//    else {
//        jogar_com_pc(jogador1.tab, jogador2.tab, possiveis_alvos, impossiveis, prioritarios, ex_prioritarios);
//    }
//    printf("\n ===ACABOU=== \n");
//
//    return 0;
//}









    //======Jogo real:======

    printf("==== Batalha Naval ====\n");
    printf("\nLegenda:\n ██ => 1 pedaço de navio\n  x => Atirou e acertou\n ww => Atirou e errou\n -- => Não atirou\n");
    printf("\nPara sair a qualquer momento, aperte ctrl+c\n")/
    printf("\n\nJogador 1, seu oponente será um humano (1) ou o PC (2)?\n");
    int p2;
    //p2 = 2;
    scanf("%d", &p2);
    printf("Okay então! \nAgora vamos montar seu tabuleiro, Jogador 1!");

    player_t jogador1;
    player_t jogador2;
    po_t possiveis_alvos[225];
    po_t prioritarios[225];
    po_t impossiveis[225];
    po_t ex_prioritarios[225];

    criar_tabuleiro(jogador1.tab);
    criar_tabuleiro(jogador2.tab);
    jogador1 = criar_armas_player(jogador1);
    jogador2 = criar_armas_player(jogador2);



    printf("\n");
    criar_tab_player(jogador1.tab, jogador1.armas);
    printf("Agora e a vez do Jogador 2 escolher seu tabuleiro!\n");
    if (p2 == 1){
        printf("Voce possui essas armas para colocar:\n");
        printar_armas_disponiveis_player(jogador2.armas);
        printf("\n");
        criar_tab_pc(jogador2.tab, jogador2.armas);
    }
    else {
        criar_tab_pc(jogador2.tab, jogador2.armas);
    }
//    printf("Tabuleiro P1:\n");
//    exibir_tab_bonito(jogador1.tab);
//    printf("Tabuleiro P2:\n");
//    exibir_tab_bonito(jogador2.tab);
    printf("\nTabuleiros criados! Agora vamos começar a jogar!! \n");
    printf("\nJogador 1, você começa!\n");
    if (p2 == 1) {
        jogar_com_player(jogador1.tab, jogador2.tab);
    }
    else {
        jogar_com_pc(jogador1.tab, jogador2.tab, possiveis_alvos, impossiveis, prioritarios, ex_prioritarios);
    }
    printf("\n ===ACABOU=== \n");

    return 0;
}
