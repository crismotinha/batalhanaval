#ifndef IAPC_H
#define IAPC_H

int criar_array(po_t array[225]);
int buscar_espaco_array(po_t array[]);
int buscar_no_array(po_t ponto, po_t array[]);
po_t escolher_ponto_pc_esperto(int tab[15][15], po_t possiveis_alvos[], po_t impossiveis[], po_t prioritarios[]);
po_t buscar_ponto_valido (po_t array[], int tab[15][15]);



#endif

