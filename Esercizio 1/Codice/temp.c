#include <stdio.h> // Includo la libreria

int main() {
    double tc, tf, conv, offset; // Dichiaro le variabili
    conv = 5./9.;
    offset = 32.;
    printf("Inserisci la temperatura in gradi Celsius \n"); 
    scanf("%lf", &tc); // Assegno a tc l'input dell'utente
    tf = tc/conv + offset;
    printf("La temperatura in gradi Fahrenheit vale %5.2f gradi\n",tf); // Stampo il risultato
}