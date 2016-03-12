//OI
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <windows.h>
typedef struct ALLEGRO_DISPLAY ALLEGRO_DISPLAY;

int p1=0, p2=0, p3=0, p4=0, p5=0; //variavel de quanto esta pronta do c4os


typedef struct{
    char nome[100];
    int money;
    char local[100];
}UserData;
UserData userdata;
int escolha, cont=0;
char c;
FILE *file;
int velD = 50; //50
int velO = 5;

void MenuBar(){
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    /*
    * First save the current color information
    */
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    /*
    * Set the new color information
    */
    SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );


    bordas();
    printf("\t%s\t|\t$%d\t|\t%s\n", userdata.nome, userdata.money, userdata.local);
    bordas();
    SetConsoleTextAttribute ( h, wOldColorAttrs);
    printf("\n");
    return 0;

}



void EscolheOpcao(int min, int max){

    scanf("%d", &escolha);

    if(escolha > max || escolha < min ){

    printf("\t>>");

    EscolheOpcao(min, max);

    }

}

void EscreveDialogo(FILE *file){
    while((c = getc(file) ) != '¬'){
    printf("%c", c);
    _sleep(velD); //velD velocidade com que a impressao acontece em milisegundos
    }
}

void EscreveOpcao(FILE *file){
    while((c = getc(file) ) != '¬'){
    printf("%c", c);
    _sleep(velO);
    }
}

void PulaTexto(FILE *file, char carac){
    while((c = getc(file) ) != carac){
    }

}

void frame_0(){
    int i;
    char string[50] = "samples/sfx_8bit_1 (42).wav";
    PlaySample(&string);
    int temp=0;
    char temp2[2];
    limpatela();
    char nome[50];
    file = fopen("txts/frame0.txt", "r");
    char texto[100];
    while(fgets(texto, 100, file) != NULL){
    printf("%s", texto);
    }
    fclose(file);

    file = fopen("txts/userdata.txt", "w");
    scanf("%s", &userdata.nome);
    PlaySample(&string);
    //al_destroy_sample(string);
    printf("\n\t\t       Bom Jogo!  %s *-*\n\n\n\t\t\t    \n", userdata.nome);
    fprintf(file, "1NOME:%s\n", nome);
    //fprintf(temp, "Buffered, will be flushed");
    fflush(stdin);
    _sleep(3000);

    char a = 'a';
    char arquivo[64];
    FILE *file2;
    sprintf(arquivo, "save/%c/userdata.txt", nome);
    file2 = fopen(arquivo, "w+");
    fclose(arquivo);
    fclose(file2);

    char music_path[50] ="music/gig.wav";
    PlayMusic(&music_path);

}

int frame_1(){
    bordas();
    loading();
    bordas();
    header();
    logo();
    menu_principal();
    bordas();
}

int frame_2(){
    StopMusic();
    char music_path[50] ="music/creep.wav";
    PlayMusic(&music_path);
    _sleep(1000);
    strcpy(userdata.local, "Sala de Calculo E308");
    userdata.money = 30;
    limpatela();
    MenuBar();
    _sleep(500);
    FILE *file;
    file = fopen("txts/frame2.txt", "r");
    char texto[100];
    if(!file)
    {
    printf( "Erro na abertura do arquivo");
    exit(0);
    }

    EscreveDialogo(file);    //3
    EscreveOpcao(file);
    EscolheOpcao(1,2); //6

    if(escolha == 1){
        PulaTexto(file, '|');

        EscreveDialogo(file);//9

        printf("%s?!", userdata.nome);

        EscreveOpcao(file);//13
        EscolheOpcao(1,2);

        if(escolha == 1){
            PulaTexto(file, '|');

            EscreveDialogo(file);

            EscreveOpcao(file);

            EscreveDialogo(file);//33

            EsperaENTER();
            frame_3();
        }

        else if(escolha == 2){
            PulaTexto(file, '@');//27

            EscreveDialogo(file);//29

            printf("%s!", userdata.nome);

            EsperaENTER();

            frame_4();

        }

    }

    else if(escolha == 2){

        PulaTexto(file, '@');//27

        EscreveDialogo(file);//29

        printf("%s!", userdata.nome);
        EsperaENTER();
        frame_4();

    }

    EsperaENTER();
    fclose(file);
    /*
    if(texto == '\n'){
        fflush(stdin);
        getchar();
    }
        printf("%s", texto);

    fclose(file);
    */


}

