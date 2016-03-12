#include<stdio.h>
#include<time.h>
#include<allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_SAMPLE *sample=NULL;
ALLEGRO_BITMAP  *image   = NULL;

void intro(){
/*    char music_path[50] ="music/gig.wav";
    PlayMusic(&music_path);
*/
    int i, k, segundos=20;
    for(i=0; i<segundos; i++){
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tG\n");
        limpatela();
    }
    for(i=0; i<segundos; i++){
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGU\n");
        limpatela();
    }
        for(i=0; i<segundos; i++){
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUI\n");
        limpatela();
    }
    for(i=0; i<segundos; i++){
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUIL\n");
        limpatela();
    }
    for(i=0; i<segundos; i++){
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUILS\n");
        limpatela();
    }
    for(i=0; i<segundos; i++){
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUILS\n");
        limpatela();
    }
    for(i=0; i<segundos; i++){
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUILST\n");
        limpatela();
    }
    for(i=0; i<segundos; i++){
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\n");
    }
    for(i=0; i<segundos; i++){
        limpatela();
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUILST\n");
        printf("\n\t\t\t\t     G\n");
    }
    for(i=0; i<segundos; i++){
        limpatela();
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUILST\n");
        printf("\n\t\t\t\t     GA\n");
    }
    for(i=0; i<segundos; i++){
        limpatela();
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUILST\n");
        printf("\n\t\t\t\t     GAM\n");
    }
    for(i=0; i<segundos; i++){
        limpatela();
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUILST\n");
        printf("\n\t\t\t\t     GAME\n");
    }
    for(i=0; i<segundos; i++){
        limpatela();
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\tGUILST\n");
        printf("\n\t\t\t\t     GAMES\n");
    }
    for(i=0; i<segundos*5; i++){
        limpatela();
        printf("\n\n\n\n\n\n\n\n\n\n\n   \t\t\t\t   PRESENTS\n");
    }
    limpatela();

}
/* Efeito de Inicializar Sistema */
void loading(){
    int i;
    //system("color a");
    FILE *file;
    file = fopen("txts/boot.txt", "r");

    char boot[100000];
    while(fgets(boot, 100000, file) != NULL){
    printf("%s", boot);
    }
    fclose(file);
    for(i=0; i<15; i++){
        printf("\n\n\n\n\n\n\n\n\n\n\n   \t\t\t\t   ... \n");
    }
    limpatela();
    return 0;
}

/* Imprime a data na tela */
void header(){
    time_t now;
    time(&now);
    printf ("\tProject C4OS OS GUILMOUR ROSSI - ENG.COMP. UTFPR 2014\n\t\t\t%s\n",ctime(&now));
    return 0;
}

void HeaderC4OS(){
    time_t now;
    time(&now);
    printf ("\tC.4.O.S. \t\t%s\n",ctime(&now));
    return 0;



}

/* Desenha C4OS na tela*/
void logo(){
    FILE *file;
    file = fopen("txts/logo.txt", "r");

    char logo[100];
    while(fgets(logo, 100, file) != NULL){
    printf("%s", logo);

    }
    printf("\n\n");
    fclose(file);



    return 0;
}

/*Bordas do Jogo*/
void bordas(){
    printf ("****************************************************************************\n");
    return 0;
}

/*Imprime o menu principal*/
void menu_principal(){
    FILE *file;
    file = fopen("txts/menu.txt", "r");
    int i;
    char menu[100000];
    while(fgets(menu, 100000, file) != NULL){
    printf("%s", menu);
    }
    printf("\n\n");
    fclose(file);

}

void limpatela(){
    #ifdef __WIN32
    system("cls");
    #endif

    #ifdef __linux__
    system("clear");
    #endif
}

/** CRIA NOVAS INFOMRAÇÕES SOBRE O USUARIO **/
void CriaUserData(){

    char a = 'a';
    char arquivo[64];
    FILE *out;
    sprintf(arquivo, "save/%c/userdata.txt", a);
    out = fopen( arquivo, "w");
    fclose(out);
    return 0;

}

void PlayMusic(char *string){

//    ALLEGRO_DISPLAY *display = NULL;
    //ALLEGRO_SAMPLE *sample=NULL;

   //char MusicPath[50] = "music/fluorescent_adolescent.wav";

   if(!al_init()){
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   if(!al_install_audio()){
      fprintf(stderr, "failed to initialize audio!\n");
      return -1;
   }

   if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
      return -1;
   }

   if (!al_reserve_samples(1)){
      fprintf(stderr, "failed to reserve samples!\n");
      return -1;
   }

   sample = al_load_sample( string ); //nome do arquivo aqui;

   if (!sample){
      printf( "Audio clip sample not loaded!\n" );
      return -1;
   }

   /*display = al_create_display(0, 0);

   if(!display){
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }
   al_destroy_display(display);
   */

   /* Loop the sample until the display closes. */
   al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

   //al_rest(10.0);
}

void timer(){

}


void PlaySample(char *string){

    ALLEGRO_SAMPLE *sample=NULL;

   //char MusicPath[50] = "music/fluorescent_adolescent.wav";

   if(!al_init()){
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   if(!al_install_audio()){
      fprintf(stderr, "failed to initialize audio!\n");
      return -1;
   }

   if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
      return -1;
   }

   if (!al_reserve_samples(1)){
      fprintf(stderr, "failed to reserve samples!\n");
      return -1;
   }

   sample = al_load_sample( string ); //nome do arquivo aqui;

   if (!sample){
      printf( "Audio clip sample not loaded!\n" );
      return -1;
   }

   /*display = al_create_display(0, 0);

   if(!display){
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }
   al_destroy_display(display);
   */

   /* Loop the sample until the display closes. */
   al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

   //al_rest(10.0);
}

void EsperaENTER(){
    fflush(stdin);
    getchar();
}

void StopMusic(){
    al_destroy_sample(sample);
    al_destroy_display(display);
}

void MostraBMP(char bmp_path[100] ){
    al_init();
    al_init_image_addon();
    //display = al_create_display(800,600);
    display = al_create_display(640,480);
    image = al_load_bitmap(bmp_path);
    al_draw_bitmap(image,0,0,0);
    al_flip_display();
    al_rest(5);
    al_destroy_display(display);
    al_destroy_bitmap(image);

}


