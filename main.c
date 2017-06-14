#include "header.h"
#include "struct.h"
#include "prototype.h"


int main(int argc, char *argv[])
{
    // variable du jeu
     game myGame;
     gameState state;
     unsigned int frameLimit = SDL_GetTicks() + 16;
     font mFont;
     state.g_bRunning=1;

     // variable des blocs et du paddle
     bloc cases[1500];
     SDL_Rect bloc[1500];
     SDL_Rect paddleleft;

    // variable de deplacement
     coordonnees dep; // paddle
     coordonnees moveball; // ball
     int directionx =-1; // direction en X
     int directiony = -1; // direction en Y

     //position intial de la balle
     moveball.x =  SCREEN_WIDTH/2-10;
     moveball.y = SCREEN_HEIGHT/2-10;


     int playerpoint = 0;
     int launchBall = 0;
     int a, b, c = 0;

     //initialisation de la vie des bloc
     int life = 0;
     for (life = 0; life < NBRBLOC; life++){cases[life].alive = 1;}





    init("BREAKOUT!!",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame, &mFont);
    SDL_Delay(100);

    while(state.g_bRunning){

            handleEvents(&state,&dep, &moveball, &launchBall); // => CONTROLLEUR
            createblock ( &myGame, &cases, &bloc, a, b, c); // => AFFICHAGE BLOCS
            paddleFunct(&myGame,&dep,&moveball, &paddleleft ); // => AFFICHAGE PADDLE
            ballFunct(&myGame,&dep,&moveball ); // => AFFICHAGE BALL
            createwall(&myGame); // => AFFICHAGE WALL

            if (launchBall){
                mouvementball ( &dep, &moveball, &directionx, &directiony);
                }
            else {initmouvementball ( &dep, &moveball, &directionx, &directiony, &paddleleft);}


            collision (&myGame, &moveball, &directionx, &directiony, &cases, &paddleleft, &launchBall, &playerpoint); // => COLLISION
            writeSDL( &myGame, mFont, playerpoint); // => AFFICHAGE DU SCORE

            if (endgame(&myGame, &cases)==0){
                writeFinish(&myGame,mFont); // => MESSAGE DE FIN
                }

            SDL_RenderPresent(myGame.g_pRenderer);
             SDL_SetRenderDrawColor(myGame.g_pRenderer,0,0,0,255);
             SDL_RenderClear(myGame.g_pRenderer);

             // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
            delay(frameLimit);
            frameLimit = SDL_GetTicks() + 16;
        }

    destroy(&myGame, &mFont);

    SDL_Quit();
    TTF_Quit();


    return 0;
}

#include "collision.c"
#include "init.c"
#include "createbloc.c"
#include "control.c"
#include "globalfunction.c"
#include "texte.c"
#include "endgame.c"
#include "padballwall.c"
