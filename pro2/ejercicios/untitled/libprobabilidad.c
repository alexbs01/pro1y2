#include <math.h>
#include "libprobabilidad.h"


static
long long semilla_normal=SEMILLA;

double normal()
{
    int n;
    double f, s, g;

    s=0.0;
    for(n=0; n<NUNIFORMES; n++)
    {
        semilla_normal=(LINEAL_A*semilla_normal+LINEAL_B)
                       % CONGRUENCIA;
        f=(double)semilla_normal/CONGRUENCIA;
        s=s+f;
    }
    g=(s-0.5*NUNIFORMES)/sqrt((1.0/12)*NUNIFORMES);

    return g;
}


static
long long semilla_uniforme=SEMILLA;

double uniforme()
{
    double f;
    semilla_uniforme=(LINEAL_A*semilla_uniforme+LINEAL_B) % CONGRUENCIA;

    f=(double)semilla_uniforme/CONGRUENCIA;

    return f;
}



void histograma(int npts, double x[],
                int nhist, int histo[],
                double x_min, double x_max)
{
    int i, n;

    for(i=0; i<nhist; i++)
    {
        histo[i]=0;
    }

    for(n=0; n<npts; n++)
    {
        i=(int)floor(
                (nhist*(x[n]-x_min))
                /(x_max-x_min) );
        if( 0<=i && i<NHISTOGRAMA )
        {
            histo[i]++;
        }
    }

}