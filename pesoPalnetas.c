#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void pesoPlanetas(){
    float m=0;
    float g=0, peso=0;

    printf("************    Calcular seu peso em outros planetas! *********\n\n\n");
    printf("Insira seu peso na Terra em Kg: ");
    scanf("%f", &peso);

    //printf("Sua massa na Terra eh: %.0fkg", (peso/9.78));
    m = peso/9.78;
    printf("Seu peso no ou na...\n");
    printf("\nSOL seria: \t\t%.0fkg", (m*279));
    printf("\nLUA seria: \t\t%.0fkg", (m*1.6));
    printf("\nMERCURIO seria: \t%.0fkg", (m*3.7));
    printf("\nVENUS seria: \t\t%.0fkg", (m*8.8));
    printf("\nMARTE seria: \t\t%.0fkg", (m*3.8));
    printf("\nJUPITER seria: \t\t%.0fkg", (m*26.4));
    printf("\nSATURNO seria: \t\t%.0fkg", (m*11.5));
    printf("\nURANO seria: \t\t%.0fkg", (m*9.3));
    printf("\nNETUNO seria: \t\t%.0fkg", (m*12.2));
    printf("\nPLUTAO seria: \t\t%.0fkg", (m*0.6));

    EsperaENTER();





}
