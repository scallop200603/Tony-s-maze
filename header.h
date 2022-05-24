#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer, const int SCREEN_WIDTH, const int SCREEN_HEIGHT,const string WINDOW_TITLE);

void logSDLError(ostream& os, const string &msg, bool fatal = false);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);

bool CrashInto(int x, int y, int w, int h, int ox, int oy, int ow, int oh);

void setColor(SDL_Renderer* renderer, string s);

void GetScreenOpen(SDL_Renderer* renderer);

void GetScreenLose(SDL_Renderer* renderer);

void GetScreenWin(SDL_Renderer* renderer);

