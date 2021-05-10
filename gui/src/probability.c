#include "pokergame.h"

double mediaEmpirica(double probabilidades[], int size){
    double suma=0;

    for (int i = 0; i < size; i++)
    {
        suma+=probabilidades[i];
    }
    
    return suma/size;
    
}

//Variancia POBLACIONAL
double varianciaEmpirica(double probabilidades[], int size, double media){
    double suma=0;

    for (int i = 0; i < size; i++)
    {
        suma+= pow(probabilidades[i]-media,2.0);
    }
    
    return suma/size;
}