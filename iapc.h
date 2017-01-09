#ifndef IAPC_H
#define IAPC_H

po_t escolher_ponto_pc_esperto(int tab[15][15], po_t possiveis_alvos[], po_t impossiveis[], po_t prioritarios[]);
po_t buscar_ponto_valido (po_t array[], int tab[15][15]);
void limpar_array(po_t array[], int tab[15][15]);
int criar_array(po_t array[], int tamanho);
void printar_possiveis_alvos(po_t array[], int tamanho);
int buscar_espaco_array(po_t array[]);
int buscar_no_array(po_t ponto, po_t array[], int tamanho);
void adicionar_possiveis_alvos_oito (po_t ponto, po_t possiveis_alvos[], int tab[15][15]);
void adicionar_possiveis_alvos(po_t ponto, po_t possiveis_alvos[], int tab[15][15]);
void add_no_array(po_t ponto, po_t array[], int tamanho);
void excluir_do_array(po_t ponto, po_t array[], int tamanho);
po_t menor_do_array(po_t array[], int tab[15][15],po_t ex_prioritarios[]);
po_t maior_do_array(po_t array[], int tab[15][15],po_t ex_prioritarios[], po_t menor);
void limpar_vizinhos(int tab[15][15], po_t vizinhos[],po_t ex_prioritarios[]);
int tem_vizinhoNSLO(po_t pontoPrincipal, int tab[15][15], po_t vizinhos[]);
void criar_prioritarios (int tab[15][15], po_t possiveis_alvos[], po_t impossiveis[], po_t prioritarios[], po_t ex_prioritarios[]);

#endif

