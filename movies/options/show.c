struct movies{
    int movie_num;
    char movie_name[40];
    char movie_review[300];
}mvie;
    int now_show_a,now_show_b;
void now_showing(){

    char ch;


    FILE *moviefp; 
    now_show:
    moviefp = fopen("movies/movies.dat","r");
    if (moviefp == NULL)
	{
		fprintf(stderr, "\nError opening file\n");
		exit (1);
	}
    rewind(moviefp);
    system("cls");
    title();
    printf("\t\tLATEST Telugu MOVIES\n\n"); // LIST OF LATEST MOVIES READ FROM FILES
    while(fread(&mvie, sizeof(struct movies), 1, moviefp)){
        printf("\t\t%d.%s\n", mvie.movie_num, mvie.movie_name);
    }   
    fclose(moviefp);
    printf("\n\n\t\t5.Go Back..\n");
    printf("\n\t\tChoose a movie:");
    scanf("%d",&now_show_a);    //  REVIEWS FOR THE MOVIE - FROM FILE
        if(now_show_a == 1) {moviefp = fopen("movies/reviews/1.txt","r");}
        else if(now_show_a == 2) {moviefp = fopen("movies/reviews/2.txt","r");}
        else if(now_show_a == 3) {moviefp = fopen("movies/reviews/3.txt","r");}
        else if(now_show_a == 4) {moviefp = fopen("movies/reviews/4.txt","r");}
        else if(now_show_a == 5) movie();
    printf("\n\t\t1.Book tickets\t\t2.Review\t\t3.Re-Select Movie\n");
    printf("\t\tEnter your option: ");
    scanf(" %d",&now_show_b);
        if(now_show_b == 1) screen();
        else if(now_show_b == 2){
            printf("\n\t\tREVIEW FOR THE MOVIE\n");    
            while((ch = fgetc(moviefp))!=EOF){    
                printf("%c",ch);
            }
            fclose(moviefp);
            getch();
            goto now_show;
    }   
    else goto now_show;


}