// #define GLM_FORCE_RADIANS
// #define GLM_FORCE_DEPTH_ZERO_TO_ONE
// #include <glm/vec4.hpp>
// #include <glm/mat4x4.hpp>
#include <iostream>
// #include "Application.h"
#include <random>
#include <functional>
#include "SDL.h"

int main(int argc, char *argv[]){

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
	  "SDL2Test",
	  SDL_WINDOWPOS_UNDEFINED,
	  SDL_WINDOWPOS_UNDEFINED,
	  640,
	  480,
	  0
  );

  if (window == nullptr)
  {
	SDL_Log("Could not create a window: %s", SDL_GetError());
	return -1;
  }

  SDL_Log("Test");

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

  bool running = true;
  SDL_Event e;

  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1,255);

  auto random = std::bind ( distribution, generator );
  /* auto t = [distribution, generator]() -> Uint8 {
    return distribution(generator);
  }; */

  while (running) {

	while( SDL_PollEvent( &e ) != 0 )
	{
	  //User requests quit
	  if( e.type == SDL_QUIT )
	  {
		running = false;
	  }
	}


	// Randomly change the colour
	Uint8 red = random();
	Uint8 green = random();
	Uint8 blue = random();

	// Fill the screen with the colour
	SDL_SetRenderDrawColor(renderer, red, green, blue, 255);

	//Clear screen
	SDL_RenderClear( renderer );

	//Render texture to screen
	// SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

	//Update screen
	SDL_RenderPresent( renderer );

  }




  SDL_Delay(3000);

  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
