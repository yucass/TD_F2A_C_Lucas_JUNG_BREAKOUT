
// fonction qui initialise le paddle
void paddleFunct(game *myGame,coordonnees *dep, coordonnees *moveball, SDL_Rect *paddleleft ) {

    SDL_Rect rectangleSource;


        myGame->g_surface = IMG_Load("./assets/paddle.png");//Chargement de l'image png

        if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", IMG_GetError());
            // handle error
        }

        if(myGame->g_surface){


                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite

                if(myGame->g_texture){

                    rectangleSource.x=0;//128*(int)((SDL_GetTicks()/100)%6);
                    rectangleSource.y=0;
                    rectangleSource.w=128;//1 image = w:128 et h:82
                    rectangleSource.h=32;

                    SDL_QueryTexture(myGame->g_texture,NULL,NULL,NULL,NULL);

                    paddleleft->x=dep->x;//debut x
                    paddleleft->y=SCREEN_HEIGHT-30;//debut y
                    paddleleft->w=rectangleSource.w;//Largeur
                    paddleleft->h=rectangleSource.h; //Hauteur
                    SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,paddleleft);

                    SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite
                    destroyTexture(myGame);

                }
                 }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }



}

// fonction de creation de la balle
void ballFunct(game *myGame,coordonnees *dep, coordonnees *moveball ) {

    SDL_Rect sourceBall;
    SDL_Rect Ball;

myGame->g_surface = IMG_Load("./assets/ball.png");//Chargement de l'image png

        if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", IMG_GetError());
            // handle error
        }

        if(myGame->g_surface){


                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
                 SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

                if(myGame->g_texture){

                    sourceBall.x=0;//128*(int)((SDL_GetTicks()/100)%6);
                    sourceBall.y=0;
                    sourceBall.w=24;//1 image = w:128 et h:82
                    sourceBall.h=24;

                    SDL_QueryTexture(myGame->g_texture,NULL,NULL,NULL,NULL);

                    Ball.x=moveball->x;//debut x
                    Ball.y=moveball->y;//debut y
                    Ball.w=sourceBall.w;//Largeur
                    Ball.h=sourceBall.h; //Hauteur
                    SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&sourceBall,&Ball);

                SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite
                    destroyTexture(myGame);
                }



                else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }

        }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }
}

// Fonction de creation des murs

void createwall(game *myGame){

    // VARIABLES
    SDL_Rect sourceWallLeft;
    SDL_Rect destWallLeft;
    SDL_Rect sourceWallRight;
    SDL_Rect destWallRight;

    myGame->g_surface = IMG_Load("./assets/side.png");//Chargement de l'image png

    if(!myGame->g_surface) {
        fprintf(stdout,"IMG_Load: %s\n", IMG_GetError());
        }

    if(myGame->g_surface){
        myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
        SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

            if(myGame->g_texture){

                // MUR DE GAUCHE
                sourceWallLeft.x=0;//128*(int)((SDL_GetTicks()/100)%6);
                sourceWallLeft.y=0;
                sourceWallLeft.w=16;//1 image = w:128 et h:82
                sourceWallLeft.h=SCREEN_HEIGHT;

                SDL_QueryTexture(myGame->g_texture,NULL,NULL,NULL,NULL);

                destWallLeft.x=0;//debut x
                destWallLeft.y= 0;
                destWallLeft.w=sourceWallLeft.w;//Largeur
                destWallLeft.h=sourceWallLeft.h; //Hauteur

                SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&sourceWallLeft,&destWallLeft);


                //MUR DE DROITE
                sourceWallRight.x=0;//128*(int)((SDL_GetTicks()/100)%6);
                sourceWallRight.y=0;
                sourceWallRight.w=16;//1 image = w:128 et h:82
                sourceWallRight.h=SCREEN_HEIGHT;

                SDL_QueryTexture(myGame->g_texture,NULL,NULL,NULL,NULL);

                destWallRight.x=SCREEN_WIDTH -16;//debut x
                destWallRight.y= 0;
                destWallRight.w=sourceWallRight.w;//Largeur
                destWallRight.h=sourceWallRight.h; //Hauteur

                SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&sourceWallRight,&destWallRight);

                destroyTexture(myGame);
            }

            else{
                fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }

        }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
            }
}
