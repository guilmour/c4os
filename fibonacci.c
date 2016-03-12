
#include <stdio.h>


void Fibonacci(){

    int a, b, auxiliar, i, n;

    a = 0;
    b = 1;

    printf("*******************  serie fibonacci.exe      ***************");
    printf("\n\nDigite um numero: ");

    scanf("%d", &n);
    printf("Os %d primeiros numeros da serie Fibonacci sao:\n");
    printf("%d\n", b);


    for(i = 0; i < n; i++){
        auxiliar = a + b;
        a = b;
        b = auxiliar;
        printf("%d  ", auxiliar);
        _sleep(40);
    }

    EsperaENTER();
}