int frame_3(){
    strcpy(userdata.local, "Sala do Coordenador");
    limpatela();
    MenuBar();
    FILE *file;
    char c;
    file = fopen("txts/frame3.txt", "r");
    char texto[100];
    if(!file)
    {
    printf( "Erro na abertura do arquivo");
    exit(0);
    }

    EscreveDialogo(file);//3

    printf("%s?!", userdata.nome);//3

    EscreveDialogo(file);//8

    printf("%s?!", userdata.nome);//10

    EscreveDialogo(file);//20
    EsperaENTER();
    frame_6();


}

int frame_4(){
    strcpy(userdata.local, "Patio Universidade");
    limpatela();
    MenuBar();

    FILE *file;
    char c;
    file = fopen("txts/frame4.txt", "r");
    char texto[100];
    if(!file)
    {
    printf( "Erro na abertura do arquivo");
    exit(0);
    }

    EscreveDialogo(file);//3

    EscreveOpcao(file);//6

    EscolheOpcao(1,2); //6

    if(escolha == 1){ //DJALMA
        limpatela();
        strcpy(userdata.local, "Djalma Lanches");
        MenuBar();
        PulaTexto(file, '|');

        EscreveDialogo(file);//10 1/2

        printf("%s", userdata.nome);//10

        EscreveDialogo(file);//11

        EscreveOpcao(file);//15

        EscolheOpcao(1,3);

        if(escolha == 1){ //x-salada

            PulaTexto(file, '|');
            EscreveDialogo(file);
            userdata.money = userdata.money - 5;
            EsperaENTER();
            fclose(file);
            frame_5();
        }

        if(escolha == 2){ //x-burguer

            PulaTexto(file,'@');
            EscreveDialogo(file);
            userdata.money = userdata.money - 4;
            EsperaENTER();
            fclose(file);
            frame_5();
        }

        if(escolha == 3){ //x-coxinha
            PulaTexto(file,'§');
            EscreveDialogo(file);
            userdata.money = userdata.money - 6;
            EsperaENTER();
            fclose(file);
            frame_5();
        }

    }

    else if(escolha == 2){ //RU
        limpatela();
        strcpy(userdata.local, "Rest. Universitario");
        MenuBar();
        PulaTexto(file,'&');
        EscreveDialogo(file);//20

        EscreveOpcao(file);//24

        scanf("%d", &escolha);

        EscreveDialogo(file);//26
        userdata.money = userdata.money - 3;
        EsperaENTER();
        frame_5();


    }

    fclose(file);

}

int frame_5(){
    strcpy(userdata.local, "Corredores Universidade");
    limpatela();
    MenuBar();
    file = fopen("txts/frame5.txt", "r");
    char texto[100];
    if(!file)
    {
    printf( "Erro na abertura do arquivo");
    exit(0);
    }

    EscreveDialogo(file);
    EscreveOpcao(file);
    EscolheOpcao(1,2);

    if(escolha == 1){ //Biblioteca sem multa
        StopMusic();
        char music_path[50] ="music/high.wav";
        PlayMusic(&music_path);
        _sleep(1000);
        strcpy(userdata.local, "Biblioteca");
        limpatela();
        MenuBar();
        PulaTexto(file, '@');
        EscreveDialogo(file);
        EsperaENTER();
        strcpy(userdata.local, "Area Restrita Biblio");
        limpatela();
        MenuBar();
        EscreveDialogo(file);
        EscreveOpcao(file);
        EscolheOpcao(1,1);
        MostraBMP("pics/caixa.bmp");
        _sleep(950);
        EscreveDialogo(file);
        EsperaENTER();
        fclose(file);
        frame_7();
    }

    else if(escolha == 2){ //CRIS
        PulaTexto(file, '|');
        EscreveDialogo(file);
        printf("%s",  userdata.nome);
        EscreveDialogo(file);
        EsperaENTER();
        StopMusic();
        char music_path[50] ="music/high.wav";
        PlayMusic(&music_path);
        _sleep(950);
        strcpy(userdata.local, "Sessao Restrita Biblio");
        limpatela();
        MenuBar();
        EscreveDialogo(file);
        printf("%s", userdata.nome);
        EscreveDialogo(file);
        EsperaENTER();
        limpatela();
        MenuBar();
        EscreveDialogo(file);
        EscreveOpcao(file);
        EscolheOpcao(1,1);
        MostraBMP("pics/caixa.bmp");
        _sleep(950);
        EscreveDialogo(file);
        EsperaENTER();
        fclose(file);
        frame_7();
    }







}

