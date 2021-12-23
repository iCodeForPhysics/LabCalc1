#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void immettiM(int *b) {
    do { // Prendo in input il valore di M (utilizzo un puntatore a intero)
        printf("Inserire il valore di M: ");
        scanf("%d", b);
        while(getchar()!='\n');
        if(*b == 0) {
            break;
        } else if(*b<4 || *b>20) {
            printf("Inserire un valore tra 4 e 20\n");
        }
    } while(*b<4 || *b>20);
}

void immettiNumero(char *pnum) {
    printf("Inserire il numero binario positivo\n"); 
    scanf("%s", pnum); // Prendo in input il numero in binario (utilizzo un puntatore a carattere)
}

void convertiStringa(char str[], int bin[], int M) {
    int count=0;
    for(int j=0; j<20; j++) { // Conto quante cifre sono state inserite dall'utente grazie ad un contatore
        if((int)str[j] == '\0') { // Ogni array termina sempre con '\0'
            break;
        }
        count++;
    }
    if(count!=M) {
        printf("Il numero inserito non è di %d cifre (%d)\n", M, count);
        exit(1);
    }
    for(int i=0; i<M; i++) { // Controllo se il numero è composto esclusivamente da 0 e 1 e riempio l'array di int
        if((int)str[M-1-i] != '0' && (int)str[M-1-i] != '1') {
            printf("Il numero inserito non è in forma binaria\n");
            exit(1);
        } else if((int)str[M-1-i] == '0') {
            bin[i] = 0;
        } else if((int)str[M-1-i] == '1') {
            bin[i] = 1;
        }
    }
}

void calccompl2(int bin[], int compl2[], int M) { // Calcolo il complemento a 2
    for(int i=0; i<M; i++) { // Inverto tutti i valori
        if(bin[M-1-i] == 0) {
            compl2[M-1-i] = 1;
        } else {
            compl2[M-1-i] = 0;
        }
    }
    for(int j=0; j<M; j++) { // Aggiungo 1 a partire dalla cifra meno significativa
        if(compl2[j] == 0) {
            compl2[j] = 1;
            break;
        } else {
            compl2[j] = 0;
        }
    }
}

void stampanumero(char testo[], int *pnum, int M) { // Stampo su schermo il testo preso dal main
    int i = 0;
    do {
        printf("%c", testo[i]);
        i++;
    } while(testo[i]!='\0');
    for(int j=M-1; j>=0; j--) {
        printf("%d", *(pnum + j));
    }
    printf("\n");
}

void generaNumero(int num[]) { // Genero il numero casuale
    for(int i=0; i<20; i++) {
        num[i] = lrand48()%2; // lrand48()%2 da come valori solo 0 e 1 
    }
}

void salvaFile(int num[], int M) { 
    FILE* fp = fopen("compl2.dat", "w"); // Puntatore a file in modalità writing
    if(fp==NULL) { // Controllo possibili errori durante l'apertura del file
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    double fn = 0;
    for(int i=0; i<M; i++) {
        fn = fprintf(fp, "%d %d\n", i, num[i]); // Stampo su file
        if(fn<=0) { // Controllo possibili errori per la stampa su file
            printf("Errore nella stampa sul file\n");
            exit(1);
        }
    }
}

int main() {
    int numbin[20] = {0}, numcompl2[20] = {0}, M, *pM = &M, seed=time(0);
    srand48(seed); // Inizializzo l'srand48
    char numstr[20], *pnumstr = numstr;
    numstr[0] = '\0'; // Svuoto la stringa
    immettiM(pM);
    if(M == 0) {
        M = 20;
        generaNumero(numbin);
        calccompl2(numbin, numcompl2, M);
        char testo1[] = "Il numero in binario è: ", testo2[] = "Il numero in complemento a 2 è: ";
        int *pcom2 = &numcompl2[0], *pbin = &numbin[0];
        stampanumero(testo1, pbin, M);
        stampanumero(testo2, pcom2, M);
        salvaFile(numcompl2, M);
    } else {
        immettiNumero(pnumstr);
        convertiStringa(numstr, numbin, M);
        calccompl2(numbin, numcompl2, M);
        char testo1[] = "Il numero in binario è: ", testo2[] = "Il numero in complemento a 2 è: ";
        int *pcom2 = &numcompl2[0], *pbin = &numbin[0];
        stampanumero(testo1, pbin, M);
        stampanumero(testo2, pcom2, M);
    }
    return 0;
}