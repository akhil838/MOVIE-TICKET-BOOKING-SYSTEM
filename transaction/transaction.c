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
            payment();        
    case 2: printf("\n\t\tCredit Card Transaction\n");
            payment();
    }

}

void payment()
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
printf("\n\t\tEnjoy the show......");
sleep(1);
printf("\n\t\tDO YOU WANT TO CONTINUE BOOKING OTHER TICKETS (EXPLORING THE SITE) ...?\n\t\t1.STOP\t\t2.CONTINUE\n\t\tENTER YOUR CHOICE: ");
scanf("%d",&end);

if(end == 1)exit(0);
else home();

}
