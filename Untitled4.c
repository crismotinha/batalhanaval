po_t menor_do_array(po_t array[], int tab[15][15]){
    int i;
    po_t menor;
    menor = array[0];

    for (i=0;i<32;i++){
        if(tab[array[i].y][array[i].x]!=2){
            if(array[i].x == array[0].x) {

                if (array[i].y < menor.y && array[i].y != -1)
                    menor.x = array[i].x;
                    menor.y = array[i].y;

            }
            if(array[i].y == array[0].y) {
                if (array[i].x < menor.x && array[i].x != -1)
                    menor.x = array[i].x;
                    menor.y = array[i].y;

            }
        }
    }
    return menor;
}
po_t maior_do_array(po_t array[], int tab[15][15]){
    int i;
    po_t maior;
    maior = array[0];

    for (i=0;i<32;i++){
        if(tab[array[i].y][array[i].x]!=2){
            if(array[i].x == array[0].x) {
                if (array[i].y > maior.y)
                    maior.x = array[i].x;
                    maior.y = array[i].y;

            }
            if(array[i].y == array[0].y) {
                if (array[i].x > maior.x)
                    maior.x = array[i].x;
                    maior.y = array[i].y;

            }
        }
    }
    return maior;
}
