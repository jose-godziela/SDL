#include <SDL.h>
#include <stdlib.h>

enum Key {
	UP = 119,
	DOWN = 115,
	LEFT = 97,
	RIGHT = 100,
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT,
};

Key key;

int main()
{
	SDL_Window *o;		//Window Pointer
	SDL_Renderer *r;	//Renderer Pointer
	SDL_Event e;		//Event variable
	SDL_Rect rectangle;	//Rectangle variable
	bool end = false;

	rectangle.x = 475;
	rectangle.y = 700;
	rectangle.h = 50;
	rectangle.w = 50;

	SDL_Init(SDL_INIT_VIDEO);

	o = SDL_CreateWindow("Game test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1024,
		800,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	r = SDL_CreateRenderer(o, -1, SDL_RENDERER_ACCELERATED);

	while (!end)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
				end = true;
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
				case SDLK_q:
					end = true;
					break;
				case UP:
					rectangle.y -= 10;
					break;
				case DOWN:
					rectangle.y += 10;
					break;
				case RIGHT:
					rectangle.x += 10;
					break;
				case LEFT:
					rectangle.x -= 10;
					break;
				}
			}
		}
		SDL_SetRenderDrawColor(r, 0, 0, 255, 255);
		SDL_RenderClear(r);


		SDL_SetRenderDrawColor(r, 0, 0, 0, 255);

		SDL_RenderFillRect(r, &rectangle);

		SDL_RenderPresent(r);
	}

	SDL_DestroyWindow(o);
	SDL_DestroyRenderer(r);
	SDL_Quit();

	return 0;
}