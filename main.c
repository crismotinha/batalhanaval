#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "armas.h"
#include "player.h"
#include "game.h"

int tab[15][15];

int main()
{

    srand(time(NULL));

    printf("==== Batalha Naval ====\n");
    printf("Jogador 1, seu oponente será um humano (1) ou o PC (2)?\n");
    int p2;
    scanf("%d", &p2);
    printf("Okay então! \nAgora vamos montar seu tabuleiro, player1!");
    player_t jogador1;
    player_t jogador2;
    criar_tabuleiro(jogador1.tab);
    criar_tabuleiro(jogador2.tab);
    jogador1 = criar_armas_player(jogador1);
    jogador2 = criar_armas_player(jogador2);
    printf("Voce possui essas armas para colocar:\n");
    printar_armas_disponiveis_player(jogador1.armas);
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
    printf("\nTabuleiros criados! Agora vamos começar a jogar!! \n");
    printf("\nJogador 1, você começa!\n");
    while (tudo_destruido(jogador2.tab) == 0 && tudo_destruido(jogador2.tab) == 0){
        int acertou;
        acertou = atirar(jogador1.tab);
        if (acertou == 1) {
            printf("\nVocê acertou e continua jogando!\n");
            acertou = atirar(jogador1.tab);
        }
        if (acertou == 0) {
            printf("\nVocê errou... Passe o controle para o outro jogador!\n");
            acertou = atirar(jogador2.tab);
        }

    }
    printf("\n ===ACABOU=== \n");

    return 0;
}
