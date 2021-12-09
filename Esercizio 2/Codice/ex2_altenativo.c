#include <stdio.h>
#include <math.h>

/* Dati: R=6.2m, ω=0.1rad/s */
int main () {
    float R, vAng;
    R = 6.2;
    vAng = 0.1;
    int tempo;
    for (tempo=0; tempo<1000; tempo++){ // Stampa il valore per ogni tempo da 1 a 100 (il corpo svolge un giro completo ogni 63 secondi circa)
        printf("%d %1.5f %1.5f %1.5f %1.5f\n", tempo, R*cos(vAng*tempo), R*sin(vAng*tempo), -vAng*R*sin(vAng*tempo), vAng*R*cos(vAng*tempo));
    }
}
