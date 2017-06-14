#ifndef PROTOTYPE_H_INCLUDED
#define PROTOTYPE_H_INCLUDED



#endif // PROTOTYPE_H_INCLUDED


//prototypes

// INITIALISATION
int init(char *title, int xpos,int ypos,int width, int height,int flags,game *myGame, font *mFont);

// DESTRUCTION DE GAME ET SDL
void destroy(game *myGame, font *mFont);

// CONTROLEURS
void handleEvents(gameState *state,coordonnees *dep, coordonnees *moveball, int *launchBall);

//DELAY POUR LE FPS
void delay(unsigned int frameLimit);

// GESTION DU PADDLE
void paddleFunct(game *myGame,coordonnees *dep, coordonnees *moveball, SDL_Rect *paddleleft );

//DEPLACEMENT DE LA BALLE et INIT DE LA BALL
void mouvementball (coordonnees *dep, coordonnees *moveball, int *directionx, int *directiony);
void initmouvementball (coordonnees *dep, coordonnees *moveball, int *directionx, int *directiony, SDL_Rect *paddleleft);

// CREATION DES BLOCS
void createblock ( game *myGame, bloc *cases, SDL_Rect *bloc, int a, int b, int c);

//GESTION DES COLLISIONS
int collision (game *myGame, coordonnees *moveball, int *directionx, int *directiony, bloc *cases, SDL_Rect *paddleleft, int *launchBall, int *playerpoint);


// CREATION DES MURS
void createwall(game *myGame);

//affichage du score
void writeSDL(game *myGame,font mFont, int playerpoint);

// creation de la balle
void ballFunct(game *myGame,coordonnees *dep, coordonnees *moveball );

//message de fin
void writeFinish(game *myGame,font mFont);

//FONCTION DE LA FIN DE JEU
int endgame (game *myGame, bloc *cases);
