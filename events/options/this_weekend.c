void thisweekend()
{
  system("cls");
  title(); 
  int this_week_a,this_week_b,econfirm;
  printf("\t\t\t\t\t\tEVENTS THIS WEEKEND\n");
  printf("\n\n\t\t1.Haailand resort\t\t2.Music live\n\n\t\t3.Go Back\n");
  printf("\n\n\t\tEnter your Choice:");
  scanf("%d",&this_week_a);
  if(this_week_a==1)
  {   haailand:
    system("cls");
    title();
    printf("\n\t\t\t\t\tWELCOME TO HAAILAND RESORT......\n");
    printf("\n\t\t1.Book tickets\t\t2.Overview\n\n\t\t3.Go Back");
    printf("\n\t\tEnter ur choice:");
    scanf("%d",&this_week_b);
    if(this_week_b==1)
    {
      printf("\n\t\tDate:\n\t\tSaturday 15  September\n\n\t\tTime:6.00pm\n\n\t\tProceed....");
      printf("\n\t\tSelect ur category...\n");
      printf("\n\t\tAdults\n\t\t500/-\n\t\tEach ticket grants entry to 1 person....\n");
      printf("\n\t\tKids\n\t\t300/-\n\t\tEach ticket grants entry to 1 person....\n");
      printf("\n\n\t\tCONTINUE BOOKING TICKETS?....| 1.YES 2.NO");
      scanf("%d",&econfirm);
      if(econfirm !=1) goto haailand;      
      printf("\n\t\tEnter number of adults and kids:");
      scanf("%d%d",&adult,&kid);

      printf("\n\t\tYou have to pay:%d",(500*adult)+(300*kid));

      printf("\n\n\t\tPROCESSING TRANSACTION PLEASE WAIT...");
      sleep(3);
      transaction();
    }
    else if (this_week_b ==2)
    {
      printf("\n\t\tHaailand grandly welcomes you to the fantastic event.....");
      printf("\n\t\tDiscover an endless combination of thrilling rides,water park,");
      printf("\n\t\tfantastic entertainment,delightful restaurants");
      getch();
      goto haailand;
    }  
    else thisweekend();
  }
  else if (this_week_a==2)
  {     livemusic:  
    system("cls");
    title();
    printf("\n\t\t\t\t\tWELCOME TO LIVE MUSIC.......\n");
    printf("\n\t\t1.Book tickets\t\t2.Overview\n\n\t\t3.Go Back");
    printf("\n\t\tEnter ur choice:");
    scanf("%d",&this_week_b);
    if(this_week_b==1)
    {
      printf("\n\t\tDate:\t\tSaturday 15  September\n\n\t\tTime:3.00pm\n\n\t\tProceed....");
      printf("\n\t\tSelect ur category...\n");
      printf("\n\t\tAdults\n\t\t600/-\n\t\tEach ticket grants entry to 1 person....\n");
      printf("\n\t\tKids\n\t\t500/-\n\t\tEach ticket grants entry to 1 person....\n");
      printf("\n\t\tEnter number of adults and kids:");
      printf("\n\n\t\tCONTINUE BOOKING TICKETS?....| 1.YES 2.NO");
      scanf("%d",&econfirm);
      if(econfirm !=1) goto livemusic;
      scanf("%d%d",&adult,&kid);

      printf("\n\t\tYou have to pay:%d",(600*adult)+(500*kid));
      printf("\n\n\t\tPROCESSING TRANSACTION PLEASE WAIT...");
      sleep(3);
      transaction();

    }

    else if (this_week_b ==2)
    {
      printf("\n\t\tLive music welcomes you....\n");
      printf("\n\t\tImmerse yourself in the world of music....ROCKZZZZZ");
      getch();
      goto livemusic;
    }
    else thisweekend();    
  }
  else if (this_week_a==3) events();
  else {printf("Enter Valid Options !!.."); sleep(1); thisweekend();}
}

