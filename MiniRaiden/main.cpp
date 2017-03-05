#include "SDL\include\SDL.h"


int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window;
	SDL_Renderer* renderer;
	

	SDL_CreateWindowAndRenderer(224, 256, 0, &window, &renderer); //crea una pantalla que sale 1 milisegundo y cierra
	
	SDL_Texture* title = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("title.bmp")); //cojemos la imagen de la carpeta y cargamos la textura

	SDL_Texture* nave = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("nave.bmp"));

	SDL_Texture* oreja = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("oreja.bmp"));

	SDL_Rect r;

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

				}
			}

			//Graphics

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //pinta la pantalla de negro  0, 0, 0, 255
			SDL_RenderClear(renderer);

			SDL_RenderCopy(renderer, oreja, NULL, NULL);

			SDL_RenderCopy(renderer, title, NULL, NULL);
			r = { 0, 0, 84, 320 };
			SDL_RenderCopy(renderer, nave, NULL, &r); // pintamos nave en la pantalla, la primera null es la imagen completa y la segunda null en este caso  en r, unas coordenadas especificas para mostrar en pantalla la nave


			SDL_RenderPresent(renderer);
		
	}

	SDL_Quit();
	return 0;
}