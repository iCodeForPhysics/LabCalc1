#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int i, np = 33, n = np-1, z=0;
    double xl, xr; // Dichiaro le variabili per i valori di x destro e sinistro
    double xmin = -15.0, xmax = 15.0, dx, fx;
    dx = (xmax - xmin) / (n-1);
    xr = xmin; // Assegno a x sinistro il valore più piccolo
    for(i=1; i<n; i++){ // Utilizzo un ciclo for che va da 1 a n-1
        xl = xr; // Assegno a x destro il valore di x sinistro
        xr = xmin+dx*i; // Aggiorno il valore di x sinistro per essere più grande di x destro di un certo incremento dx*i
        // Implemento i casi x destro o sinistro uguali a 0 
        if(xl==0){
            fx = sin(xr)/xr;
            if(fx<=0) {
                z++; // Incremento di 1 il numero di 0
            }
        } else if (xr==0){
            fx = sin(xl)/xl;
            if(fx<=0) {
                z++; // Incremento di 1 il numero di 0
            }
        } else {
            fx = (sin(xr)/xr) * (sin(xl)/xl);
            if(fx<=0) {
                z++; // Incremento di 1 il numero di 0
            }
        }
    }
    printf("Ci sono %d zeri\n", z); // Stampo il numero di 0
}