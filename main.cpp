#include <iostream>
#include <SDL2/SDL.h>
#include "header.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>

using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "TONY'S MAZE";

struct Icon
{
    int x = 25, y = 2, h, w;
    Icon(int _h, int _w) : h(_h), w(_w)
    {

    }
    void render(SDL_Renderer* renderer)
    {
        SDL_Rect newIcon;
        newIcon.h = h;
        newIcon.w = w;
        newIcon.x = x;
        newIcon.y = y;
        SDL_Texture* picture = loadTexture("61zEQWk7LtL-removebg-preview.png", renderer);
        SDL_RenderCopy(renderer, picture, NULL, &newIcon);
    }

    void turnLeft()
    {
        x -= 20;
        y -= 0;
    }
    void turnRight()
    {
        x += 20;
        y +=  0;
    }
    void turnUp()
    {
        x -= 0;
        y -= 20;
    }
    void turnDown()
    {
        x += 0;
        y += 20;
    }
};
struct Wall
{
    int x, y, h, w;
    Wall(int _x, int _y, int _h, int _w) : x(_x), y(_y), h(_h), w(_w)
    {

    }
    Wall()
    {

    }
    void render(SDL_Renderer* renderer)
    {
        SDL_Rect object;
        object.h = h;
        object.w = w;
        object.x = x;
        object.y = y;
        setColor(renderer, "Coral");
        SDL_RenderFillRect(renderer, &object);
    }
};

struct Obstacle
{
    int x, y, h, w;
    Obstacle(int _x, int _y, int _h, int _w) : x(_x), y(_y),h(_h), w(_w)
    {

    }
    Obstacle()
    {

    }
    void render(SDL_Renderer* renderer)
    {
        SDL_Rect rectangle;
        rectangle.h = h;
        rectangle.w = w;
        rectangle.x = x;
        rectangle.y = y;
        setColor(renderer, "Coral");
        SDL_RenderFillRect(renderer, &rectangle);
    }
};

