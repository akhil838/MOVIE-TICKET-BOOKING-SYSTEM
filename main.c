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

int s_cmp,login_user,result=0;
int month,year,cvv=0;
int now_show_a,now_show_b,up_a;
int amount=0,transaction_a;
int theater,movie_time,mode,booking;
int adult,kid,couple,movie_a;
int next_week_a,next_week_b,econfirm;
int this_week_a,this_week_b,econfirm;
int now_show_a,now_show_b,events_a;
int i,x,num,t,i,n,a=0,snack,otp,sp,end,n1;
int VIP,GA,teen;

FILE * reset[48],*seat_fp,*moviefp,* screenfp,*ufp;
struct users u;
char usr_name[15];
char usr_pass[10];
char cardname,cardnum,str[10],ch;
char selected_movie[40];
char selected_theater[50];





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