int frame_6(){

    strcpy(userdata.local, "Livrarias Curytiba");
    limpatela();
    MenuBar();
    file = fopen("txts/frame6.txt", "r");
    char texto[100];
    if(!file)
    {
    printf( "Erro na abertura do arquivo");
    exit(0);
    }

    EscreveDialogo(file);
    EscreveOpcao(file);
    EscolheOpcao(1,3);

    if(escolha == 1){
        PulaTexto(file, '|');
        EscreveDialogo(file);
        PulaTexto(file, '&');
        EscreveDialogo(file);
        userdata.money = userdata.money - 10;
        EsperaENTER();
        strcpy(userdata.local, "Biblioteca");
        limpatela();
        MenuBar();
        PulaTexto(file, '#');
        EscreveDialogo(file);
        EsperaENTER();

        StopMusic();
        char music_path[50] ="music/high.wav";
        PlayMusic(&music_path);
        _sleep(1000);

        strcpy(userdata.local, "Sessao Restrita Biblio");
        limpatela();
        MenuBar();
        EscreveDialogo(file);
        EscreveOpcao(file);
        EscolheOpcao(1,1);
        MostraBMP("pics/caixa.bmp");
        _sleep(950);
        EscreveDialogo(file);
        EsperaENTER();
        frame_7();
    }

    else if(escolha == 2){
        PulaTexto(file, '@');
        EscreveDialogo(file);
        PulaTexto(file, '&');
        EscreveDialogo(file);
        userdata.money = userdata.money - 10;
        EsperaENTER();
        strcpy(userdata.local, "Biblioteca");
        limpatela();
        MenuBar();
        PulaTexto(file, '#');
        EscreveDialogo(file);
        EsperaENTER();

        StopMusic();
        char music_path[50] ="music/high.wav";
        PlayMusic(&music_path);
        _sleep(1000);

        strcpy(userdata.local, "Sessao Restrita Biblio");
        limpatela();
        MenuBar();
        EscreveDialogo(file);
        EscreveOpcao(file);
        EscolheOpcao(1,1);
        MostraBMP("pics/caixa.bmp");
        _sleep(950);
        EscreveDialogo(file);
        EsperaENTER();
        frame_7();
    }

    else if(escolha == 3){
        PulaTexto(file, '§');
        EscreveDialogo(file);
        PulaTexto(file, '&');
        EscreveDialogo(file);
        userdata.money = userdata.money - 10;
        EsperaENTER();
        strcpy(userdata.local, "Biblioteca");
        limpatela();
        MenuBar();
        PulaTexto(file, '#');
        EscreveDialogo(file);
        EsperaENTER();

        StopMusic();
        char music_path[50] ="music/high.wav";
        PlayMusic(&music_path);
        _sleep(1000);

        strcpy(userdata.local, "Sessao Restrita Biblio");
        limpatela();
        MenuBar();
        EscreveDialogo(file);
        EscreveOpcao(file);
        EscolheOpcao(1,1);
        MostraBMP("pics/caixa.bmp");
        _sleep(950);
        EscreveDialogo(file);
        EsperaENTER();
        frame_7();
    }

}

int frame_7(){
    //system("color 0b");
    strcpy(userdata.local, "Meu Quarto-Laboratorio");
    limpatela();
    MenuBar();
    file = fopen("txts/frame7.txt", "r");
    char texto[100];
    if(!file)
    {
    printf( "Erro na abertura do arquivo");
    exit(0);
    }
    int i;

    EscreveDialogo(file);
    EsperaENTER();
    EscreveDialogo(file);
    EsperaENTER();
    //INICIA C4OS
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;
    SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    limpatela();
    bordas();
    logo();
    printf("\n");
    for(i=0; i<75; i++){
        printf("%c", 178);
        _sleep(100);
    }
    PulaTexto(file, '@');
    EscreveOpcao(file);
    EsperaENTER();
    EscreveOpcao(file);
    bordas();
    EsperaENTER();
    //fecha c4os

    SetConsoleTextAttribute ( h, wOldColorAttrs);
    EscreveDialogo(file);
    EsperaENTER();
    limpatela();
    MenuBar();
    EscreveDialogo(file);//depuração

    C4OS_Depuracao();
}

