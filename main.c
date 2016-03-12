#include <stdio.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include<allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <time.h>
#include <Windows.h>
#include <unistd.h>

int escolha=0;
unsigned sleep(unsigned seconds);
clock_t begin, end;
typedef struct{
    char nome[100];
    int score;
}UserData;

int main()
{

    double time_spent;
    begin = clock();  //começa o timer

    system("title Project C4OS");
    system("color 0a");
    frame_0();
    _sleep(1000);
    intro();
    frame_1();
    scanf("%d", &escolha);


    if(escolha == 4){
        return 0;
    }
    else if(escolha == 1){
        frame_2();
    }

    end = clock(); // para io timer
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Se passaram %.0lf segundos;", time_spent);

    //music

//    al_destroy_sample(sample);
    return 0;
//    al_destroy_timer(timer);

//    al_destroy_event_queue(event_queue);
}

/*Recordes(int money){

    end = clock(); // para io timer
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Voce gastou %.0lf segundos para fechar o jogo;", time_spent);

    printf("Sua pontuação foi: %d", (1000000 - time_spent) + (money*100));

    arq = fopen("Recordes.txt", "wt");
    if (arq == NULL)
    {
       printf("Problemas na CRIACAO do arquivo\n");
       return;
    }
    strcpy(Str,"Linha de teste");
    result = fputs(Str, arq);
    if (result == EOF)
        printf("Erro na Gravacao\n");
    fclose(arq);
}*/



