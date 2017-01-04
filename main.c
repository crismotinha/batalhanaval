#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "armas.h"
#include "player.h"
#include "iapc.h"

int tab[15][15];

int main()
{

    srand(time(NULL));
    //testes de IA
    /*po_t possiveis_alvos[225];

    player_t jogador1;
    criar_tabuleiro(jogador1.tab);
    jogador1 = criar_armas_player(jogador1);

    arma_t arma1;
    arma1 = criar_arma(3);
    arma1 = girar_arma(arma1, 2);

    po_t po1;
    po1.x = 4;
    po1.y = 6;

    po_t ponto;
    int acertou;

    colocar_peca(jogador1.tab, arma1, po1);

    ponto = escolher_ponto_pc_esperto(jogador1.tab, possiveis_alvos);
    acertou = atirar(jogador1.tab, ponto);
            if (acertou == 1) {
                printf("\nVocê acertou e continua jogando!\n");
                adicionar_possiveis_alvos(ponto, possiveis_alvos, jogador1.tab);
            }
            if (acertou == 0) {
                printf("\nVocê errou... Passe o controle para o outro jogador!\n");
            }


    */
    printf("==== Batalha Naval ====\n");
    printf("Jogador 1, seu oponente será um humano (1) ou o PC (2)?\n");
    int p2;
    scanf("%d", &p2);
    printf("Okay então! \nAgora vamos montar seu tabuleiro, player1!");

    player_t jogador1;
    jogador1.nome[3] = "P1";
    player_t jogador2;
    jogador1.nome[3] = "P2";
    criar_tabuleiro(jogador1.tab);
    criar_tabuleiro(jogador2.tab);
    jogador1 = criar_armas_player(jogador1);
    jogador2 = criar_armas_player(jogador2);
    po_t possiveis_alvos[225];

    //printf("Voce possui essas armas para colocar:\n");
    //printar_armas_disponiveis_player(jogador1.armas);
    printf("\n");
    criar_tab_pc(jogador1.tab, jogador1.armas);
    printf("Agora e a vez do player2 escolher seu tabuleiro!\n");
    if (p2 == 1){
        printf("Voce possui essas armas para colocar:\n");
        printar_armas_disponiveis_player(jogador2.armas);
        printf("\n");
        criar_tab_player(jogador2.tab, jogador2.armas);
    }
    else {
        criar_tab_pc(jogador2.tab, jogador2.armas);
    }
    printf("Tabuleiro P1:\n");
    exibir_tab_bonito(jogador1.tab);
    printf("Tabuleiro P2:\n");
    exibir_tab_bonito(jogador2.tab);
    printf("\nTabuleiros criados! Agora vamos começar a jogar!! \n");
    printf("\nJogador 1, você começa!\n");
    jogar_com_pc(jogador1.tab, jogador2.tab, possiveis_alvos);
    printf("\n ===ACABOU=== \n");


    return 0;
}
