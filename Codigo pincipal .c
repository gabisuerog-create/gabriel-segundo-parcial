c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "reto.h"

/* Funcion calcular: procesa las muestras segun la regla especifica del reto */
void calcular(const int muestras_unidad|, intm, int tipo, int p, int *estado, int *score_out) {
    int presupuesto = p + 50;
    int usado = 0;
    int score = 0;
    int i;

    if (tipo == 0) {
        /* De izquierda a derecha */
        for (i = 0; i< m; i++) {
            if (muestras_unidad[i] < 0 || muestras_unidad[i] > 100) {
                 /* Dominio invalido manejado a nivel general */
            }
            if (usado + muestras_unidad[i] <= presupuesto) {
                usado += muestras_unidad[i];
                score++;
            }
        }
    }
    /* Regla del estado: estado = 1 si 2*usado >= presupuesto; si no, 0 */
    if (2 * usado >= presupuesto) {
        *estado = 1;
    } else {
       *estado = 0;
    }

    *score_out = score;
}

/* Total_rec: suma recursivamente los scores con caso base n = 0 */
int total_rec(const unidadMecatronica unidades[], int n) {
    if (n <= 0) {
        return 0;
    }
    return unidades[n - 1]. score + total_rec(unidades, n-1);
}

/* Ordenar: metodo de burbuja (o seleccion/insercion) por score descendente y, en empate, id ascendente */
void ordenar(unidadMecatronica unidades[], int n) {
   int i, j;
   unidadMecatronica temp;
   for (i = 0; i< n - 1; i++) {


