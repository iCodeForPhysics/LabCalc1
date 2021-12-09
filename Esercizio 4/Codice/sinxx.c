#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int i = 0, np = 65;
    double x, xmin = -5.0, xmax = 5.0, dx, fx;
    dx = (xmax - xmin) / (np-1); // Inizializzo l'incremento
    while(i<np) {
        x = xmin + dx*i; // Calcolo x dopo ogni incremento
        i++; // Incremento i di 1 ad ogni iterazione
    }
    // Parte 2
    int j = 0, np1 = 129;
    x = 0;
    dx = (xmax - xmin) / (np1-1); // Inizializzo l'incremento per il nuovo valore di np
    while(j<np) {
        x = xmin + dx*i; // Calcolo x dopo ogni incremento
        if(x==0) { // Se x = 0 -> f(x) = 1 (limite noto = 1)
            fx = 1;
            printf("%lf %lf\n", x, fx); // Stampo i valori di x e f(x) (in questo caso 0 e 1) 
        } else {
            fx = sin(x) / x;
            printf("%lf %lf\n", x, fx); // Stampo i valori di x e f(x)
        }
        j++; // Incremento j di 1 ad ogni iterazione
    }
}