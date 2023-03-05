extern  int this_week_a,this_week_b,econfirm;
extern int VIP,GA,amount;
void thisweekend()
{
  system("cls");
  title(); 

  printf("\t\t\t\t\t\tEVENTS THIS WEEKEND\n");
  printf("\n\n\t\t1.Sunburn Arena Ft. Martin Garrix - Hyderabad\t\t2.Summer Beats\n\n\t\t3.Go Back\n");
  printf("\n\n\t\tEnter your Choice:");
  scanf("%d",&this_week_a);
  if(this_week_a==1)
  {   sunburn:
    system("cls");
    title();
    printf("\n\t\t\t\t\tWELCOME TO Sunburn Arena Ft. Martin Garrix - Hyderabad......\n");
    printf("\n\t\t1.Book tickets\t\t2.Overview\n\n\t\t3.Go Back");
    printf("\n\t\tEnter ur choice:");
    scanf("%d",&this_week_b);
    if(this_week_b==1)
    {
      printf("\n\t\tDate:\n\t\tSaturday 4 March\n\n\t\tTime: 9:30pm\n\n");
      printf("\n\t\tVIP Phase 1\n\t\t3000/-\n");
      printf("\n\t\tGA Phase 1\n\t\t1500/-\n\t\tEach ticket grants entry to 1 person only!\n");
      printf("\n\n\t\tCONTINUE BOOKING TICKETS?....| 1.YES 2.NO");
      scanf("%d",&econfirm);
      if(econfirm !=1) goto sunburn;      
      printf("\n\t\tEnter number of VIP Tickets: ");
      scanf("%d",&VIP);
      printf("\n\t\tEnter number of GA Tickets: ");
      scanf("%d",&GA);
      printf("\n\t\tYou have to pay:%d",(500*VIP)+(300*GA));
      amount = 500*VIP + 300*GA;
      printf("\n\n\t\tPROCESSING TRANSACTION PLEASE WAIT...");
      sleep(3);
      transaction(2);
    }
    else if (this_week_b ==2)
    {
      printf("\n\t\tThe stage is set for the world's number one DJ - Martin Garrix!! \n\t\tGet ready for the biggest-ever Sunburn Arena tour across eight cities this Holi season!! \n\t\tCatch the award-winning artist perform...");
      getch();
      goto sunburn;
    }  
    else thisweekend();
  }
  else if (this_week_a==2)
  {     summer:  
    system("cls");
    title();
    printf("\n\t\t\t\t\tWELCOME TO Summer Beats...\n");
    printf("\n\t\t1.Book tickets\t\t2.Overview\n\n\t\t3.Go Back");
    printf("\n\t\tEnter ur choice:");
    scanf("%d",&this_week_b);
    if(this_week_b==1)
    {
      printf("\n\t\tDate:\t\tSaturday 4 March\n\n\t\tTime: 11:30pm");
      printf("\n\t\tAGE Restiction: 21+ only\n\t\tLANGUAGE: Hinglish");
      printf("\n\n\t\tCONTINUE BOOKING TICKETS?....| 1.YES 2.NO");
      scanf("%d",&econfirm);
      if(econfirm !=1) goto summer;
      printf("\n\t\tEnter number of Tickets: ");
      scanf("%d",&adult);
      amount = 499*adult;
      printf("\n\t\tYou have to pay:%d",(499*adult));
      printf("\n\n\t\tPROCESSING TRANSACTION PLEASE WAIT...");
      sleep(3);
      transaction(2);
    }
    else if (this_week_b ==2)
    {
      printf("\n\t\tSummer Beats welcomes you....\n");
      printf("\t\tSummer is just around the corner. \n\t\tStep into the summer with mind blogging Music of Chitrapuri Talkies and Dawn and end the night \n\t\ton a high note with the beats of DJ Piyush");
      getch();
      goto summer;
    }
    else thisweekend();    
  }
  else if (this_week_a==3) events();
  else {printf("Enter Valid Options !!.."); sleep(1); thisweekend();}
}

