#include "SDL\include\SDL.h"


int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("Game", 400, 400, 480, 640, NULL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_PRESENTVSYNC);


	

	SDL_Texture* title = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("title.bmp")); //cojemos la imagen de la carpeta y cargamos la textura
    SDL_Texture* navesita = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("navesitas.bmp"));

	SDL_Rect r;
	SDL_Rect j;

	int spaceship_x = 0;
	int spaceship_y = 0;
	int spaceship_xvel = 0;
	int spaceship_yvel = 0;

	bool run = true;
	while (run)
	{



		//Input
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				run = false;
			}
			switch (event.type)
			{
			case SDL_KEYDOWN:
				
				switch (event.key.keysym.sym)
				{
				case SDLK_LEFT:
					spaceship_xvel = -1;
					break;

				case SDLK_RIGHT:
					spaceship_xvel = 1;
					break;

				case SDLK_UP:
					spaceship_yvel = -1;
					break;

				case SDLK_DOWN:
					spaceship_yvel = 1;
					break;

	
				}

			}



			//Graphics

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //pinta la pantalla de negro  0, 0, 0, 255
			SDL_RenderClear(renderer);


			SDL_RenderCopy(renderer, title, NULL, NULL);
			j = { spaceship_x, spaceship_y, 200, 150 };
			SDL_RenderCopy(renderer, navesita, NULL, &j);


			SDL_RenderPresent(renderer);

		}

	}
			SDL_Quit();
			return 0;
		
	}



