#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED



#endif // STRUCT_H_INCLUDED


typedef struct game{
     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_texture;
     SDL_Surface *g_surface;

}game;

typedef struct gameState{

    int g_bRunning;
    int left;
    int right;


}gameState;


typedef struct coordonnees{

    int x;
    int y;

}coordonnees;

typedef struct font{

    TTF_Font *g_font;

}font;

typedef struct bloc{
    coordonnees position;
    int alive;

}bloc;


typedef int bool;
#define true 1
#define false 0
