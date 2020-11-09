// #define GLM_FORCE_RADIANS
// #define GLM_FORCE_DEPTH_ZERO_TO_ONE
// #include <glm/vec4.hpp>
// #include <glm/mat4x4.hpp>
#include <iostream>
// #include "Application.h"

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

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  SDL_Delay(3000);

  SDL_DestroyWindow(window);
  SDL_Quit();

  /*
  const auto app = std::make_unique<Application>();

  try {

	app->Run();

  } catch (const std::exception& exception) {

    std::cerr << exception.what() << std::endl;
    return EXIT_FAILURE;
  }
  */

  return EXIT_SUCCESS;
}
