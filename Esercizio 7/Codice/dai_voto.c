#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int i, j, x, comm[10];
    double media[10][4], y, dati[10][8];
    FILE* fpr = fopen("anno.dat", "r"); // Puntatore a file e apro il file in r(eading)
    if(fpr==NULL) { // Controllo se ci sono errori
        printf("ERRORE: Apertura del File non riuscito. Chiusura del programma\n");
        exit(1); // Esco dal programma
    }
    for(i=0; i<10; i++) { // Ciclo for per prendere i dati dal file
        fscanf(fpr, "%d %lf %lf %lf %lf %lf %lf %lf %lf", &(comm[i]), &(dati[i][0]), &(dati[i][1]), &(dati[i][2]), &(dati[i][3]), &(dati[i][4]), &(dati[i][5]), &(dati[i][6]), &(dati[i][7]));
    }
    for(int k=0; k<4; k++) { // Ciclo for per cambiare semestre
        for(i=0; i<10; i++) { // Ciclo for per calcolare la media del semestre attuale
            media[i][k] = dati[i][2*k] / dati[i][2*k+1];
        }
        for(i=0; i<10; i++){ // Ciclo for nidificato per riordinare i dati (BubbleSort)
            for(j=9; j>=0; j--) {
                if(media[j-1][k]<media[j][k]) {
                    y = media[j-1][k];
                    media[j-1][k] = media[j][k];
                    media[j][k] = y;
                    // Oltre alla media ordino anche gli altri dati
                    y = dati[j-1][2*k];
                    dati[j-1][2*k] = dati[j][2*k];
                    dati[j][2*k] = y;
                    y = dati[j-1][2*k+1];
                    dati[j-1][2*k+1] = dati[j][2*k+1];
                    dati[j][2*k+1] = y;
                    x = comm[j-1];
                    comm[j-1] = comm[j];
                    comm[j] = x;
                }
            }
        }
        // Stampo i dati in ordine
        printf("//////////////////////Trimestre n°%d///////////////////////\n", k+1);
        printf("#Commesso   #Ore   #Vendite   #Media       #Voto\n");
        for(i=0; i<10; i++) {
            printf("#%2d         #%2.fh   #%3.f€      #%2.3lf€/h   #%2dpti\n", comm[i], dati[i][2*k], dati[i][2*k+1], media[i][k], 10-i); 
            comm[i] = i + 1; // Resetto la posizione dei dipendenti nell'array         
        } 
    }
    fclose(fpr); // Chiudo il file
    return 0;
}