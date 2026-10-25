#include "raylib.h"
#include "screen.h"
#include "snake.h"

int main(int argc , char* argv[])
{
    const int window_width {1200}, window_height{720};
    Screen screen = Screen(window_width,window_height);

    InitWindow(window_width, window_height, "Snake_Game");
    SetTargetFPS(60);

    Snake snake = Snake();


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        if(IsKeyDown(KEY_S)){
            snake.moveDown();
        }
        
        if(IsKeyDown(KEY_A)){
            snake.moveLeft();
        }
        screen.draw();
        snake.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
