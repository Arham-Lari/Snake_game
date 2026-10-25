#include "raylib.h"
#include "screen.h"
#include "snake.h"

bool timer(double interval){
    static double curr_time = 0;
    double time = GetTime();

    if(time - curr_time >= interval){

        curr_time = time;
        return true;

    }

    return false;
}

int main(int argc , char* argv[])
{
    const int window_width {1200}, window_height{720};
    Screen screen = Screen(window_width,window_height);

    InitWindow(window_width, window_height, "Snake_Game");

    Snake snake = Snake();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        if(timer(0.1)){
            snake.moveLeft();
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
