#include "teste.h"
#include <stdio.h>
#include <time.h>

teste::teste()
{
    //ctor
}

teste::~teste()
{
    //dtor
}




int data(){
    time_t now;
    time(&now);
    printf ("It' s now %s\n ",ctime(&now));
    return 0;
}
