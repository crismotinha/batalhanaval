#ifndef ARMAS_H
#define ARMAS_H
typedef enum { false, true } bool;

enum tipo_arma {submarino = 1, cruzador = 2,
hidroaviao = 3, encouracado = 4, portaavioes = 5};
enum orient {norte = 1, leste = 2, sul = 3, oeste = 4};
enum eixo_y {A=1,B,C,D,E,F,G,H,I,J,K,L,M,N,O};
extern char str_eixo[17];
extern char* str_tipo_arma[6];

typedef struct po {int x; //po = par ordenado
                    int y;} po_t;
typedef struct arma { int tipo_arma;
                      po_t pontos[5];
                      int orient;
                      bool usada;
                } arma_t;

int buscar_ponto(char buscado);
int criar_tabuleiro (int tab[15][15]);
int foi_atingido(po_t po, int tab[15][15]);
void printar_pontos (arma_t arma);
void printar_tabuleiro (int tab[15][15]);
arma_t girar_arma(arma_t arma, int orient);
arma_t criar_arma (int tipo_escolhido);
int contida_tab(int tab[15][15], arma_t arma, po_t p_origem);
int toca_outra_fig(int tab[15][15], arma_t arma, po_t p_origem);
int intersecta_outra_fig (int tab[15][15], arma_t arma, po_t p_origem);

int posicao_valida(int tab[15][15], arma_t arma, po_t p_origem);
int buscar_por_tipo(arma_t armas[13], int tipo);
int armas_usadas(arma_t armas[13]);

int colocar_peca (int tab[15][15], arma_t arma, po_t p_origem);
int colocar_peca_sem_print (int tab[15][15], arma_t arma, po_t p_origem);

#endif
