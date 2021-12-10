#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, j, x, comm[10];
    double media[10], y, dati[10][2]; 
    FILE* fpr = fopen("trimestre1.dat", "r"); // Puntatore a file e apro il file in r(eading)
    if(fpr==NULL) { // Controllo se ci sono errori
        printf("ERRORE: Apertura del File non riuscito. Chiusura del programma\n");
        exit(1); // Esco dal programma
    }
    for(i=0; i<10; i++) { // Ciclo for per prendere i dati dal file
        fscanf(fpr, "%d %lf %lf", &(comm[i]), &(dati[i][0]), &(dati[i][1]));
        media[i] = dati[i][0] / dati[i][1];
    }
    for(i=0; i<10; i++) { // Ciclo for nidificato per riordinare i dati (BubbleSort)
        for(j=9; j>i; j--) {
            if (media[j-1] < media[j]){
                y = media[j-1];
                media[j-1] = media[j];
                media[j] = y;
                // Oltre alla media ordino anche gli altri dati
                x = dati[j-1][0];
                dati[j-1][0] = dati[j][0];
                dati[j][0] = x;
                x = dati[j-1][1];
                dati[j-1][1] = dati[j][1];
                dati[j][1] = x;
                x = comm[j-1];
                comm[j-1] = comm[j];
                comm[j] = x;
            }
        }
    }
    fclose(fpr); // Chiudo il file
    printf("#Commesso   #Ore   #Vendite   #Media       #Voto\n"); 
    // Stampo i dati in ordine
    for(i=0; i<10; i++) {
        printf("#%2d         #%2.fh   #%3.f€      #%2.3lf€/h   #%2dpti\n", comm[i], dati[i][1], dati[i][0], media[i], 10-i);
    } 
    return 0;
}