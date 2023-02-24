

void movie()
  { 

    int movie_a;
     system("cls");
     title();
     printf("\t\t\t\t\t<-  LATEST MOVIES ONLY  ->\n\n");
     printf("\t\t1.Now Showing\t\t2.Upcoming Movies\n\n\t\t3.Go Back\t\t4.EXIT\n\n");
     printf("\n\t\tEnter Category:");
     scanf("%d",&movie_a);
     switch(movie_a)
    {
	    case 1:now_showing();
		         break;
	    case 2:upcoming();
		         break;
      case 3:home();       
      case 4:exit(0);
      default: {printf("\t\tEnter Valid Option:");sleep(1);movie();}
	  }
   }


