extern int next_week_a,next_week_b,econfirm;
extern int adult,teen,amount;

void nextweekend()
{

system("cls");
title(); 

printf("\t\t\t\t\t\tEVENTS NEXT WEEKEND\n");    
printf("\n\n\t\t1.HOLI SPLASH 1.0\t\t2.Sunday Unplugged ft. Arpit Chourey\n\n\t\t3.Go Back\n");
printf("\n\t\tEnter your Choice:");
scanf("%d",&next_week_a);
if(next_week_a==1)
{ HOLI:
          system("cls");
          title();
          printf("\n\t\t\t\tWELCOME TO HOLI SPLASH 1.0 | Holi 2023.......\n");
          printf("\n\t\t1.Book tickets\t\t2.Overview\n\n\t\t3.Go Back..\n");
          printf("\n\t\tEnter your Choice:");
          scanf("%d",&next_week_b);
              if(next_week_b==1)
                  {
                    printf("\n\t\tDate: Wednesday , 8 March\n\t\tTime:\t\t9.00am");
                    printf("\n\t\tLocation:SkyBox Sports club, Opp Sreyas Engineering College,\n\t\t\tHyderabad,Telangana\n");
                    printf("\n\t\tPrice: 299/- for each person.");
                    printf("\n\n\t\tCONTINUE BOOKING TICKETS?....| 1.YES 2.NO");
                    scanf("%d",&econfirm);
                    if(econfirm !=1) goto HOLI;                          
                    printf("\n\t\tEnter number of Tickets:");
                    scanf("%d",&adult);
                    printf("\n\n\t\tYou have to pay:%d",(adult*299));
                    amount = 299*adult;
                    printf("\n\n\t\tPROCESSING TRANSACTION PLEASE WAIT...");
                    sleep(3);
                    transaction(3);
                    }
              else if(next_week_b==2)
                  {
                  printf("\n\t\tLet's Celebrate the festival of colors by bringing positivity and happiness\n\t\tin each others lives by adding colors to their life");
                  getch();
                    goto HOLI;
                  }
              else { nextweekend();}  
        }
else if(next_week_a==2)
{
  Sunday:
    system("cls");
    title();
    printf("\n\t\t\t\tWELCOME TO Sunday Unplugged ft. Arpit Chourey......\n");
    printf("\n\t\t1.Book tickets\t\t2.Overview\n\n\t\t3.Go Back..\n");
    printf("\n\t\tEnter ur choice:");
    scanf("%d",&next_week_b);
        if(next_week_b==1)
            {   printf("\n\t\t\t---Details Of The Event:---\n");
                printf("\n\n\t\tDate:Friday , 11 March\n\n\t\tTime:10.00pm\n\n\t\tProceed....");
                printf("\n\t\tAdult:  800/-\n\t\tTeens: 600\n");
                printf("\t\tLocation: Capital mall, 4th floor\n\t\t\tHyderabad, Telangana");
                printf("\n\n\t\tCONTINUE BOOKING TICKETS?....| 1.YES 2.NO");
                scanf("%d",&econfirm);
                if(econfirm !=1) goto Sunday;
                printf("\n\t\tEnter number of Adults:");
                scanf("%d",&adult);
                printf("\n\t\tEnter number of Teens:");
                scanf("%d",&teen);
                printf("\n\t\tYou have to pay:%d",(adult*800)+(teen*600));
                amount = (adult*800)+(teen*600);
                printf("\n\n\t\tPROCESSING TRANSACTION PLEASE WAIT...");
                sleep(4);
                transaction(3);
              }
          else if(next_week_b==2)
              {
                printf("\n\t\tThis March 11th, Featuring the famous and the man with impeccable talent Ankit Tiwari. \n\t\tWitness the magic live!");
                getch();
                goto Sunday;
              } 
          else{ nextweekend();} 
    }
else { events();} 
}