int main(int argc, char** argv)
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    Icon icon(25, 25);

    const int max_wall = 4;

    Wall w[max_wall];

    w[0] = Wall(1, 1, 600, 20);

    w[1] = Wall(60, 1, 20, 960);

    w[2] = Wall(980, 20, 580, 20);

    w[3] = Wall(20, 580, 20, 900);

    const int max_obstacle = 59;

    Obstacle o[max_obstacle];

    o[0] = Obstacle (20, 220, 5, 100);

    o[1] = Obstacle (250, 20, 150, 5);

    o[2] = Obstacle (470, 20, 100, 5);

    o[3] = Obstacle (350, 360, 120, 5);

    o[4] = Obstacle (580, 480, 100, 5);

    o[5] = Obstacle (860, 500, 5, 120);

    o[6] = Obstacle (860, 300, 5, 120);

    o[7] = Obstacle (860, 305, 100, 5);

    o[8] = Obstacle (100, 170, 5, 250);

    o[9] = Obstacle (100, 100, 70, 5);

    o[10] = Obstacle (105, 100, 5, 50);

    o[11] = Obstacle (165, 175, 100, 5);

    o[12] = Obstacle (345, 175, 100, 5);

    o[13] = Obstacle (280, 275, 5, 70);

    o[14] = Obstacle (280, 280, 100, 5);

    o[15] = Obstacle (125, 380, 5, 160);

    o[16] = Obstacle (500, 475, 5, 200);

    o[17] = Obstacle (400, 375, 120, 5); // 17

    o[18] = Obstacle (595, 375, 100, 5);

    o[19] = Obstacle (495, 370, 5, 200);

    o[20] = Obstacle (495, 270, 100, 5);

    o[21] = Obstacle (690, 170, 200, 5);

    o[22] = Obstacle (600, 165, 5, 200);

    o[23] = Obstacle (600, 70, 180, 5);

    o[24] = Obstacle (405, 270, 5, 90);

    o[25] = Obstacle (405, 90, 180, 5);

    o[26] = Obstacle (300, 90, 5, 105);

    o[27] = Obstacle (125, 385, 70, 5);

    o[28] = Obstacle (65, 455, 5, 140);

    o[29] = Obstacle (20, 50, 5, 180);

    o[30] = Obstacle (195, 50, 80, 5);

    o[31] = Obstacle (115, 220, 100, 5);

    o[32] = Obstacle (115, 315, 5, 110);

    o[33] = Obstacle (220, 225, 90, 5);

    o[34] = Obstacle (65, 305, 150, 5);

    o[35] = Obstacle (200, 455, 80, 5);

    o[36] = Obstacle (200, 535, 5, 280);

    o[37] = Obstacle (300, 90, 50, 5);

    o[38] = Obstacle (470, 120, 5, 70);

    o[39] = Obstacle (540, 120, 190, 5);

    o[40] = Obstacle (540, 310, 5, 100);

    o[41] = Obstacle (520, 480, 100, 5);

    o[42] = Obstacle (400, 475, 5, 100);

    o[43] = Obstacle (255, 490, 5, 145);

    o[44] = Obstacle (255, 430, 60, 5);

    o[45] = Obstacle (350, 360, 5, 120);

    o[46] = Obstacle (520, 70, 5, 80);

    o[47] = Obstacle (640, 20, 90, 5);

    o[48] = Obstacle (640, 110, 5, 100);

    o[49] = Obstacle (795, 65, 100, 5);

    o[50] = Obstacle (695, 65, 5, 100);

    o[51] = Obstacle (795, 85, 5, 130);

    o[52] = Obstacle (925, 85, 50, 5);

    o[53] = Obstacle (750, 245, 5, 180);

    o[54] = Obstacle (750, 245, 290, 5);

    o[55] = Obstacle (660, 415, 5, 95);

    o[56] = Obstacle (620, 530, 5, 130);

    o[57] = Obstacle (925, 190, 60, 5);

    o[58] = Obstacle (925, 190, 5, 55);

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        cout << "Error: " << Mix_GetError() << endl;
    Mix_Music* bgm = Mix_LoadMUS("kahootlobby_22ea657b5375822.mp3");
    if(!Mix_PlayingMusic())
        Mix_PlayMusic(bgm, -1);
    else if(Mix_PausedMusic())
        Mix_ResumeMusic();
    else
        Mix_PausedMusic();

    GetScreenOpen(renderer);
    waitUntilKeyPressed();
    SDL_RenderClear(renderer);

    SDL_Event e;
    do
    {
        SDL_Texture* background = loadTexture("istockphoto-1146367630-612x612.png", renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);

        SDL_Rect arrow;
        arrow.h = 50;
        arrow.w = 50;
        arrow.x = 920;
        arrow.y = 530;
        SDL_Texture* picture = loadTexture("arrow-removebg-preview.png", renderer);
        SDL_RenderCopy(renderer, picture, NULL, &arrow);

        for(int i = 0; i < max_wall; i++)
        {
            w[i].render(renderer);
        }

        for(int i = 0; i < max_obstacle; i++)
        {
            o[i].render(renderer);
        }

        if(icon.x > 920 && icon.x < 1000 && icon.y > 580 && icon.y < 600)
        {
            GetScreenWin(renderer);
            break;
        }
        if(
                 (CrashInto(icon.x, icon.y, icon.w, icon.h, w[0].x, w[0].y, w[0].w, w[0].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, w[1].x, w[1].y, w[1].w, w[1].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, w[2].x, w[2].y, w[2].w, w[2].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, w[3].x, w[3].y, w[3].w, w[3].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[0].x, o[0].y, o[0].w, o[0].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[1].x, o[1].y, o[1].w, o[1].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[2].x, o[2].y, o[2].w, o[2].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[3].x, o[3].y, o[3].w, o[3].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[4].x, o[4].y, o[4].w, o[4].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[5].x, o[5].y, o[5].w, o[5].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[6].x, o[6].y, o[6].w, o[6].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[7].x, o[7].y, o[7].w, o[7].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[8].x, o[8].y, o[8].w, o[8].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[9].x, o[9].y, o[9].w, o[9].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[10].x, o[10].y, o[10].w, o[10].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[11].x, o[11].y, o[11].w, o[11].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[12].x, o[12].y, o[12].w, o[12].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[13].x, o[13].y, o[13].w, o[13].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[14].x, o[14].y, o[14].w, o[14].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[15].x, o[15].y, o[15].w, o[15].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[16].x, o[16].y, o[16].w, o[16].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[17].x, o[17].y, o[17].w, o[17].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[18].x, o[18].y, o[18].w, o[18].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[19].x, o[19].y, o[19].w, o[19].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[20].x, o[20].y, o[20].w, o[20].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[21].x, o[21].y, o[21].w, o[21].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[22].x, o[22].y, o[22].w, o[22].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[23].x, o[23].y, o[23].w, o[23].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[24].x, o[24].y, o[24].w, o[24].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[25].x, o[25].y, o[25].w, o[25].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[26].x, o[26].y, o[26].w, o[26].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[27].x, o[27].y, o[27].w, o[27].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[28].x, o[28].y, o[28].w, o[28].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[29].x, o[29].y, o[29].w, o[29].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[30].x, o[30].y, o[30].w, o[30].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[31].x, o[31].y, o[31].w, o[31].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[32].x, o[32].y, o[32].w, o[32].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[33].x, o[33].y, o[33].w, o[33].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[34].x, o[34].y, o[34].w, o[34].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[35].x, o[35].y, o[35].w, o[35].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[36].x, o[36].y, o[36].w, o[36].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[37].x, o[37].y, o[37].w, o[37].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[38].x, o[38].y, o[38].w, o[38].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[39].x, o[39].y, o[39].w, o[39].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[40].x, o[40].y, o[40].w, o[40].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[41].x, o[41].y, o[41].w, o[41].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[42].x, o[42].y, o[42].w, o[42].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[43].x, o[43].y, o[43].w, o[43].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[44].x, o[44].y, o[44].w, o[44].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[45].x, o[45].y, o[45].w, o[45].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[46].x, o[46].y, o[46].w, o[46].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[47].x, o[47].y, o[47].w, o[47].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[48].x, o[48].y, o[48].w, o[48].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[49].x, o[49].y, o[49].w, o[49].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[50].x, o[50].y, o[50].w, o[50].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[51].x, o[51].y, o[51].w, o[51].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[52].x, o[52].y, o[52].w, o[52].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[53].x, o[53].y, o[53].w, o[53].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[54].x, o[54].y, o[54].w, o[54].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[55].x, o[55].y, o[55].w, o[55].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[56].x, o[56].y, o[56].w, o[56].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[57].x, o[57].y, o[57].w, o[57].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[58].x, o[58].y, o[58].w, o[58].h))
              || (CrashInto(icon.x, icon.y, icon.w, icon.h, o[59].x, o[59].y, o[59].w, o[59].h))
          )
              {
                  GetScreenLose(renderer);
                  break;
              }

        icon.render(renderer);
        SDL_RenderPresent(renderer);

        if(SDL_WaitEvent(&e) == 0)
            continue;
        if(e.type == SDL_KEYDOWN)
        {
            switch (e.key.keysym.sym)
            {
                case SDLK_UP:
                    icon.turnUp();
                    break;
                case SDLK_DOWN:
                    icon.turnDown();
                    break;
                case SDLK_LEFT:
                    icon.turnLeft();
                    break;
                case SDLK_RIGHT:
                    icon.turnRight();
                    break;
                default:
                    break;
            }
        }
    }
    while(true);

    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