void C4OS_Depuracao(){
    limpatela();
    MenuBar();
    printf("\nVou tentar iniciar em modo de Depuracao Agora....\n");
    file = fopen("txts/frame7.txt", "r");
    char texto[100];
    if(!file)
    {
    printf( "Erro na abertura do arquivo");
    exit(0);
    }
    int i;
    //Inicia C4OS Novamente! (modo segurança)
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;
    SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    bordas();
    logo();
    printf("\n");
    for(i=0; i<75; i++){
        printf("%c", 178);
        _sleep(100);
    }
    printf("\n\tCarregando Sistema.....\n\tIniciar em Modo Seguro? (ENTER)\n");

    EsperaENTER();

    printf("\tWelcome User!\n\tLOGIN:");
    //Welcome User LOGIN:
    char login[10];
    scanf("%s", &login);

    if(stricmp (login, "Frank") == 0){
        printf("\n\tSenha Correta!!\n");
        bordas();

        StopMusic();
        char string[50] = "samples/sfx_8bit_1 (94).wav";
        PlaySample(&string);
        _sleep(1000);
        C4OS_Frank();
    }
    else {
        printf("\n\tERROR! Incorrect User! Try Again.");
        printf("\n");
        bordas();
        EsperaENTER();
        SetConsoleTextAttribute ( h, wOldColorAttrs);
        PulaTexto(file, '&');
        EscreveDialogo(file);
        EscreveOpcao(file);
        EscolheOpcao(1,2);
        if(escolha == 1){
            limpatela();
            C4OS_Depuracao();
        }
        else if(escolha == 2){
            MostraBMP("pics/caixa.bmp");
            limpatela();
            C4OS_Depuracao();
        }
    }

}

void C4OS_login(){
    int i;
    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;
    SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
    bordas();
    HeaderC4OS();
    logo();
    printf("\n");
    for(i=0; i<75; i++){
        printf("%c", 178);
        _sleep(10);
    }
    printf("\tWelcome User!\n\tLOGIN:");
    //Welcome User LOGIN:
    char login[10];
    char senha[10];
    scanf("%s", &login);

    if(stricmp (login, "Frank") == 0){ //frank nao tem senha
        printf("\n\tSenha Correta!!\n");
        bordas();

        StopMusic();
        char string[50] = "samples/sfx_8bit_1 (94).wav";
        PlaySample(&string);
        _sleep(1000);
        C4OS_Frank();
    }

    else if(stricmp (login, "Kevin") == 0){
        printf("\nSenha:");
        scanf("%s", &senha);

        if(stricmp (senha, "seamus") == 0){

            printf("\n\tSenha Correta!!\n");
            bordas();
            StopMusic();
            char string[50] = "samples/sfx_8bit_1 (94).wav";
            PlaySample(&string);
            _sleep(1000);
           C4OS_Kevin();
        }

        else {
            printf("\n\tSenha Incorreta!!\n");
             printf("\n\tDica da Senha: ~O nome do meu cachorro~ \n");
            EsperaENTER();
            limpatela();
            C4OS_login();
        }

    }

    else if(stricmp (login, "Susan") == 0){
        printf("\nSenha:");
        scanf("%s", &senha);

        if(stricmp (senha, "newton") == 0){

            printf("\n\tSenha Correta!!\n");
            bordas();
            StopMusic();
            char string[50] = "samples/sfx_8bit_1 (94).wav";
            PlaySample(&string);
            _sleep(1000);
            StopMusic();
            StopMusic();
            C4OS_Susan();
        }


        else {
            printf("\n\tSenha Incorreta!!\n");
            printf("\n\tDica da Senha: ~Melhor fisico da historia!~ \n");
            EsperaENTER();
            limpatela();
            C4OS_login();
        }
    }

    else{
        printf("\nUser ou Senha Incorretos!");
        EsperaENTER();
        limpatela();
        C4OS_login();
    }
}


void C4OS_Frank(){
    StopMusic();
    char string[50] = "music/liveonce.wav";
    PlayMusic(&string);
    limpatela();
    bordas();
    HeaderC4OS();
    printf("Bem vindo ao C.4.O.S!\n");
    _sleep(500);
    printf("Nome: Frank.\tFuncao: Estagiario.\tAcesso: Limitado\n");
    bordas();
    printf("Operacoes encontrados neste diretorio:\n");
    printf("1.Banco de Dados\n\n2. Kevin_Eu_e_Susan.jpg\n\n3.jogo_da_velha.exe\n\n4.jogo_advinha.exe\n\n5.seamus_PinkFloyd.wav\n\n6. SAIR\n");

    scanf ("%d", &escolha);
    switch (escolha)
        {
        	case 1:
                	printf ("\n\n\a\aAcesso Nao Permitido!");
                	EsperaENTER();
                	limpatela();
                	C4OS_Frank();
        	break;
        	case 2:
                    MostraBMP("pics/turma_reunida.bmp");
                    C4OS_Frank();
        	break;
        	case 3:
                	limpatela();
                    p1 = 1;
                	JogodaVelha();

        	break;
            case 4:
                    limpatela();
                    p2 = 1;
                	AdvinhaGame();
        	break;

            case 5:
                    printf("\nSeamus - Pink Floyd\n");
                    file = fopen("txts/seamus.txt", "r");
                    char texto[100];
                    if(!file){
                    printf( "Erro na abertura do arquivo");
                    exit(0);
                    }
                    int i;
                    EscreveOpcao(file);
                    EsperaENTER();
                    C4OS_Frank();

        	break;

            default:
                    limpatela();
                    C4OS_login();


        }
	return(0);

}

