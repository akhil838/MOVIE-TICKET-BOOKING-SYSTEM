
struct seats{
    char seat_chr;
    int seat_num;
}s,booked,tmp[100];
    
extern int now_show_a,now_show_b;
extern int amount;
void reset_seats();
extern FILE* screenfp;

extern FILE* r_seat_fp(int,int,int,int);
extern int num,n1,rname,i,t,x,mode,booking;
extern int n,a,theater,movie_time,snack;
extern char ch;
int num_ticket;
extern char selected_theater[50];



void screen(){
x =0;
a =0;
start:
    num_ticket = 0;
    amount = 0;
    system("cls");
    title();
    printf("\n\t\t\t\t<-   Theaters Available:    ->");
    printf("\n\n\t\t1.INOX GSM Mall,Madeenaguda\t\t2.INOX Maheshwari Parmeshwari Mall,Kachiguda\n\n\t\t3.INOX GVK One,Banjara Hills\t\t4.INOX Sattva Necklace Mall, Kavadiguda\n\n\n\t\t5.Go Back..");
    printf("\n\t\tChoose The Nearest Theater: "); 

    scanf("%d",&theater);
    if(theater == 1) strcpy(selected_theater , "INOX GSM Mall,Madeenaguda");
    if(theater == 2) strcpy(selected_theater , "INOX Maheshwari Parmeshwari Mall,Kachiguda"); 
    if(theater == 3) strcpy(selected_theater , "INOX GVK One,Banjara Hills");
    if(theater == 4) strcpy(selected_theater , "INOX Sattva Necklace Mall, Kavadiguda");
    if(theater == 5)
    now_showing();
    printf("\n\t\t\t\t<-      SHOW TIMINGS    ->\n");
    printf("\n\t\t1.Afternoon\t(12:00 PM)\n\t\t2.Evening\t(06:00 PM)\n\t\t3.Night\t\t(09:00 PM)\n\n\t\t4.Reselect Theater..");
    printf("\n\t\tEnter Your Choice: ");

    scanf("%d",&movie_time);
    if(movie_time == 4)
    goto start;
    sleep(1);
    // SEAT MATRIX
    screenfp = r_seat_fp(theater,movie_time,now_show_a,0); 
    system("cls");
    title();
    matrix(screenfp);
    printf("\tDO YOU WANT TO CONTINUE BOOKING ?...\n\t\t1.YES\t\t2.NO(Go Back)");
    scanf("%d",&booking);
    if(booking != 1) now_showing();

    system("cls");
    title();
    matrix(screenfp);
    printf("\n\t\tENTER THE SEAT NUMBERS THAT YOU WANT TO BOOK (press 00 to stop): ");
    printf("");
    fclose(screenfp);
    

screenfp = r_seat_fp(theater,movie_time,now_show_a,1);
while(1){
scanf(" %c%d", &booked.seat_chr, &booked.seat_num);
t = 100;
x = 0;
    while(t--){ // LINEAR SEARCH
        if((tmp[t].seat_chr == booked.seat_chr) && (tmp[t].seat_num == booked.seat_num)){
            if(booked.seat_chr >='G' && booked.seat_chr <='J') amount+=450;  
            if(booked.seat_chr >='D' && booked.seat_chr <='F') amount+=370; 
            if(booked.seat_chr >='A' && booked.seat_chr <='C') amount+=250; 
            x =1;
            num_ticket++;
            break;
        }
    }
if(booked.seat_chr =='0' && booked.seat_num == 0) goto out;    
if(x == 0 || (booked.seat_chr == '.' && booked.seat_num == 0)){ // PROMT THE USER IF THE SEAT IS INVALID OR ALREADY BOOKED
    printf("\t\tThe Selected Seat %c%d is already booked!! OR INVALID",booked.seat_chr,booked.seat_num);
    printf("\n\t\tSelect a Valid Seat.\n\n\t\tEnter Seat Numbers: ");
}
else if(x==1)
{
    tmp[t].seat_chr = '.';
    tmp[t].seat_num = 0 ;
}
}
out:    //  WRITING BACK TO FILE
    for ( t = 0; t <100; t++)
    {
    fwrite(&tmp[t],sizeof(struct seats),1,screenfp);
    }
fclose(screenfp);
system("cls");
title();
printf("\n\t\t\t\tSNACKS TIME:");
 printf("\n\t\t1.Coke                                          Cost:179");
 printf("\n\t\t2.Pepsi                                         Cost:179");
 printf("\n\t\t3.Popcorn                                       Cost:199");
 printf("\n\t\t4.Combo(Popcorn + Coke)                         Cost:359"); 
 printf("\n\t\t5.French Fries                                  Cost:149");
 printf("\n\t\t6.Burger                                        Cost:199");
 printf("\n\t\t7.Combo(Burger + Coke/Pepsi + Popcorn)          Cost:550");
 printf("\n\t\t8.Combo(Burger + Coke/Pepsi + French Fries)     Cost:520");
 printf("\n\t\t9.Water Bottle                                  Cost:60");
 printf("\n\n\t\t10.NOTHING ELSE...!");
 printf("\n\n\t\tEnter your choices: ");
 do{
 scanf("%d",&snack);
 if(snack==1 || snack==2)
    amount+=179;
 else if(snack==3 || snack == 6)
   amount+=199;
 else if(snack==4)
   amount+=359;
 else if(snack==5)
   amount+=149; 
 else if(snack==7)
   amount+=550; 
 else if(snack==8)
   amount+=520;   
 else if(snack==9)
   amount+=60;         
 else{
   if(snack!=10) 
   printf("Invalid option:");
   }}while(snack != 10);

sleep(1);


if(amount == 0){
printf("\n\t\tNOTHING BOOKED GOING BACK TO MOVIES...");
sleep(2);
now_showing();
}

printf("\t\tTotal Amount = %d",amount);
printf("\t\tPROCESSING TRANSACTION PLEASE WAIT!!...");
sleep(4);
transaction(1);

getch();
}


