void writeSDL(game *myGame,font mFont, int playerpoint) {

    char score[20];
    sprintf(score, "%d", playerpoint);
    SDL_Color fontColor={255,0,0};

    myGame->g_surface=TTF_RenderText_Blended(mFont.g_font, score, fontColor);//Charge la police

    if(myGame->g_surface){

            //D�finition du rectangle dest pour blitter la chaine
            SDL_Rect rectangle;
            rectangle.x=100;//debut x
            rectangle.y=SCREEN_HEIGHT - 100;//debut y
            rectangle.w=80; //Largeur
            rectangle.h=30; //Hauteur


             myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Pr�paration de la texture pour la chaine
             //SDL_FreeSurface(myGame->g_surface); // Lib�ration de la ressource occup�e par le sprite

             if(myGame->g_texture)
                {SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,NULL,&rectangle);} // Copie du sprite gr�ce au SDL_Renderer
             else
             {fprintf(stdout,"�chec de cr�ation de la texture (%s)\n",SDL_GetError());}

    }else{
        fprintf(stdout,score,SDL_GetError());
    }
    SDL_FreeSurface(myGame->g_surface); // Lib�ration de la ressource occup�e par le sprite
            destroyTexture(myGame);

}

// fonction d'affichage du texte "vous avez gagnez" si tous les bloc sont detruits
void writeFinish(game *myGame,font mFont) {

    SDL_Color fontColor={255,0,0};

    myGame->g_surface=TTF_RenderText_Blended(mFont.g_font, "Vous avez gagnez !!", fontColor);//Charge la police

    if(myGame->g_surface){


            //D�finition du rectangle dest pour blitter la chaine
            SDL_Rect rectangleFin;
            rectangleFin.x=SCREEN_WIDTH/2 - 200;//debut x
            rectangleFin.y=SCREEN_HEIGHT/2 - 50;//debut y
            rectangleFin.w=400; //Largeur
            rectangleFin.h=100; //Hauteur


             myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Pr�paration de la texture pour la chaine
             //SDL_FreeSurface(myGame->g_surface); // Lib�ration de la ressource occup�e par le sprite

             if(myGame->g_texture){

                    SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,NULL,&rectangleFin); // Copie du sprite gr�ce au SDL_Renderer

             }
             else{
                    fprintf(stdout,"�chec de cr�ation de la texture (%s)\n",SDL_GetError());
            }

    }else{
        fprintf(stdout,"Vous avez Gagnez" ,SDL_GetError());
    }
    SDL_FreeSurface(myGame->g_surface); // Lib�ration de la ressource occup�e par le sprite
            destroyTexture(myGame);

}
