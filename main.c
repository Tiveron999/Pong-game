#include <SDL2/SDL.h>
#include <stdio.h>

// Screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Paddles and ball properties
int paddle_height = 80, paddle_width = 10, paddle_speed = 5;
int ball_width = 10, ball_speed_x = 4, ball_speed_y = 4;

// Paddle positions
int paddle1_x = 20, paddle2_x = SCREEN_WIDTH - 30;

// Ball position
int ball_x, ball_y;
int paddle1_y, paddle2_y;

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize positions
    paddle1_y = (SCREEN_HEIGHT - paddle_height) / 2;
    paddle2_y = (SCREEN_HEIGHT - paddle_height) / 2;
    ball_x = SCREEN_WIDTH / 2;
    ball_y = SCREEN_HEIGHT / 2;

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Game loop
    int running = 1;
    SDL_Event event;
    while (running) {
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Move paddles and ball here (implement later)

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw paddles
        SDL_Rect paddle1 = {paddle1_x, paddle1_y, paddle_width, paddle_height};
        SDL_Rect paddle2 = {paddle2_x, paddle2_y, paddle_width, paddle_height};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &paddle1);
        SDL_RenderFillRect(renderer, &paddle2);

        // Draw ball
        SDL_Rect ball = {ball_x, ball_y, ball_width, ball_width};
        SDL_RenderFillRect(renderer, &ball);

        // Update the screen
        SDL_RenderPresent(renderer);

        // Delay for 16ms (~60 FPS)
        SDL_Delay(16);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
