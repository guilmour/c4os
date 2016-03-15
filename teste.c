#include<stdio.h>
#include<time.h>


int data(){
    time_t now;
    time(&now);
    printf ("It is now %s\n ",ctime(&now));
    return 0;
}
