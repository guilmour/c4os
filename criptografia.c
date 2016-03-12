//guilmour
//exercio da lista 09 da Leyza
/*2. (*) Faca um programa em C que receba uma frase e troque as vogais existentes nesta frase por um asterisco (*). Por exemplo: Frase \EU ESTOU NA ESCOLA"
resultado na tela ** *ST** N* *SC*L* */

#include <stdio.h>

void Criptografia(){

    char frase[100];
    int k, i;
    printf("*************** criptografia ***************\n");
    printf("\nDigite uma frase para ser condificada: \n\n");
    fgets(frase, 100, stdin);

    //printf("%s", frase);

    for(i=0; i<strlen(frase); i++){
        if(frase[i]== 'a' || frase[i]== 'e' || frase[i]== 'i' || frase[i]== 'o' || frase[i]== 'u'){
            frase[i]= '*';

        }

        else if(frase[i]== 'A' || frase[i]== 'E' || frase[i]== 'I' || frase[i]== 'O' || frase[i]== 'U'){

            frase[i]= '*';

        }


    }

    printf("%s", frase);
    EsperaENTER();
    C4OS_Kevin();
}


