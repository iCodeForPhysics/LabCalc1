#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define g 9.82

int main() {
    // Svuoto il contenuto del file "motogravi.dat"
    FILE* f = fopen("motogravi.dat", "w"); // Chiamo un puntatore a FILE e apro il documento in modalità "w(riting)"
    fprintf(f, ""); // Stampo sul file una stringa vuota che sovrascrive il vecchio contenuto
    fclose(f); // Chiudo il documento
    double v0, alp, l, quo, git;
    printf("Questo programma calcola la traiettoria di un moto parabolico\n");
    // Prendo in input i valori di v0, alp e l
    printf("Inserire il valore della velocità iniziale (in metri su secondo): \n");
    scanf("%lf", &v0);
    printf("Inserire il valore dell'angolo Alfa (in gradi): \n");
    scanf("%lf", &alp);
    printf("Sono state inseriti come dati iniziali una velocità iniziale di %lfm/s^2\ne un angolo di %lf°\n", v0, alp);
    alp = alp * (M_PI / 180); // Converto alp da gradi in radianti secondo la formula (° * (Pi/180))
    printf("\n\n%lf\n\n", alp); // Stampo il contenuto di alp convertito per controllare la conversione manualmente
    printf("Inserire la distanza (in metri) per la quale si vuole calcolare l'altezza del corpo\n");
    scanf("%lf", &l);
    // Calcolo il valore della quo(ta) e della git(tata)
    quo = ((l * tan(alp)) - ((g * pow(l, 2)) / (2 * pow(v0, 2) * pow(cos(alp), 2))));
    git = ((2 * pow(v0, 2) * sin(alp) * cos(alp)) / g);
    // Stampo i risultati
    printf("Alla distanza %lf il corpo avrà una quota di %lfm\n", l, quo);
    printf("La gittata massima invece è di %lfm\n", git);
    printf("\n\n\n\n"); // Separo dalla seconda parte del programma
    printf("Parte 2");
    float x1 = 5, x2 = 6, h = 2.05, alp2 = .7, v0d = 10, quo2; // Dichiaro e inizializzo le variabili dell'esercizio
    // Creo un ciclo for per controllare in maniera precisa quando il proiettile colpisce il muro
    for (float i=x1; i<=x2; i+=.01){
        quo2 = ((i * tan(alp2)) - ((g * pow(i, 2)) / (2 * pow(v0d, 2) * pow(cos(alp2), 2))));
        if (quo2<=h) { // Controllo se la quota raggiunta è minore o uguale all'altezza del muro
            printf("Il corpo colpisce il muro a %.2fm\n", i);
            break; // Esco dal ciclo for
        }
        printf("Il corpo non colpisce l'asta nel punto x1 a %.2fm\n", i);
    }
    printf("\n\n\n\n"); // Separo dalla terza parte del programma
    printf("Parte 3");
    float v0t = 10, git2;
    double alp3[10];
    printf("Inserire 10 valori di alfa (in gradi) differenti: \n");
    // Creo un ciclo for per convertire tutti i valori di alfa inseriti
    for (int j=0; j<10; j++){
        scanf("%lf", &alp3[j]);
        alp3[j] = alp3[j] * (M_PI / 180);
    }
    // Creo un ciclo for per calcolare la gittata per ogni valore di alp, stampare il risultato e salvare i risultati sul file
    for (int j=0; j<10; j++){
        git2 = ((2 * pow(v0t, 2) * sin(alp3[j]) * cos(alp3[j])) / g);
        printf("Per alfa di valore %lfrad la gittata massima è di %fm\n", alp3[j], git2);
        FILE* f = fopen("motogravi.dat", "a"); // Chiamo un puntatore a FILE e apro il documento in modalità "a(ppend))"
        fprintf(f, "%lf %f\n", alp3[j], git2); // Stampo sul file il valore di alp e git
        fclose(f);
    }
    system("python3 motogravi.py &"); // Uso la funzione system() per eseguire automaticamente il grafico in python
}