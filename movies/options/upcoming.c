void upcoming()
{   int up_a;
    system("cls");
    title();
    printf("\t\tUPCOMING Telugu MOVIES");
    printf("\n\n\t\t1.Ant man and wasp quantumania\n\t\t2.Salaar\n\t\t3.SIR\n\t\t4.John wick chapter 4\n\n\t\t5. Go Back....");
    printf("\n\t\tEnter ur choice:");
    scanf("%d",&up_a);
        if(up_a==1)
            {
                printf("\n\t\tMovie name: Ant man and wasp quantumania\n\t\tRelease Date: 17 February, 2023\t\tDuration: 2h 4min\n\n");
                printf("\t\tDirector: Peyton Reed\n\t\tActors: 	Paul Rudd, Evangeline Lilly, Jonathan Majors, Michelle Pfeiffer...\n");
                printf("\n\t\tBooking opens on  12 February 2023");
            }
        else if(up_a==2)
            {
                printf("\n\t\tMovie name: Salaar\n\t\tRelease Date:28 September, 2023\n\n");
                printf("\t\tDirector: Prashanth Neel\n\t\tActors: Prabhas, Shruti Haasan, Jagapathi Babu...\n");
                printf("\n\t\tBooking opens on: To be Announced");
            }
        else if(up_a==3)
            {
                printf("\n\t\tMovie name: SIR\n\t\tRelease Date:17 February, 2023\t\tDuration: 2h 4min\n\n");
                printf("\t\tDirector: Venky Atluri\n\t\tActors: Dhanush, Samyuktha Menon, P. Sai Kumar, Tanikella Bharani...\n");
                printf("\n\t\tBooking opens soon...");
            }
        else if(up_a==4)
            {
                printf("\n\t\tMovie name: John wick chapter 4\n\t\tRelease Date: 24 March 2023\n\n");
                printf("\t\tDirector: Chad Stahelski\n\t\tActors: Keanu Reeves, Donnie Yen, Bill Skarsgard, Laurence Fishburn\n");
                printf("\n\t\tBooking opens on: To be Announced");
            }
        else if(up_a==5){movie();}
        else 
            {
                printf("Enter Valid Option !!..");
            }
    getch();            
    upcoming();
  }

