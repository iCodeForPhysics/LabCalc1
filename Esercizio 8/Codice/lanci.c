#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int lancio(int N, int d) { // Dichiaro la funzione per lanciare i dadi
    int ris=0, k=0;
    for(int j=0; j<N; j++) {
        do {
            ris = lrand48()%7; // Genero un numero pseudocasuale tra 0 e 6 con la funzione lrand48
        } while(ris==0);
        if(ris==d) {
            k++; // Segno quante volte esce il valore
        }
    }
    return k;
}

int main() {
    int N, M, k, d, seed=time(0);
    double isto[21] = {0};
    srand48(seed);
    // Prendo in input i valori di N, M e d
    do {
        printf("Inserire il numero di dadi a 6 facce\n");
        scanf("%d", &N);
        while(getchar()!='\n');
    } while(N<=0 || N>20);
    do {
        printf("Inserire il numero totale di lanci da effettuare\n");
        scanf("%d", &M);
        while(getchar()!='\n');
    } while(M<=0 || M>100);
    do {
        printf("Inserire il valore (da 1 a 6) del dado di cui si desidera tenere traccia\n");
        scanf("%d", &d);
        while(getchar()!='\n');
    } while(d<=0 || d>6);
    for(int i=0; i<M; i++) {
        k = lancio(N, d); // Richiamo la funzione lancio M volte per N dadi
        isto[k]+= 1; // Aumento di 1 il valore k-esimo dell'array
    }
    for(int i=0; i<N; i++) {
        isto[i] /= M; // Normalizzo i valori dell'array
        printf("isto = %lf, k = %d\n", isto[i], k);
    }
    FILE* fp = fopen("lanci.dat", "w"); // Puntatore a file
    for(k=0; k<=N; k++){
        fprintf(fp, "%.20lf %d\n", isto[k], k); // Salvo sul file i valori
        printf("%.20lf %d\n", isto[k], k); // Stampo i valori sul terminale (Opzionale)
    }
    fclose(fp); // Chiudo il documento
    return 0;
}