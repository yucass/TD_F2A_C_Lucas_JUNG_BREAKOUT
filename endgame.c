
// fonction qui test tous les point de vie des cases si tous sont a 0 PV la fonction retourne 0 et affiche le message de fin
int endgame (game *myGame, bloc *cases){

    int valCases =0;
    int addlife = 0;

    for (valCases = 0; valCases <= NBRBLOC; valCases++){
        if (cases[valCases].alive >= 1){
            addlife +=1;
        }
        if (addlife >= 1){

            return 1;
        }
        else {return 0;}
    }

}
