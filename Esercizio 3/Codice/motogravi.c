#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.82

int main() {
    double v0, alp, l, quo, git;
    printf("Questo programma calcola la traiettoria di un moto parabolico\n");
    // Prendo in input i valori di v0, alp e l
    printf("Inserire il valore della velocità iniziale (in metri su secondo): \n");
    scanf("%lf", &v0);
    printf("Inserire il valore dell'angolo Alfa (in radianti): \n");
    scanf("%lf", &alp);
    printf("Sono state inseriti come dati iniziali una velocità iniziale di %lfm/s^2\ne un angolo di %lfrad\n", v0, alp);
    printf("Inserire la distanza (in metri) per la quale si vuole calcolare l'altezza del corpo\n");
    scanf("%lf", &l);
    // Calcolo la quo(ta) e la git(tata) 
    quo = ((l * tan(alp)) - ((g * pow(l, 2)) / (2 * pow(v0, 2) * pow(cos(alp), 2))));  
    git = ((2 * pow(v0, 2) * sin(alp) * cos(alp)) / g);
    // Stampo i risultati
    printf("Alla distanza %lf il corpo avrà una quota di %lfm\n", l, quo);
    printf("La gittata massima invece è di %lfm\n", git);
    printf("\n\n\n\n"); // Creo spazio tra la prima e la seconda parte
    printf("Parte 2\n");
    // Dichiaro un v0 fisso (v0t)
    float v0t = 10;
    // Prendo in input il valore di alfa
    printf("Inserire alfa (in radianti): \n");
    scanf("%lf", &alp);
    // Calcolo la git(tata)
    git = ((2 * pow(v0t, 2) * sin(alp) * cos(alp)) / g);
    // Stampo i risultati seguendo il formato richiesto (prima alp, poi git e a capo)
    printf("%lf %lf\n", alp, git);
}