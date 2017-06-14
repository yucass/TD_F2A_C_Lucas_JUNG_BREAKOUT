
// INITIALISATION DE LA FENETRE ET DE LA SDL

int init(char *title, int xpos,int ypos,int width, int height,int flags,game *myGame, font *mFont){

    myGame->g_pWindow=NULL;
    myGame->g_pRenderer=NULL;
    myGame->g_surface=NULL;
    myGame->g_texture=NULL;

    //initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING)>=0)
        {
        //if succeeded create our window
        myGame->g_pWindow=SDL_CreateWindow(title,xpos,ypos,width,height,flags);

        //if succeeded create window, create our render
        if(myGame->g_pWindow!=NULL){
            myGame->g_pRenderer=SDL_CreateRenderer(myGame->g_pWindow,-1,SDL_RENDERER_PRESENTVSYNC);

            }

    }else
    {return 0;}

    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    mFont->g_font=TTF_OpenFont("./assets/fonts/lucon.ttf",65);

    if(!mFont->g_font) {
        printf("TTF_OpenFont: %s\n", TTF_GetError());
        SDL_Delay(5000);
        exit(EXIT_FAILURE);
        }

    return 1;

}

// INITIALISATION DE LA BALLE
void initmouvementball (coordonnees *dep, coordonnees *moveball, int *directionx, int *directiony, SDL_Rect *paddleleft)
{
    moveball->x= dep->x + RADIUS + paddleleft->h;
    moveball->y= paddleleft->y - RADIUS;
}
