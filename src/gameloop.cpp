#include "gameloop.hpp"

#include <SDL2/SDL_timer.h>
#include <cstdlib>
#include <iostream>

namespace snake{

void snakeGameloop::init()
{   
    genericObj obj(*game_sizeX/2, *game_sizeY/2);
    snake_components.push_back(obj);
    for (genericObj s : snake_components){
        std::cout << s.x << " " << s.y << '\n';
    }
}

void snakeGameloop::runloop(snakeRenderer * p_renderer, snakeWindow * p_window, uint32_t * p_windowSizeX, uint32_t * p_windowSizeY, uint8_t * p_gameSizeX, uint8_t * p_gameSizeY) 
{
    renderer = p_renderer;  // Reference to the renderer that has a scope of the whole class
    game_sizeX = p_gameSizeX;
    game_sizeY = p_gameSizeY;

    windowSizeX = p_windowSizeX;
    windowSizeY = p_windowSizeY;
    

    init();
    updateScore(length - 2);

    // Checks if the program should exit
    while( !quit ){
        while( SDL_PollEvent( &e ) != 0 ){
            if( e.type == SDL_QUIT ){
                quit = true;
            } else if (e.type == SDL_WINDOWEVENT) {
                switch (e.window.event){
                    case SDL_WINDOWEVENT_RESIZED:
                        p_window->resized(&e.window.data1, &e.window.data2);
                    break;
                }
            }
        }

    previousTime = currentTime;
    currentTime = SDL_GetTicks();

    // Actual things for game to run
    gameLogic();
    loopRender();
    
    // Delays the game to cap the framerate as desired
    if (currentTime - previousTime < 1000 / MaxFps) {
        SDL_Delay(1000 / MaxFps - currentTime + previousTime);
    }
    }
}

void snakeGameloop::gameLogic()
{
    input.input(&playerController, &e, windowSizeX, windowSizeY);

    // Creates a fruit if there is currently no fruit on the board
    // This will happen at the beggining of the game, and will happen every time a fruit is eaten and destroyed
    if (fruit.x == 0){
        uint8_t f_x, f_y; 
        srand(time(0));

        bool emptyPos = true;
        do{
            f_x = rand()% *game_sizeX + 1;
            f_y = rand()% *game_sizeY + 1;

            for(genericObj s : snake_components){
                if (s.x == f_x && s.y == f_y)
                    emptyPos = false;
            }
        }while (emptyPos == false);    // Ensures that the fruit is not generated inside of the snake body / or another fruit if multiple fruits are supported in the future
        
        fruit = genericObj(f_x, f_y);
    }

    /*
    *   Limits the game logic update rate
    *   difficulty is increased based on the update rate
    *   Uses the same logic as the main loop, just with a special unit 'lastLogic' 
    *   which controls the frequency of the game logic
    */  
    if ((previousTime - lastLogic > 1000 / logicFPS)) {
        lastLogic = currentTime;

        // Update player coords based on current direction
        switch (playerController.dir){
            case 'R':
                playerController.x += 1;
                break;
            case 'L':
                playerController.x -= 1;
                break;
            case 'U':
                playerController.y -= 1;
                break;
            case 'D':
                playerController.y += 1;
                break;
        }
        
        //  Failure occurs if the player runs off the screen or runs into their own tail
        self_collision = false;
        for (genericObj& p : snake_components){
            if (p.x == playerController.x && p.y == playerController.y){
                self_collision = true;
            }
        }

        if (    playerController.x == 0
                || playerController.y == 0
                || playerController.x == *game_sizeX + 1 
                || playerController.y == *game_sizeY + 1
                || self_collision == true
            ) {
            quit = true;
            return;
        }

        // If the player interacts with the fruit, the length is incrased and the fruit is removed from the vector, which stages another fruit to be created
        if (playerController.x == fruit.x && playerController.y == fruit.y){
            length += 1;
            updateScore((length - 2)*100);

            fruit.x = 0;
            logicFPS = sqrt(length);
        }

        snake_components.push_back(genericObj(playerController.x,playerController.y));

        // Creates a new tail object which is used to keep track of where we
        // need to reset from being rendered after the snake moves and grows
        //tailObjects.push_back(genericObj(playerController.x, playerController.y)); 

        // if the tail is longer than the proper size, the tail gets shortened by
        // reseting the map varible at that location and deleting the object from the vector
        if (static_cast<uint8_t>(snake_components.size()) >= length + 1) {
            snake_components.erase(snake_components.begin());
        }
    }

}

void snakeGameloop::updateScore(uint8_t p_score)
{
    // Deletes the current text object if there is one
    if (!text.empty())
        text.erase(text.begin());

    std::string textOut = "Score: " + std::to_string(static_cast<int>(p_score));                        // Create the string with the score appended
    text.push_back(snakeText(renderer->getRenderer(), "ttf/Hack.ttf", 28, textOut, {255,255,255,255})); // Create a new text object with the new score

}

void snakeGameloop::loopRender()
{
    renderer->clear();
    renderer->render(fruit.x, fruit.y);
    for (genericObj& s : snake_components){
        renderer->render(s.x, s.y);
    }
    text.front().display(12, 12, renderer->getRenderer());
    SDL_RenderPresent(renderer->getRenderer());
}
}
