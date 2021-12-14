#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double inserimento() {
    double in=-1;
    // Prendo in input il valore di Np (Escludo i valori negativi e le lettere)
    do {
        printf("Inserire il numero di punti da generare per stimare l'area (Si sconsigliano valori troppo grandi): \n");
        scanf("%lf", &in);
        while(getchar()!='\n'); // Svuoto il buffer
        if(in<0) {
            printf("Inserire un valore valido\n");
        }
    } while(in<0);
    return in;
}

double genera_coordinata(long int Np) {
    double x;
    x = -4 * drand48() + 2; // Genero un numero casuale nell'intervallo [-2, 2]
    return x;
}

int main() {
    printf("Questo programma calcola con il metodo Monte Carlo l'area della superficie generata dall'intersezione delle superfici\ndi due ellissi perpendicolari tra loro\n\n");
    long int seed=time(0);
    double Np = -1, coord[2], A, Nh = 0, Aan, prc;
    srand48(seed); // Inizializzo la funzione rand
    Np = inserimento();
    FILE *fp = fopen("punti.dat", "w"); // Dichiaro un puntatore a FILE in modalità w(riting)
    if(fp==NULL) { // Controllo che il FILE sia stato aperto 
        printf("Errore nell'apertura del file\n");
        exit(0);
    }
    for(int i=0; i<Np; i++) {
        coord[0] = genera_coordinata(Np);
        coord[1] = genera_coordinata(Np);
        if((pow(coord[0], 2)/4 + pow(coord[1], 2)) < 1 && (pow(coord[0], 2) + pow(coord[1], 2)/4) < 1) {
            prc = fprintf(fp, "%lf %lf\n", coord[0], coord[1]); // Salvo i valori sul FILE
            if(prc<=0) { // Controllo che avvenga la scrittura su FILE
                printf("Errore nella scrittura sul file\n");
                exit(0);
            }
            Nh++;
        }
    }
    fclose(fp); // Chiudo il FILE
    Aan = 4 * asin(4./5.); // Calcolo il valore dell'Area secondo la formula
    A = (16 * Nh) / Np; // Calcolo il valore stimato dell'Area
    printf("La stima dell'area per Np = %.lf è A = %.2lf\n", Np, A); // Stampo il valore stimato dell'Area
    printf("Il valore analitico dell'area è A = %.2lf\n", Aan); // Stampo il valore dell'Area 
    return 0;
}