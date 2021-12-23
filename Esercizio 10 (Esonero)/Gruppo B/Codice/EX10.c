#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void immettiM(int *a) {
    do { // Prendo in input il valore di M (utilizzo un puntatore a intero)
        printf("Inserire il valore di M: ");
        scanf("%d", a);
        while(getchar()!='\n');
        if(*a == 0) {
            break;
        } else if(*a<12 || *a>23) {
            printf("Inserire un valore tra 12 e 23\n");
        }
    } while(*a<12 || *a>23);
}

void immettiNumero(double *pd) {
    do { // Prendo in input il numero da convertire (utilizzo un puntatore a double)
        printf("Inserire un numero tra 1.0 e 1.9\n");
        scanf("%lf", pd);
        while(getchar()!='\n');
        if(*pd < 1. || *pd > 1.9) {
            printf("Il numero inserito non è compreso tra 1.0 e 1.9\n");
        }
    } while(*pd < 1. || *pd > 1.9);
}

void convertiNumero(double n, int numc[], int M) { // Converto il numero seguendo l'algoritmo del PDF
    n--;
    for(int i=M-1; i>=0; i--) {
        n*=2;
        if((int)n==0) {
            numc[i] = 0;
        } else if((int)n==1) {
            numc[i] = 1;
            n--;
        }
    }
    if(n>=0.5) {
        for(int i=0; i<M; i++) {
            if(numc[i] == 0) {
                numc[i] = 1;
                break;
            } else {
                numc[i] = 0;
            }
        }
    }
}

void generaNumero(double *num) { // Genero un numero casuale nell'intervallo [1.0, 1.9)
    do {
        *num = 1 + drand48();
    } while(*num <= 2 && *num >= 1.9);
}

// Extra //
void stampaNumero(int numfp[], int M) { // Stampo il valore convertito (Utile per controllare con il PDF)
    printf("Il numero convertito (di mantissa %d) è: ", M);
        for(int i=M-1; i>=0; i--) {
            printf("%d", numfp[i]);
        }
        printf("\n");
}
// Fine Extra //

void salvaFile(int numfp[], int M) {
    FILE* fp = fopen("numfpsum.dat", "w"); // Puntatore a file in modalità writing
    if(fp==NULL) { // Controllo possibili errori durante l'apertura del file
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    double fn = 0;
    int temp = 0;
    for(int i=0; i<M; i++) {
        temp += numfp[i];
        fn = fprintf(fp, "%d %d\n", i, temp); // Stampo su file
        if(fn<=0) { // Controllo possibili errori per la stampa su file
            printf("Errore nella stampa sul file\n");
            exit(1);
        }
    }
}

int main() {
    int numfp[23], M, *pM = &M, seed = time(0);
    srand48(seed); // Inizializzo l'srand48
    double num, *pnum = &num;
    immettiM(pM);
    if(M==0) {
        M = 23;
        generaNumero(pnum);
        convertiNumero(num, numfp, M);
        stampaNumero(numfp, M);
        salvaFile(numfp, M);
    } else {
        immettiNumero(pnum);
        convertiNumero(num, numfp, M);
        stampaNumero(numfp, M);
    }
    return 0;
}