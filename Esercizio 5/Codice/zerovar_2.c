#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int i, n, z, j, b = 0, o;
    double xl, xr, xmin = -100.0, xmax = 100.0, dx, fx; // Il codice non cambia per x nell'intervallo [-15, 15]
    xr=xmin;
    // Prendo in input il valore di n (massimo intervalli)
    printf("Inserire il numero massimo di intervalli: ");
    scanf("%d", &n);
    while(getchar()!='\n'); // Svuoto il buffer
    // Prendo nuovamente in input il valore di n
    printf("Inserire nuovamente il numero massimo di intervalli: ");
    while(!b){ // Ciclo while per richiedere l'input in caso di valori non validi
        o = scanf("%d", &n); // o simula un boolean (Se n inserito è un intero o diventa 1 (True), se non è un'intero diventa 0(False))
        while(getchar()!='\n'); // Svuoto il buffer
        if(o==1 && n>=1) {
            b=1;
        } else {
            printf("Inserire un valore valido\n");
        }
    }
    /* Il codice per l'inserimento di n può essere riscritto così
    printf("Inserire il numero massimo di intervalli: ");
    n=0;
    do {
        scanf("%d", &n);
        while(getchar()!='\n');
        if(n<=0) {
            printf("Inserire un valore valido\n");
        }
    } while(n<=0);
    */
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