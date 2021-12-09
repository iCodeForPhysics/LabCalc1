#include <stdio.h>
#include <math.h>

/* Dati: R=6.2m, ω=0.1rad/s */
int main () {
    float R, vAng;
    R = 6.2;
    vAng = 0.1;
    // Stampo su schermo i risultati per 4 tempi diversi
    printf("%d %1.5f %1.5f %1.5f %1.5f\n", 0.0, R*cos(vAng*0.0), R*sin(vAng*0.0), -vAng*R*sin(vAng*0.0), vAng*R*cos(vAng*0.0));
    printf("%d %1.5f %1.5f %1.5f %1.5f\n", 0.5, R*cos(vAng*0.5), R*sin(vAng*0.5), -vAng*R*sin(vAng*0.5), vAng*R*cos(vAng*0.5));
    printf("%d %1.5f %1.5f %1.5f %1.5f\n", 10, R*cos(vAng*10), R*sin(vAng*10), -vAng*R*sin(vAng*10), vAng*R*cos(vAng*10));
    printf("%d %1.5f %1.5f %1.5f %1.5f\n", 20, R*cos(vAng*20), R*sin(vAng*20), -vAng*R*sin(vAng*20), vAng*R*cos(vAng*20));
}
