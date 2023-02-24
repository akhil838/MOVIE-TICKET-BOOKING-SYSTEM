
int adult,kid,couple;

void events()
{
 int events_a;
 event:
 system("cls");
 title();   
 printf("\t\t\t\t\t\t<- EVENTS ->\n");
 printf("\n\n\t\t1.This weekend\t\t\t\t2.Next weekend\n\n\t\t3.Go Back..\n");
 printf("\n\n\t\tEnter your Choice:");
 scanf("%d",&events_a);
      switch(events_a){
            case 1:thisweekend();break;
            case 2:nextweekend();break;
            case 3: home();
            default: printf("\n\t\tEnter Valid Option: ");goto event;
      }
}

