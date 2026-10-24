#include "raylib.h"
#include "screen.h"
#include "snake.h"

int main(int argc , char* argv[])
{
    const int window_width {800}, window_height{400};
    Screen screen = Screen(window_width,window_width);

    InitWindow(window_width, window_height, "Snake_Game");
    SetTargetFPS(60);

    Snake snake = Snake();

    screen.displayGrid();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        screen.draw();
        snake.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
