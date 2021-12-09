#include <stdio.h> 
#include <math.h>

int main(void) {
    printf("Benvenuto! Questo è un programma dimostrativo delle funzioni matematiche in C.\n");
    printf("8 + 7 = %d\n", 8+7); // %d indica che si vuole stampare un intero printf("3.2 + 8.4 = %f\n", 3.2+8.4); // %f indica un numero floating point in doppia precisione
    printf("2^2+4^2 = %f\n", pow(2, 2) + pow(4, 2));
    printf("sqrt(36) = %f\n", sqrt(36));
    printf("cos(pi/6) = %f\n", cos(M_PI/6.0)); printf("sin(pi/6)=%f\n", sin(M_PI/6));
    printf("sinh(0) = %f tanh(1)=%f\n", sinh(0.0),tanh(1.0));
    printf("cos(pi/6) + 10 = %f cos(pi/6) + 10 = %f\n", cos(M_PI/6) + 10., cos(M_PI/6) + 10.);
    printf("cos(pi/6)*10^4 = %f cos(pi/6)/10^2 = %f\n", cos(M_PI/6)*10000, cos(M_PI /6.0)/100);
    printf("%f %f %f\n", 0.5, 6.2*cos(0.1*0.5), 6.2*sin(0.1*0.5));//R*cos(w*t) con R=6.2,w=0.1,t=0.5
}
