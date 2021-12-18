#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int getN() {
    int n;
    do { // Prendo in input il numero massimo di estrazioni
        printf("Inserire il numero massimo di estrazioni da fare: ");
        scanf("%d", &n);
        if(n<500 || n>35000) {
            printf("Inserire un valore compreso tra 500 e 35000\n");
        }
    } while(n<500 || n>35000);
    return n;
}

double computeArea(int nmax) {
    double x[35000], y[35000], area, a=0;
    for(int j=0; j<nmax; j++) { // Genero x e y casuali e controllo che siano fuori dai 4 cerchi
        x[j] = 4 * drand48();
        y[j] = 4 * drand48();
        if(pow((x[j]-1),2) + pow((y[j]-1), 2) > 1 && pow((x[j]-3),2) + pow((y[j]-1), 2) > 1 && pow((x[j]-1),2) + pow((y[j]-3), 2) > 1 && pow((x[j]-3),2) + pow((y[j]-3), 2) > 1) {
            a++;
        }
    }
    area = 16 * a / (double)nmax; // Calcolo l'area con il metodo Montecarlo
    return area;
}

void writeArray(double a[30]) {
    FILE *fp = fopen("area.dat", "w"); // Puntatore a File
    if(fp == NULL) { // Controllo l'apertura del File
        printf("Errore nell'apertura del file\n");
        exit(0);
    }
    for(int i=0; i<30; i++) {
        fprintf(fp, "%lf\n", a[i]); // Stampo il valore di a nel File
    }
    fclose(fp); // Chiudo il File
}

int main() {
    int nmax, seed = time(0), i = 0, n = 100;
    double a[30] = {0};
    srand48(seed); // Inizializzo la funzione srand
    printf("Questo programma calcola l'area di un quadrato di lato 4m a cui viene rimossa l'area di 4 cerchi di raggio 1m\n");
    nmax = getN();
    do {
        a[i] = computeArea(n);
        i++;
        n *= 2;
    } while(n<nmax); 
    writeArray(a);
}

