#ifndef GAME_H
#define GAME_H

void exibir_tab_bonito(int tab[15][15]);
void exibir_tab_bonito_inimigo(int tab[15][15]);
po_t escolher_ponto_player();
po_t escolher_ponto_pc_burro(int tab[15][15]);
int atirar(int tab[15][15], po_t ponto);
int atirar_sem_print(int tab[15][15], po_t ponto);
int tudo_destruido(int tab[15][15]);
void jogar_com_player(int tab_p1[15][15],int tab_p2[15][15]);
void jogar_com_pc(int tab_p1[15][15],int tab_p2[15][15], po_t possiveis_alvos[225], po_t impossiveis[225],po_t prioritarios[225], po_t ex_prioritarios[225]);




#endif
