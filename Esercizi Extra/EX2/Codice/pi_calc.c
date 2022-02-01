#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void prendiN(int *N);
void generaP(double punti[][2], int N);
double calcolo(double pInterni, double punti[][2], int N);

int main() {
    int seed = time(0), N = 0, *pN = &N;
    double punti[100000][2] = {.0}, pInterni = .0, PI = .0;
    srand48(seed);
    printf("Questo programma calcola il valore di PI generando numeri casuali tra 0 e 1\n");
    prendiN(pN);
    generaP(punti, N);
    PI = calcolo(pInterni, punti, N);
    printf("PI = %lf\n", PI);
}

void prendiN(int *N) {
    printf("Inserire il numero di punti da generare\n");
    do {
        printf("Punti: ");
        scanf("%d", N);
        if(*N < 1000 || *N > 100000) {
            printf("Inserire un valore compreso tra 1000 e 100000\n");
        }
    } while(*N < 1000 || *N > 100000);
}

void generaP(double punti[][2], int N) {
    for(int i=0; i<N; i++) {
        punti[i][0] = drand48();
        punti[i][1] = drand48();
    }
}
double calcolo(double pInterni, double punti[][2], int N) {
    double PI_calcolato = .0;
    FILE *fp = fopen("pi_calcolo.dat", "w");
    for(int i=0; i<N; i++) {
        if((pow(punti[i][0], 2)+pow(punti[i][1], 2)) <= 1) {
            pInterni++;
            fprintf(fp, "%lf %lf\n", punti[i][0], punti[i][1]);
        }
    }
    fclose(fp);
    PI_calcolato = 4 * pInterni / N;
    return PI_calcolato;
}