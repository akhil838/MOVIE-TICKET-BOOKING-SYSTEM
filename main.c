    //HEADER FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
    //TITLE
#include "title/Splash.c"
#include "title/title.c"
    //LOGIN FUNCTION
#include "login/login.c"
    //MOVIE FUNCTION
#include "movies/movies.c"
#include "movies/options/screen.c"
#include "movies/options/show.c"
#include "movies/options/upcoming.c"
    //EVENTS FUNCTION
#include "events/events.c"
#include "events/options/this_weekend.c"
#include "events/options/next_weekend.c"
    //TRANSACTION FUNCTION
#include "transaction/transaction.c"





int main_a;
void main(){
    splash();
    reset_seats();
    sleep(2);
    login();
}

void home(){
    start:
    system("cls");
    title();
    printf("\t\t\t\t<- THE ONLY PLACE WHERE ENTERTAINMENT BEGINS ->\n");
    printf("\n\n\t\t1.MOVIES\t\t\t\t2.EVENTS\n\n\t\t3.LOGOUT\t\t\t\t4.EXIT\n\n");
    printf("\n\t\tEnter your choice:");
    scanf("%d",&main_a);

    switch(main_a){
        case 1: movie();
                goto start;
                break;
        case 2: events();
                goto start;
                break;
        case 3: login();       
        case 4: exit(0);
        default: printf("\n\t\tEnter Valid Option!!!...");     
    }

}