#include "raylib.h"
#include "screen.h"

int main(int argc , char* argv[])
{
    const int window_width {800}, window_height{400};
    Screen screen = Screen(window_width,window_width);

    InitWindow(window_width, window_height, "Snake_Game");
    SetTargetFPS(60);

    screen.displayGrid();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        screen.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
