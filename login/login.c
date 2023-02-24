struct users
{
   char uname[15];
   char upass[10];
   char name[15];
   char location[20];
   char ph_num[11];
};

// Driver program
int login ()
{
	FILE *ufp;
	struct users u;
   int x,s_cmp,login_user,result=0;
	char usr_name[15];
   char usr_pass[10];
   start:
   ufp = fopen ("login/users.dat", "a+");

   system("cls");
   title();
   printf("\t\t\t\t\t<--- LOGIN / SIGN UP --->\n\n");
   printf("\t\t1.Existing User\n\n\t\t2.New User(Register Now)\n\n\t\t3.EXIT\n");
   printf("\n\n\t\tEnter Your Choice: ");
   scanf("%d",&login_user);


   if(login_user == 1){
   exe_user:   
   system("cls");
   title();
   printf("\t\t\t\t\t\t<--- LOGIN --->\n\n");
   rewind(ufp);
   x =3;
	printf("\n\n\t\tENTER USER NAME: ");
   scanf(" %s",usr_name);
	while(fread(&u, sizeof(struct users), 1, ufp)){ 
      if((s_cmp = strcmp(usr_name,u.uname))==0){
         result = 1; // LINEAR SEARCHING FOR USERNAME
         while(x--){
            printf("\n\t\tEnter Password: ");   
            scanf(" %s",usr_pass);  // CHECKING IF PASSWORD MATCHES
            if((strcmp(usr_pass,u.upass))==0){  
               printf("\n\n\t\tlogin successful!!..\n");
               sleep(2);   
               home();  //SUCCESSFULL LOGIN
               break;
            }
            else {
               printf("\n\n\t\tTry again");  // MAX 3 TRIES for INCORRECT PASSWORD
               printf("\n\t\t%d Attempts Remaining\n",x);
            }
            }
            if(x == -1) {
               printf("\n\t\tToo many attempts\n");
               sleep(1);   // RETURNS TO LOGIN PAGE IF MAX_TRIES ARE EXAUSTED
            goto start;
         }
      }  
   }
   if(result == 0){
      printf("\n\n\t\tUSER NAME DOES NOT EXITS\n");
      sleep(1);   // RETURNS TO LOGIN PAGE IF USERNAME DOESN'T EXIST IN DATABASE
      goto start; 
   }
   }

   else if(login_user == 2){
   new_user:
   system("cls");
   title();
   printf("\t\t\t\t\t<--- SIGN UP --->\n\n");
   //Entering Data
   printf("\n\n\t\tEnter USER NAME: ");scanf("%s",usr_name);
   // SEEING IF USERNAME ALREADY EXISTS
   while(fread(&u, sizeof(struct users), 1, ufp)){
      if((strcmp(usr_name,u.uname))==0){  // LINEAR SEARCHING FOR USERNAME
         printf("\n\n\t\tUSER already Exists\n\t\t\t(press any key to continue)");
         getch();
         goto start;
   }
   }
   // GATHERING DETAILS OF USER
   printf("\n\t\tEnter NAME: ");scanf(" %[^\n]",u.name);
   printf("\n\t\tEnter MOBILE NUMBER: ");scanf("%s",u.ph_num);
   do{  
      printf("\n\n\t\tEnter PASSWORD: ");scanf("%s",u.upass);
      printf("\n\t\tPlease Re-Enter the PASSWORD: ");scanf("%s",usr_pass);
      if((strcmp(u.upass,usr_pass))!=0)   // CONFIRMATION OF PASSWORD
         printf("\n\t\tPASSWORD Mis-Matched\n");
   }while((strcmp(u.upass,usr_pass))!=0);
   
   strcpy(u.uname,usr_name);

   // WRITING USER-DATA TO DATA BASE
   fwrite (&u, sizeof(struct users), 1, ufp);   
   fclose(ufp);

   printf("\t\t\t\tTHANK YOU FOR SIGNING UP\n\t\t\t\t(press any key to continue)");
   getch(); // RETURN TO LOGIN PAGE
   goto start;
   }
   else if(login_user == 3)
   exit(0);


}