void reset_seats(){
    FILE* reset[48];
    //MOVIE 1
    int x,num,t;
    char ch;

    reset[0] =  fopen("screen/m1_t1_s1.dat","w");    
    reset[1] =  fopen("screen/m1_t1_s2.dat","w");
    reset[2] =  fopen("screen/m1_t1_s3.dat","w");

    reset[3] =  fopen("screen/m1_t2_s1.dat","w");
    reset[4] =  fopen("screen/m1_t2_s2.dat","w");
    reset[5] =  fopen("screen/m1_t2_s3.dat","w");
    
    reset[6] =  fopen("screen/m1_t3_s1.dat","w");
    reset[7] =  fopen("screen/m1_t3_s2.dat","w");
    reset[8] =  fopen("screen/m1_t3_s3.dat","w");
   
    reset[9] =  fopen("screen/m1_t4_s1.dat","w");
    reset[10] = fopen("screen/m1_t4_s2.dat","w");
    reset[11] = fopen("screen/m1_t4_s3.dat","w");
    
    //MOVIE 2 
    reset[12] = fopen("screen/m2_t1_s1.dat","w");
    reset[13] = fopen("screen/m2_t1_s2.dat","w");
    reset[14] = fopen("screen/m2_t1_s3.dat","w");
    
    reset[15] = fopen("screen/m2_t2_s1.dat","w");
    reset[16] = fopen("screen/m2_t2_s2.dat","w");
    reset[17] = fopen("screen/m2_t2_s3.dat","w");
   
    reset[18] = fopen("screen/m2_t3_s1.dat","w");
    reset[19] = fopen("screen/m2_t3_s2.dat","w");
    reset[20] = fopen("screen/m2_t3_s3.dat","w");
    
    reset[21] = fopen("screen/m2_t4_s1.dat","w");
    reset[22] = fopen("screen/m2_t4_s2.dat","w");
    reset[23] = fopen("screen/m2_t4_s3.dat","w");

    //MOVIE 3 

    reset[24] = fopen("screen/m3_t1_s1.dat","w");
    reset[25] = fopen("screen/m3_t1_s2.dat","w");
    reset[26] = fopen("screen/m3_t1_s3.dat","w");
    
    reset[27] = fopen("screen/m3_t2_s1.dat","w");
    reset[28] = fopen("screen/m3_t2_s2.dat","w");
    reset[29] = fopen("screen/m3_t2_s3.dat","w");
    
    reset[30] = fopen("screen/m3_t3_s1.dat","w");
    reset[31] = fopen("screen/m3_t3_s2.dat","w");
    reset[32] = fopen("screen/m3_t3_s3.dat","w");
    
    reset[33] = fopen("screen/m3_t4_s1.dat","w");
    reset[34] = fopen("screen/m3_t4_s2.dat","w");
    reset[35] = fopen("screen/m3_t4_s3.dat","w");

    //MOVIE 4   

    reset[36] = fopen("screen/m4_t1_s1.dat","w");
    reset[37] = fopen("screen/m4_t1_s2.dat","w");
    reset[38] = fopen("screen/m4_t1_s3.dat","w");
    
    reset[39] = fopen("screen/m4_t2_s1.dat","w");
    reset[40] = fopen("screen/m4_t2_s2.dat","w");
    reset[41] = fopen("screen/m4_t2_s3.dat","w");
    
    reset[42] = fopen("screen/m4_t3_s1.dat","w");
    reset[43] = fopen("screen/m4_t3_s2.dat","w");
    reset[44] = fopen("screen/m4_t3_s3.dat","w");
    
    reset[45] = fopen("screen/m4_t4_s1.dat","w");
    reset[46] = fopen("screen/m4_t4_s2.dat","w");
    reset[47] = fopen("screen/m4_t4_s3.dat","w");
    

    t =99;
    for(ch='J';ch>='A';ch--){
        for(num = 1;num<=10;num++){
            tmp[t].seat_chr = ch;
            tmp[t].seat_num = num;
            t--;
        }    
    }

    for ( x = 0; x<48; x++){
        for ( t = 99; t >=0; t--)
        {
            fwrite(&tmp[t],sizeof(struct seats),1,reset[x]);
        }
        fclose(reset[x]);
    }
}

