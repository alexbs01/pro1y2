#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libprobabilidad.h"

void calculo1(double a, double u[101], double x1[101], double xi1[101]);

const double h = 0.001;
const double b=1;
const double e=2.71828;

int main(){
    int i;
    double u[101], x1[101], xi1[101], tp[101];

    FILE *f;

    for(i=0; i <= 100; i++){
        u[i] = normal();
    }

    f = fopen("Datos_Pec_Ej1.dat","w");

    if (f == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }

    calculo1(0.1, u, x1, xi1);

    for(i=0; i <= 100; i++){
        tp[i] = 100*i*h;
    }

    for(i=0; i <= 100; i++){
        fprintf(f,"%lf %lf \n",xi1[i],tp[i]);
    }
}

void calculo1(double a, double u[101], double x1[101], double xi1[101]){
    x1[0]=1;
    xi1[0]=1;
    double sumador=0;

    for(int i = 1; i <= 100; i++){
        x1[i] = x1[i-1]*(1+a*h+b*(u[i])*sqrt(h));

        for(int n=1; n <= 10; n++){
            sumador = sumador + pow(x1[i],n);
        }

        xi1[i] = (sumador*0.1);
        sumador = 0;
    }
}