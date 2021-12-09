#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int i, n, z, j;
    double xl, xr, xmin = -100.0, xmax = 100.0, dx, fx; // Il codice non cambia per x nell'intervallo [-15, 15]
    xr=xmin;
    // Prendo in input il valore di n (massimo intervalli)
    printf("Inserire il numero massimo di intervalli: ");
    scanf("%d", &n);
    printf("Intervallo  Zeri\n");
    // Creo due cicli for nidificati per determinare il numero di zeri per ogni sottointervallo di [1, n]
    for(j=1; j<=n; j++) {
        z=0; // Inizializzo a zero il numero di zeri
        dx = (xmax - xmin) / (j); // Aggiorno l'incremento
        for(i=1; i<=j; i++) { // Ciclo for interno che conta gli zeri (Codice commentato nell'esercizio 4)
            xl = xr;
            xr = xmin+dx*i;
            if(xl==0) {
                fx = sin(xr)/xr;
                if(fx<=0) {
                    z++;
                }
            } else if(xr==0) {
                fx = sin(xl)/xl;
                if(fx<=0) {
                    z++;
                }
            } else {
                fx = (sin(xr)/xr) * (sin(xl)/xl);
                if(fx<=0) {
                    z++;
                }
            }
        }
        printf("%4.1d      %4.1d\n", j, z); // Stampo il valore del sottointervallo e degli zeri corrispondenti 
    }
}