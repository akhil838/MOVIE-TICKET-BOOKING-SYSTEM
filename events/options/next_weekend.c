void nextweekend()
{

 system("cls");
 title(); 
    int next_week_a,next_week_b,econfirm;
printf("\t\t\t\t\t\tEVENTS NEXT WEEKEND\n");    
printf("\n\n\t\t1.Cuba event\t\t2.TEDx event\n\n\t\t3.Go Back\n");
printf("\n\t\tEnter your Choice:");
scanf("%d",&next_week_a);
if(next_week_a==1)
{
    cuba:
    system("cls");
    title();
    printf("\n\t\t\t\tWELCOME TO CUBA EVENT......\n");
    printf("\n\t\t1.Book tickets\t\t2.Overview\t\t3.Go Back..\n");
    printf("\n\t\tEnter ur choice:");
    scanf("%d",&next_week_b);
        if(next_week_b==1)
            {   printf("\n\t\t\t---Details Of The Event:---\n");
                printf("\n\n\t\tDate:Saturday , 25 February\n\n\t\tTime:10.00pm\n\n\t\tProceed....");
                printf("\n\t\tOnly Couples are allowed...\n\n");
                printf("\t\tWanna come...!\t\tBring your partner...\n\t\tDon't have one...\n\t\tFind one...");
                printf("\n\t\tCouple:  2000/-\n\t\tEach ticket grants entry to a couple....\n\n");
                printf("\t\tLocation: Capital mall\t4th floor\n\t\t\tHyderabad\t\tTelangana");
                printf("\n\n\t\tCONTINUE BOOKING TICKETS?....| 1.YES 2.NO");
                scanf("%d",&econfirm);
                if(econfirm !=1) goto cuba;

                printf("\n\t\tEnter number of couples:");
                scanf("%d",&couple);

                printf("\n\t\tYou have to pay:%d",(couple*2000));
                printf("\n\n\t\tPROCESSING TRANSACTION PLEASE WAIT...");
                sleep(4);
                transaction();
              }
          else if(next_week_b==2)
              {
                printf("\n\t\tCuba welcomes you to the fantastic event.....\n");
                printf("\t\tSpend time with your loved ones....");\
                getch();
                goto cuba;
              } 
          else{
                      nextweekend();
            }               
                
          }
    else if(next_week_a==2)
      {
            TEDx:
            system("cls");
            title();
            printf("\n\t\t\t\tWELCOME TO TEDx EVENT.......\n");
            printf("\n\t\t1.Book tickets\t\t2.Overview\n\n\t\t3.Go Back..\n");
            printf("\n\t\tEnter your Choice:");
            scanf("%d",&next_week_b);
                if(next_week_b==1)
                    {
                      printf("\n\t\tDate: Saturday , 26 February\n\t\tTime:\n\t\t9.00am\n\n\t\tProceed....");
                      printf("\n\t\tSelect ur category...\n");
                      printf("\n\t\tAdults\n\t\t4000/-\n\t\tEach ticket grants entry to 1 person....\n");
                      printf("\t\t\tLocation:Hyderabad,Telangana\n");
                      printf("\n\n\t\tCONTINUE BOOKING TICKETS?....| 1.YES 2.NO");
                      scanf("%d",&econfirm);
                      if(econfirm !=1) goto TEDx;                          
                      printf("\n\t\tEnter number of adults:");
                      scanf("%d",&adult);
          
                      printf("\n\n\t\tYou have to pay:%d",(adult*4000));
                      printf("\n\n\t\tPROCESSING TRANSACTION PLEASE WAIT...");
                      sleep(3);
                      transaction();
                      }
                else if(next_week_b==2)
                    {
                      printf("\n\t\tTEDx EVENT WELCOMES YOU....\n");
                      printf("\t\tExplore yourself....\n\t\tBuild your thinking...........");
                      getch();
                      goto TEDx;
                    }
                else {
                  nextweekend();
                }  
          }
          else {
            events();
          }
    }


    