void C4OS_Susan(){
    StopMusic();
    StopMusic();
    StopMusic();
    StopMusic();
    char music_path[50] = "music/adolescent.wav";
    PlayMusic(&music_path);
    limpatela();
    bordas();
    HeaderC4OS();
    printf("Bem vindo ao C.4.O.S!\n");
    _sleep(500);
    printf("Nome: Susan.\tFuncao: Astrofisica.\tAcesso: Ilimitado\n");
    bordas();
    printf("Operacoes encontrados neste diretorio:\n");
    printf("1.gravitacao planetaria\n\n2. >>COMPILAR C4OS<<\n\n3.SAIR\n");

    scanf ("%d", &escolha);
    switch (escolha)
        {
        	case 1:
                    p3 = 1;
                	limpatela();
                	pesoPlanetas();
                	C4OS_Susan();
        	break;

            case 2:
                C4OS_FINAL();
                /*
                if(p1 == 1, p2 == 1, p3 == 1, p4 == 1, p5 == 1){

                }

                else{

                    printf("\nO C4OS ainda nao estava 100% restaurando.\n");
                    EsperaENTER();
                    limpatela();
                    C4OS_Susan();

                }*/


        	break;

            default:
                    limpatela();
                    C4OS_login();


        }
	return(0);

}

void C4OS_Kevin(){
    StopMusic();
    StopMusic();
    StopMusic();
    StopMusic();
    char music_path[50] = "music/gimme_shelter.wav";
    PlayMusic(&music_path);
    limpatela();
    bordas();
    HeaderC4OS();
    printf("Bem vindo ao C.4.O.S!\n");
    _sleep(500);
    printf("Nome: KEVIN.\tFuncao: Programado e Matemarico.\tAcesso: Ilimitado\n");
    bordas();
    printf("Operacoes encontrados neste diretorio:\n");
    printf("1.fibonnaci\n\n2. criptografia\n\n3. >>COMPILAR C4OS<< \n\n4.SAIR\n");

    scanf ("%d", &escolha);
    switch (escolha)
        {
        	case 1:
                    p4 = 1;
                	limpatela();
                	Fibonacci();
                	C4OS_Kevin();
        	break;

            case 2:
                    p5 = 1;
                	limpatela();
                    Criptografia();
                    C4OS_Kevin();
        	break;

        	case 3:

                C4OS_FINAL();
                /* if(p1 == 1, p2 == 1, p3 == 1, p4 == 1, p5 == 1){

                }
                else{

                    printf("\nO C4OS ainda nao estava 100% restaurando.");
                    EsperaENTER();
                    limpatela();
                    C4OS_Kevin();
                }
                */
        	break;


            default:
                    limpatela();
                    C4OS_login();


        }
	return(0);

}

void C4OS_FINAL(){
    system("color a");
    limpatela();
    MenuBar();

    file = fopen("txts/final.txt", "r");
    char texto[100];

    if(!file){
        printf( "Erro na abertura do arquivo");
        exit(0);
    }

    EscreveDialogo(file);
    EsperaENTER();
    EscreveDialogo(file);
    printf("%s", userdata.nome);
    EscreveDialogo(file);
    char string[50] = "samples/tiro.wav"; //tiro
    PlaySample(&string);
    EsperaENTER();
    limpatela();
    StopMusic();
    char music_path[50] = "samples/sfx_8bit_1 (40).wav"; //barramg
    PlaySample(&music_path);
    system("color F7");
    StopMusic();
    _sleep(3000);

    char music_path2[50] = "music/babyblue.wav"; //baby blue
    PlayMusic(&music_path2);
    system("color 0E");

    EscreveDialogo(file);
    EsperaENTER();

    /* creditos */
    StopMusic();
    char string4[50] = "music/pressure.wav"; //baby blue
    PlayMusic(&string4);

    EscreveDialogo(file);
    exit(0);
//    Recordes(userdata.money, &userdata.nome);

}


































