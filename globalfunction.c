// This file is use to stock all mandatory function.
// they have no modification during the programmation or the process of the game




void delay(unsigned int frameLimit){
    // Gestion des 60 fps (images/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}



void destroyTexture(game *myGame){


    //Destroy texture
    if(myGame->g_texture!=NULL)
            SDL_DestroyTexture(myGame->g_texture);

}

void destroy(game *myGame, font *mFont){

      //Destroy render
     if(myGame->g_pRenderer!=NULL)
        SDL_DestroyRenderer(myGame->g_pRenderer);

      //Destroy texture
     if(myGame->g_texture!=NULL)
        SDL_DestroyTexture(myGame->g_texture);

    //Destroy surface
     if(myGame->g_surface!=NULL)
         SDL_FreeSurface(myGame->g_surface);

    //Destroy window
    if(myGame->g_pWindow!=NULL)
        SDL_DestroyWindow(myGame->g_pWindow);

}
