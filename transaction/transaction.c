extern int now_show_a;
extern int amount;
extern int num,n1,rname,i,t,x,mode,booking;
extern int n,a,theater,movie_time,snack;
extern char ch,usr_name[15];
extern int next_week_a,this_week_a;
extern char selected_movie[40];
extern char selected_theater[50];
extern int num_ticket;
extern int adult,VIP,GA,teen;
void transaction(int i)
{
    int transaction_a;
    system("cls");
    title();
    printf("\t\t\t\t\t<- PAYMENT GATEWAY ->");
    printf("\n\n\n\t\t1.Debit card\t\t2.Credit card");
    printf("\n\t\tEnter your mode of transaction:");
    scanf("%d",&transaction_a);
    switch(transaction_a){
    case 1: printf("\n\t\tDebit Card Transaction\n");
            payment(i);        
    case 2: printf("\n\t\tCredit Card Transaction\n");
            payment(i);
    }

}

void payment(int i)
{
char cardname,cardnum,str[10];
int month,year,cvv=0,otp,sp,end;
system("cls");
title();
printf("\n\t\t\t.......... TRANSACTION........");
printf("\n\t\tEnter name as it appears on your card : ");
scanf("%s",&cardname);
printf("\n\t\tEnter your card number: ");
scanf("%s",&cardnum);
printf("\n\t\tEnter expiry date(month&year): ");
scanf("%d %d",&month,&year);

printf("\n\t\tEnter CVV:");
while(cvv<=3)
{
str[cvv]=getch();
sp=str[cvv];
if(sp==3)
  break;
else
  printf("*");
  cvv++;
}
str[cvv]='\0';

printf("\n\t\tOTP has been sent Mobile No. :");
printf("\n\t\tEnter your OTP number:");
scanf(" %d",&otp);

printf("\n\n\t\tYOUR TRANSACTION HAS BEEN DONE SUCCESSFULLY......");
printf("\t\tYOUR TICKET IS BOOKED");
printf("\n\n\t\tPRINTING TICKET...");
ticket_print(i);

printf("\n\t\tEnjoy the show......");
sleep(1);
printf("\n\n\t\tDO YOU WANT TO CONTINUE BOOKING OTHER TICKETS (EXPLORING THE SITE) ...?\n\t\t1.STOP\t\t2.CONTINUE\n\t\tENTER YOUR CHOICE: ");
scanf("%d",&end);

if(end == 1)exit(0);
else home();

}


void ticket_print(int i){
FILE* tp;
tp = fopen("TICKET.txt","a");
fprintf(tp,"USERNAME: %s\n",usr_name);
if(i==1){
    fprintf(tp,"MOVIE: %s",selected_movie);
    fprintf(tp,"\nTHEATER: %s",selected_theater);
    if(movie_time == 1) {fputs("\nSHOW TIMING: Afternoon\t(12:00 PM)",tp);}
    if(movie_time == 2) {fputs("\nSHOW TIMING: Evening\t(06:00 PM)",tp);}
    if(movie_time == 3) {fputs("\nSHOW TIMING: Night\t(09:00 PM)",tp);}
    fprintf(tp,"\nNUMBER OF TICKETS: %d",num_ticket);
}
else if(i==2){
    if(this_week_a == 1){fprintf(tp,"EVENT: Sunburn Arena Ft. Martin Garrix\nTICKETS: VIP-%d, GA%d",VIP,GA);}
    if(this_week_a == 2){fprintf(tp,"EVENT: Summer Beats\nTICKETS: %d",adult);}
}
else if(i==3){
    if(next_week_a == 1){fprintf(tp,"EVENT: HOLI SPLASH 1.0\nTICKETS: %d",adult);}
    if(next_week_a == 2){fprintf(tp,"EVENT: Sunday Unplugged\nTICKETS: Adults - %d,Teen - %d",adult,teen);}
}
    fprintf(tp,"\nTOTAL AMOUNT: %d\n\n\n",amount);

fclose(tp);
  
}