FILE* r_seat_fp(int theater,int movie_time,int now_show_a,int mode){
    FILE* seat_fp;
//  READ FUNCTION     
    //  THEATER 1 AFTERNOON
    if(theater == 1 && movie_time == 1 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t1_s1.dat","r");}    
    if(theater == 1 && movie_time == 1 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t1_s1.dat","r");} 
    if(theater == 1 && movie_time == 1 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t1_s1.dat","r");}
    if(theater == 1 && movie_time == 1 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t1_s1.dat","r");}
    // THEATER 1 EVENING
    if(theater == 1 && movie_time == 2 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t1_s2.dat","r");}
    if(theater == 1 && movie_time == 2 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t1_s2.dat","r");}
    if(theater == 1 && movie_time == 2 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t1_s2.dat","r");}
    if(theater == 1 && movie_time == 2 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t1_s2.dat","r");}
    //  THEATER 1 NIGHT
    if(theater == 1 && movie_time == 3 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t1_s3.dat","r");}
    if(theater == 1 && movie_time == 3 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t1_s3.dat","r");}
    if(theater == 1 && movie_time == 3 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t1_s3.dat","r");}
    if(theater == 1 && movie_time == 3 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t1_s3.dat","r");}

    //  THEATER 2 AFTERNOON
    if(theater == 2 && movie_time == 1 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t2_s1.dat","r");}
    if(theater == 2 && movie_time == 1 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t2_s1.dat","r");}
    if(theater == 2 && movie_time == 1 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t2_s1.dat","r");}
    if(theater == 2 && movie_time == 1 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t2_s1.dat","r");}
    // THEATER 2 EVENING
    if(theater == 2 && movie_time == 2 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t2_s2.dat","r");}
    if(theater == 2 && movie_time == 2 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t2_s2.dat","r");}
    if(theater == 2 && movie_time == 2 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t2_s2.dat","r");}
    if(theater == 2 && movie_time == 2 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t2_s2.dat","r");}
    //  THEATER 2 NIGHT
    if(theater == 2 && movie_time == 3 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t2_s3.dat","r");}
    if(theater == 2 && movie_time == 3 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t2_s3.dat","r");}
    if(theater == 2 && movie_time == 3 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t2_s3.dat","r");}
    if(theater == 2 && movie_time == 3 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t2_s3.dat","r");}


    //  THEATER 3 AFTERNOON    
    if(theater == 3 && movie_time == 1 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t3_s1.dat","r");}
    if(theater == 3 && movie_time == 1 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t3_s1.dat","r");}
    if(theater == 3 && movie_time == 1 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t3_s1.dat","r");}
    if(theater == 3 && movie_time == 1 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t3_s1.dat","r");}
    // THEATER 3 EVENING
    if(theater == 3 && movie_time == 2 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t3_s2.dat","r");}
    if(theater == 3 && movie_time == 2 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t3_s2.dat","r");}
    if(theater == 3 && movie_time == 2 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t3_s2.dat","r");}
    if(theater == 3 && movie_time == 2 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t3_s2.dat","r");}
    //  THEATER 3 NIGHT
    if(theater == 3 && movie_time == 3 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t3_s3.dat","r");}
    if(theater == 3 && movie_time == 3 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t3_s3.dat","r");}
    if(theater == 3 && movie_time == 3 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t3_s3.dat","r");}
    if(theater == 3 && movie_time == 3 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t3_s3.dat","r");}


    //  THEATER 4 AFTERNOON
    if(theater == 4 && movie_time == 1 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t4_s1.dat","r");}
    if(theater == 4 && movie_time == 1 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t4_s1.dat","r");}
    if(theater == 4 && movie_time == 1 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t4_s1.dat","r");}
    if(theater == 4 && movie_time == 1 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t4_s1.dat","r");}
    // THEATER 4 EVENING
    if(theater == 4 && movie_time == 2 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t4_s2.dat","r");}
    if(theater == 4 && movie_time == 2 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t4_s2.dat","r");}
    if(theater == 4 && movie_time == 2 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t4_s2.dat","r");}
    if(theater == 4 && movie_time == 2 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t4_s2.dat","r");}
    //  THEATER 4 NIGHT
    if(theater == 4 && movie_time == 3 && now_show_a == 1 && mode == 0) {seat_fp = fopen("screen/m1_t4_s3.dat","r");}
    if(theater == 4 && movie_time == 3 && now_show_a == 2 && mode == 0) {seat_fp = fopen("screen/m2_t4_s3.dat","r");}
    if(theater == 4 && movie_time == 3 && now_show_a == 3 && mode == 0) {seat_fp = fopen("screen/m3_t4_s3.dat","r");}
    if(theater == 4 && movie_time == 3 && now_show_a == 4 && mode == 0) {seat_fp = fopen("screen/m4_t4_s3.dat","r");}
    
//  WRITE FUNCTION    
    //  THEATER 1 AFTERNOON
    if(theater == 1 && movie_time == 1 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t1_s1.dat","w");}    
    if(theater == 1 && movie_time == 1 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t1_s1.dat","w");} 
    if(theater == 1 && movie_time == 1 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t1_s1.dat","w");}
    if(theater == 1 && movie_time == 1 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t1_s1.dat","w");}
    // THEATER 1 EVENING
    if(theater == 1 && movie_time == 2 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t1_s2.dat","w");}
    if(theater == 1 && movie_time == 2 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t1_s2.dat","w");}
    if(theater == 1 && movie_time == 2 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t1_s2.dat","w");}
    if(theater == 1 && movie_time == 2 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t1_s2.dat","w");}
    //  THEATER 1 NIGHT
    if(theater == 1 && movie_time == 3 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t1_s3.dat","w");}
    if(theater == 1 && movie_time == 3 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t1_s3.dat","w");}
    if(theater == 1 && movie_time == 3 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t1_s3.dat","w");}
    if(theater == 1 && movie_time == 3 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t1_s3.dat","w");}

    //  THEATER 2 AFTERNOON
    if(theater == 2 && movie_time == 1 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t2_s1.dat","w");}
    if(theater == 2 && movie_time == 1 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t2_s1.dat","w");}
    if(theater == 2 && movie_time == 1 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t2_s1.dat","w");}
    if(theater == 2 && movie_time == 1 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t2_s1.dat","w");}
    // THEATER 2 EVENING
    if(theater == 2 && movie_time == 2 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t2_s2.dat","w");}
    if(theater == 2 && movie_time == 2 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t2_s2.dat","w");}
    if(theater == 2 && movie_time == 2 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t2_s2.dat","w");}
    if(theater == 2 && movie_time == 2 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t2_s2.dat","w");}
    //  THEATER 2 NIGHT
    if(theater == 2 && movie_time == 3 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t2_s3.dat","w");}
    if(theater == 2 && movie_time == 3 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t2_s3.dat","w");}
    if(theater == 2 && movie_time == 3 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t2_s3.dat","w");}
    if(theater == 2 && movie_time == 3 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t2_s3.dat","w");}


    //  THEATER 3 AFTERNOON    
    if(theater == 3 && movie_time == 1 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t3_s1.dat","w");}
    if(theater == 3 && movie_time == 1 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t3_s1.dat","w");}
    if(theater == 3 && movie_time == 1 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t3_s1.dat","w");}
    if(theater == 3 && movie_time == 1 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t3_s1.dat","w");}
    // THEATER 3 EVENING
    if(theater == 3 && movie_time == 2 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t3_s2.dat","w");}
    if(theater == 3 && movie_time == 2 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t3_s2.dat","w");}
    if(theater == 3 && movie_time == 2 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t3_s2.dat","w");}
    if(theater == 3 && movie_time == 2 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t3_s2.dat","w");}
    //  THEATER 3 NIGHT
    if(theater == 3 && movie_time == 3 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t3_s3.dat","w");}
    if(theater == 3 && movie_time == 3 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t3_s3.dat","w");}
    if(theater == 3 && movie_time == 3 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t3_s3.dat","w");}
    if(theater == 3 && movie_time == 3 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t3_s3.dat","w");}


    //  THEATER 4 AFTERNOON
    if(theater == 4 && movie_time == 1 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t4_s1.dat","w");}
    if(theater == 4 && movie_time == 1 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t4_s1.dat","w");}
    if(theater == 4 && movie_time == 1 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t4_s1.dat","w");}
    if(theater == 4 && movie_time == 1 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t4_s1.dat","w");}
    // THEATER 4 EVENING
    if(theater == 4 && movie_time == 2 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t4_s2.dat","w");}
    if(theater == 4 && movie_time == 2 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t4_s2.dat","w");}
    if(theater == 4 && movie_time == 2 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t4_s2.dat","w");}
    if(theater == 4 && movie_time == 2 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t4_s2.dat","w");}
    //  THEATER 4 NIGHT
    if(theater == 4 && movie_time == 3 && now_show_a == 1 && mode == 1) {seat_fp = fopen("screen/m1_t4_s3.dat","w");}
    if(theater == 4 && movie_time == 3 && now_show_a == 2 && mode == 1) {seat_fp = fopen("screen/m2_t4_s3.dat","w");}
    if(theater == 4 && movie_time == 3 && now_show_a == 3 && mode == 1) {seat_fp = fopen("screen/m3_t4_s3.dat","w");}
    if(theater == 4 && movie_time == 3 && now_show_a == 4 && mode == 1) {seat_fp = fopen("screen/m4_t4_s3.dat","w");}
  
    return seat_fp;
}

void matrix(FILE* screenfp){

    int i;
    printf("\t\t\t\t\t<-  AVAILABLE SEATS  ->\n");
    printf("\n\t  |-----------------------------------------------------------------------------------------|\n");
    printf("\t--->\t");
    i = 0;
       
    while(fread(&s,sizeof(struct seats),1,screenfp)){
        
        if(i%10 ==0) printf("\n\n\t");
        if(i==70) printf("\t\t\t\t\t<---EXECUTIVE---> | Rs.250 |\n\t");
        if(i==40) printf("\t\t\t\t\t<---PREMIERE--->  | Rs.370 |\n\t");
        if(i==0) printf("\t\t\t\t\t <---SILVER--->   | Rs.450 |\n\t");
        tmp[i].seat_chr = s.seat_chr;
        tmp[i].seat_num = s.seat_num;
        i++;
        printf("\t[ %c%d ]",s.seat_chr,s.seat_num);
    }
    rewind(screenfp);
       
    printf("\n\n\n\n\n\n\t|                    |-------------------|ALL EYES THIS SIDE|---------------------|               |\n\n\n");
}