#include<bits/stdc++.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
using namespace std;
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

SDL_Window* gWindow = NULL;
SDL_Window* second = NULL;    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gScreenSurface1 = NULL;
//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }

        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
            // gScreenSurface1 = SDL_GetWindowSurface( second);
            // gScreenSurface = SDL_GetWindowSurface( second );
        }
    }

    return success;
}
bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP( "images/second_isometric.bmp" );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/hello_world.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}
void close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    SDL_DestroyWindow(second);
    gWindow = NULL;
    second = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}

void draw(){
    //cout<<"Drawing"<<endl;
    SDL_Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.w = 500;
    rect.h = 500;
    SDL_BlitScaled( gHelloWorld, NULL, gScreenSurface, &rect );
    // SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface1, NULL );
    SDL_UpdateWindowSurface( gWindow );
    // SDL_UpdateWindowSurface( second );
    //cout<<"Waiting"<<endl;
  }

void run(){
    SDL_Event e;
    bool quit = false;
 
    //gCurrentSurface = gKeyPressSurface[surface_total];
    while (!quit){
      while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT){
          quit = true;
        }
    }
    draw();
    }
}

int main(){
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Apply the image
            cout<<"Noe Problem"<<endl;
            run();
        }
    }
    close();
    return 0;
}