/*Código encontrado no site http://tilinguagenspro.blogspot.com.br/2014/03/jogo-da-velha-completo-em-linguagem-c.html
"Inteligencia artifical (aleatoria) implementada por @guilmour"*/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int conta = 0;

void JogodaVelha(){

    bordas();
    printf("*****************     \aSUPER JOGO DA VELHA.     *****************************\n\n\n");
    printf("Seu desafio aqui eh ganhar do adversario durante 5 vezes seguidas!\n");
    JogarJV();
}




int JogarJV(){
    srand(time(NULL));
    //char para a tabela do jogo
    char *tabela[3][3];
    //o mudarjogador é para usar dentro do for,fazendo com que em quanto o for fo rodando
    //e sempre receba +1 quando for rodado de novo,ele é usado poder mudar de jogador e
    //comparar quando é para mostra na tabela 'O' ou 'X'
    int mudarjogador=1,l=0,j,i,linha,coluna;
    for(i=0;i<3;i++)//for usado para declara que tabela[3][3] sera vazia
        for(j=0;j<3;j++)//for usado para declara que tabela[3][3] sera vazia
             //como esta tabela[i][j]=" " e os dois for seram rodados 3 vezes 'i' e 'j' passaram de 0 por 0 para 0 por 1 depois
             //0 por 2 e 0 por 3 depois o for sera rodado novamente e passarar a ser 1 por 0 depois 1 por 1 e assim sucessivamente sempre vazio
             tabela[i][j]=" ";
    //for para mostra a tabela do jogo
    for(i=0;i<3;i++){
                     printf("\t\t\t\t %s | %s | %s\n",tabela[i][0],tabela[i][1],tabela[i][2]);
                     //if pra comparar se i<3-1, como i é <3 ele so era printa duas linha,sendo assim a tabela ira sair perfeita
                     if(i<3-1){
                               printf("\t\t\t\t-----------\n");
                               }
                     }
    //for pra poder jogar nove vezes
    for(l=1;l<=9;l++){
        //if para mudar de jogador 1 e jogador 2 quando o for roda a primeira vez modarjogador sera 1 ai sera o jogador 1
        //quando rodar novamente mudarjogador sera 2 ai sera o jogador 2, numeros inpas jogador um caso contrario jogador 2
        if(mudarjogador==1 || mudarjogador==3 || mudarjogador==5 || mudarjogador==7 || mudarjogador==9){
            printf("EU\n");
            printf("Digite a linha\n");
            //escaniando a linha
            scanf("%d",&linha);
            printf("Digite a coluna\n");
            //escaniando a coluna
            scanf("%d",&coluna);
            limpatela();
        }
        else{
            printf("MAQUINA\n");
            printf("Digite a linha:");
            linha = rand() % 3 + 1;
            _sleep(500);
            printf(" %d", linha);
            printf("\nDigite a coluna:");
            coluna = rand() % 3 + 1;
            _sleep(500);
            printf(" %d\n", coluna);
            _sleep(1500);
            limpatela();
        }


    //depois de escaniar apague tudo com system("cls") e irar entra no if para comparar

    //if para dizer se a tabela linha e coluna digitadas estiverm vazias mostre a figura na tabela
    //-1 é para ele ler aparti da linha 1 e coluna 1
    if(tabela[linha-1][coluna-1]==" "){
                         if (tabela[linha-1][coluna-1]=" "){
                                                //if para comparar se mudarjador==1 e ==3 e 5 e 7 ou 9 sera o jogador 1 e mostrara na tabela a 'O'
                                                if(mudarjogador==1 || mudarjogador==3 || mudarjogador==5 || mudarjogador==7 || mudarjogador==9){
                                                                                       tabela[linha-1][coluna-1]="O";
                                                }
                                                                                  //caso contrario mostrarar o 'X'
                                                                                  else {
                                                                                        tabela[linha-1][coluna-1]="X";
                                                                                        }
                         }
                                    //variaveu para mudar de jogador e mostra a figura de acordo com a vez do jogador
                                    mudarjogador++;
                                    }
                                    //caso contrario mostre esta oculpado
    else{
         printf("Casa ja ocupada!!! Tente outra coordenada!\n\n\n");
         //variaveu para que se a casa ja estiver oculpado o i-- faz com que o for volte uma vez ai faz com que nao seja interfirido no jogador
         i--;
    }
    //printfs para printa a figura na linha e coluna que o jogador escolher
    printf("\t\t\t\t %s | %s | %s\n", tabela[0][0], tabela[0][1], tabela[0][2]);
    printf("\t\t\t\t-----------\n");
    printf("\t\t\t\t %s | %s | %s\n", tabela[1][0], tabela[1][1], tabela[1][2]);
    printf("\t\t\t\t-----------\n");
    printf("\t\t\t\t %s | %s | %s\n", tabela[2][0], tabela[2][1], tabela[2][2]);
    //if para comparar se a figura 'O' ja estiver na horizontal ou vertical ou diagonal
    //verifica na horizontal
    if((tabela[0][0]=="O" && tabela[0][1]=="O" && tabela[0][2]=="O")||
    (tabela[1][0]=="O" && tabela[1][1]=="O" && tabela[1][2]=="O")||
    (tabela[2][0]=="O" && tabela[2][1]=="O" && tabela[2][2]=="O")||
    //verifica na vertical
    (tabela[0][0]=="O" && tabela[1][0]=="O" && tabela[2][0]=="O")||
    (tabela[0][1]=="O" && tabela[1][1]=="O" && tabela[2][1]=="O")||
    (tabela[0][2]=="O" && tabela[1][2]=="O" && tabela[2][2]=="O")||
    //verifica na diagonal
    (tabela[0][0]=="O" && tabela[1][1]=="O" && tabela[2][2]=="O")||
    (tabela[0][2]=="O" && tabela[1][1]=="O" && tabela[2][0]=="O")){
                        conta++;
                       printf("\n\t\tJogador 1, Voce ja venceu %d vezes:)\n\n\n", conta);

                      //para o jogo
                       break;
                                                                     }
    //if para comparar se a figura 'X' ja estiver na horizontal ou vertical ou diagonal
    //verifica na horizontal
    if((tabela[0][0]=="X" && tabela[0][1]=="X" && tabela[0][2]=="X")||
    (tabela[1][0]=="X" && tabela[1][1]=="X" && tabela[1][2]=="X")||
    (tabela[2][0]=="X" && tabela[2][1]=="X" && tabela[2][2]=="X")||
    //verifica na vertical
    (tabela[0][0]=="X" && tabela[1][0]=="X" && tabela[2][0]=="X")||
    (tabela[0][1]=="X" && tabela[1][1]=="X" && tabela[2][1]=="X")||
    (tabela[0][2]=="X" && tabela[1][2]=="X" && tabela[2][2]=="X")||
    //verifica na diagonal
    (tabela[0][0]=="X" && tabela[1][1]=="X" && tabela[2][2]=="X")||
    (tabela[0][2]=="X" && tabela[1][1]=="X" && tabela[2][0]=="X")){

                       printf("\n\t\t a MAQUINA venceu :)\n\n\n");
                       conta = 0;
                       printf("Comece do Zero o game!");
                       //para o jogo
                       break;
                       }
                       //se o for rodar nove vezes e ninguem ganhar mostre que deu empate
                       if(l==9){
                               printf("Partida Empatada\n\n\n");
                               break;
                       }
}
             //printf("Digite 1 para jogar novamente\nDigite 2 para sair do jogo\n");
             //scanf para ler um numero
             //scanf("%d",&i);
             //se o numero digitado for =1 apague todo e mostre o jogo da velha
             if(conta < 5){
                        EsperaENTER();
                      limpatela();
                      JogarJV();
             }
             //se numero digitado for =2 feche com a função exit
             else if(conta >= 5){
                      printf("Parabens! Voce zerou o SUPER JOGO DA VELHA!\n");
                      EsperaENTER();
                      C4OS_Frank();
                      //exit(2);
             }
}

