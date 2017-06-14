#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#endif // CONTROL_H_INCLUDED


void handleEvents(gameState *state,coordonnees *dep, coordonnees *moveball, int *launchBall){

    SDL_Event event;
    if(SDL_PollEvent(&event)){
        switch(event.type){ // GESTION DE LA SOURIS
        case SDL_MOUSEMOTION: dep->x = event.motion.x;
                    if (dep->x + 128>=SCREEN_WIDTH-16)
                        dep->x = SCREEN_WIDTH-128-16;
                    else if(dep->x <=16)
                        dep->x = 16;
                    break;



        case SDL_QUIT:
              state->g_bRunning=0;break;
        case SDL_KEYDOWN:
                        switch (event.key.keysym.sym)
                            {
                                case SDLK_ESCAPE: state->g_bRunning=0;break; // PRESS ESCAPE TO QUITE
                                case SDLK_SPACE: *launchBall =1; break; // PRESS SPACE TO LAUNCH THE BALL

                            }
                            break;
                            case SDL_KEYUP:break;
                            default:break;
        }

    }

}

void mouvementball (coordonnees *dep, coordonnees *moveball, int *directionx, int *directiony)
{
    // methode de deplacement de la balle, pas totalement efficace car il manque une vitesse et un angle en float
    moveball->x= moveball->x + (*directionx * 4);
    moveball->y= moveball->y+ (*directiony * 4);
}
