#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int AdvinhaGame() {
  int num, x;
  int tent = 1;
  char s = 't';
  srand(time(NULL));
  x = rand() % 100 + 1;
  printf("************************   \aadivinha.exe   *****************************");
  printf("\n\n                   Estou pensando em um numero de 1 a 100");
  printf("\n                                  Advinhe!");

  do {
  printf("\nDigite um numero: ");
  scanf("%d", &num);

    if (num > x) {
      printf("O numero que estou pensando eh MENOR do que %d", num);
    }
    else {
      if (num < x)
        printf("O numero que estou pensando eh MAIOR do que %d", num);
      else {
        printf("\n                              VOCE ACERTOU!!");
        printf("\n                           Numero de tentativas: %d", tent);
        printf("\n                            O numero era: %d", x);
        EsperaENTER();
        limpatela();
        C4OS_Frank();

      }
    }

  tent++;
  } while (num != x && tent <= 20);

    if (tent > 20) {
        printf("\n\nVoce Ultrapassou o numero de tentativas, tente outra vez.");
        printf("\nO numero era: %d", x);
    }

    while ((s != 's' && s != 'n') || (s != 'S' && s != 'N')) {
        printf("\n\nQuer tentar outra vez? [S/N]: ");
        scanf("%c", &s);

    if (s == 's' || s == 'S')
      AdvinhaGame();
  }

    return 0;

}
