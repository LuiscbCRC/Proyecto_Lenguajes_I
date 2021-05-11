#include"pokergame.h"

double getProbability(int qty, int tries){
    double value = 0;
    value = (double) qty/(double) tries * 100;
    return value;
}

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
       // suma+= pow(probabilidades[i]-media,2.0);
    }
    
    return suma/size;
}