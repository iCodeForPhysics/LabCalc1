#include <stdio.h>

int main() {
    double tc, tf, conv, offset;
    conv = 5./9.;
    offset = 32.;
    printf("Inserisci la temperatura in gradi Celsius \n"); 
    scanf("%lf", &tc);
    tf = tc/conv + offset;
    printf("La temperatura in gradi Fahrenheit vale %5.2f gradi\n",tf);
}