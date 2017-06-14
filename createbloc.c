
/* Fonction createbloc - Elle permet l'affichage des blocs.*/
void createblock ( game *myGame, bloc *cases, SDL_Rect *bloc, int a, int b, int c) {

//VARIABLES
    SDL_Rect rectangleSource;
    a, b, c = 0;
    int valColor =0;
    int maxBlocH = 15;// -> NOMBRE DE BLOC EN H
    int maxBlocW = 15;// -> NOMBRE DE BLOC EN W

    // Chargement de l'asset
    myGame->g_surface = IMG_Load("./assets/bricks.png");//Chargement de l'image png
    if(!myGame->g_surface) {
        fprintf(stdout,"IMG_Load: %s\n", IMG_GetError());
        }

    if(myGame->g_surface){
        myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite

        if(myGame->g_texture){
            for (a=0; a<maxBlocW; a++){//affichage des blocs en largeur
                for (b=0; b<maxBlocH; b++){// affichage des blocs en hauteur

                   if (cases[c].alive >= 1){
                        if (valColor == 4){valColor = 0;}
                        if (valColor == 0){
                                rectangleSource.x= 0*64;
                                rectangleSource.y= 0*24;
                                rectangleSource.w=64;
                                rectangleSource.h=24;
                            }
                        else if (valColor == 1){
                                rectangleSource.x= 1*64;
                                rectangleSource.y= 0*24;
                                rectangleSource.w=64;
                                rectangleSource.h=24;
                            }
                        else if (valColor == 2){
                                rectangleSource.x= 0*64;
                                rectangleSource.y= 1*24;
                                rectangleSource.w=64;
                                rectangleSource.h=24;
                            }
                        else if (valColor == 3){
                                rectangleSource.x= 1*64;
                                rectangleSource.y= 1*24;
                                rectangleSource.w=64;
                                rectangleSource.h=24;
                            }
                        SDL_QueryTexture(myGame->g_texture,NULL,NULL,NULL,NULL);

                        // Blit de l'image dans bloc[]. cases[] est utilisé pour les collisions.
                        bloc[c].x = a*64 + (SCREEN_WIDTH-(16*2) - (15*64));
                        cases[c].position.x = bloc[c].x;
                        bloc[c].y = b*24;
                        cases[c].position.y = bloc[c].y;
                        bloc[c].w = 64; //Largeur
                        bloc[c].h = 24; //Hauteur

                        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&bloc[c]);


                        valColor++;
                    }
                            // SI LA VIE DU BLOC EST EGALE A 0 ALORS ON LE RETIRE DU JEU.
                    else {
                        bloc[c].w = 0; bloc[c].h = 0;
                        bloc[c].x=-1000;
                        cases[c].position.x = bloc[c].x;
                        bloc[c].y=-1000;
                        cases[c].position.y = bloc[c].y;
                        }
                    // On increment c qui represente la valeur de bloc[].
                     c++;

                    }
                }

                SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite
                destroyTexture(myGame);
        }
    }

}
