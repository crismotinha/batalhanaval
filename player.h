#ifndef PLAYER_H
#define PLAYER_H

typedef struct player { char nome[10];
                        arma_t armas[13];
                        int tab[15][15]; } player_t;
extern player_t player1;
extern player_t player2;
extern po_t possiveis_alvos[225];

player_t criar_armas_player(player_t player);
void printar_armas_disponiveis_player(arma_t armas[13]);
void criar_tab_player(int tab[15][15], arma_t armas[13]);
void criar_tab_pc(int tab[15][15], arma_t armas[13]);



#endif
