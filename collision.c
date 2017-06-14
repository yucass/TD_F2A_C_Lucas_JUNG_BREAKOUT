
int collision (game *myGame, coordonnees *moveball, int *directionx, int *directiony, bloc *cases, SDL_Rect *paddleleft, int *launchBall, int *playerpoint){
    int valNum = 0;


// COLLISION DE LA BALLE SUR LES MURS

    // MUR DROIT
    if (moveball->x + RADIUS >= SCREEN_WIDTH -16){
        *directionx = -1;
    }
    // MUR GAUCHE
     if (moveball->x <= 16){
        *directionx = 1;
    }
    // MUR HAUT
      if (moveball->y <= 0){
        *directiony = 1;
    }
    // MUR BAS --> FAIT PERDRE 50 POINTS et REINITIALISE LAUNCHBALL
    if (moveball->y >= SCREEN_HEIGHT){
        *launchBall =0;
        *playerpoint -=50;

    }



// COLISIONS DE LA BALLE SUR LA RAQUETE

    if (moveball->y + RADIUS >= paddleleft->y){
        if (moveball->x >= paddleleft->x + 20){
            if (moveball->x <= paddleleft->x +100){
                *directiony = -1;
            }
        }
    }

    if (moveball->y + RADIUS >= paddleleft->y){
        if (moveball->x >= paddleleft->x){
            if (moveball->x <= paddleleft->x +20){
                *directiony = -1;
                *directionx = -1;
            }
        }
    }

    if (moveball->y + RADIUS >= paddleleft->y){
        if (moveball->x >= paddleleft->x+100){
            if (moveball->x <= paddleleft->x +120){
                *directiony = -1;
                *directionx = 1;
            }
        }
    }


// COLISION DES BLOCS

    for (valNum=0;valNum<226; valNum++){

        if (cases[valNum].alive == 1){

            // COLLISION BAS
            if ((moveball->y  == cases[valNum].position.y + BLOC_H)|| (moveball->y  == cases[valNum].position.y + BLOC_H -1)){
                if (moveball->x >= cases[valNum].position.x){
                    if (moveball->x <= cases[valNum].position.x + BLOC_W){
                        printf("collision");
                        *directiony = 1;
                        cases[valNum].alive -=1;
                        *playerpoint += 10;
                    }
                }
            }

            // COLLISION HAUT
            else if ((moveball->y + RADIUS == cases[valNum].position.y) || (moveball->y + RADIUS == cases[valNum].position.y + 1)){
                if (moveball->x >= cases[valNum].position.x){
                    if (moveball->x <= cases[valNum].position.x + BLOC_W){
                        printf("collision");
                        *directiony = -1;
                        cases[valNum].alive -=1;
                        *playerpoint += 10;

                    }
                }
            }

            // COLLISION GAUCHE
            else if (moveball->x + RADIUS == cases[valNum].position.x){
                if (moveball->y >= cases[valNum].position.y){
                   if (moveball->y <= cases[valNum].position.y + BLOC_H){
                        *directionx = -1;printf("collision");
                        cases[valNum].alive -=1;
                        *playerpoint += 10;
                    }
                }
            }

            // COLLISION DROITE
            else if (moveball->x  == cases[valNum].position.x + BLOC_W){
                if (moveball->y >= cases[valNum].position.y){
                    if (moveball->y <= cases[valNum].position.y){
                       *directionx = -1;printf("collision");
                       cases[valNum].alive -=1 ;
                       *playerpoint += 10;
                        }
                    }
                }


        }
    }

    return 0;
}




