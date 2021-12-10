#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long int fattoriale(int N) { // Dichiaro la funzione fattoriale di tipo %Lu
    unsigned long int n = 1, i;
    for(i=1; i<=N; i++) {
        n *= i;
    }
    return n;
}

double binomiale(double p, int N, unsigned long int k) { // Dichiaro la funzione per il calcolo della distribuzione di Bernoulli
    double bern;
    unsigned long int fN, fk, fNk;
    fN = fattoriale(N);
    fk = fattoriale(k);
    fNk = fattoriale(N-k);
    bern = (fN/(fk*fNk))*(pow(p, k)*pow(1-p, N-k));
    return bern;
}

int main() {
    int N;
    double p;
    // Prendo in input i valori di N e p
    do {
        printf("Inserire il numero totale di eventi\n");
        scanf("%d", &N);
        while(getchar()!='\n');
    } while(N<=0 || N>20);
    do {
        printf("Inserire la probabilità del singolo evento\n");
        scanf("%lf", &p);
        while(getchar()!='\n');
    } while(p<=0);
    unsigned long int k;
    double bernoulli, a;
    char fn[17];
    FILE* fp; // Puntatore a file
    sprintf(fn,"bernoulli_%i.dat", N); // Assegno a fn la stringa corrispondente al file (che dipende da N)
    fp=fopen(fn,"w"); // Apro il file in w(riting)
    for(k=0; k<=N; k++) {
        bernoulli = binomiale(p, N, k); // Richiamo la funzione "binomiale" con i valori di p, N e k inseriti
        fprintf(fp, "%lu %.20lf\n", k, bernoulli); // Stampo il risultato sul file
        printf("Bernoulli = %.20lf, k = %lu\n", bernoulli, k); // Stampo sul terminale i risultati (Facoltativo)
    }
    fclose(fp); // Chiudo il documento
    return 0;
}