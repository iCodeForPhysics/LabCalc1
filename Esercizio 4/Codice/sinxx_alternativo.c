#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
    int i, np = 1000;
    double x, xmin = -100.0, xmax = 100.0, dx, fx;
    dx = (xmax - xmin) / (np-1);
    for(i=0; i<np; i++){
        x = xmin + dx*i;
        if(x==0) {
            fx = 1;
            printf("%lf %lf\n", x, fx);
        } else {
            fx = sin(x) / x;
            printf("%lf %lf\n", x, fx);
        }
    }
}