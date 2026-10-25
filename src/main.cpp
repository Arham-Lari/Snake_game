#include "raylib.h"
#include "game.h"


int main(int argc , char* argv[])
{
    const int window_width {1200}, window_height{720};

    InitWindow(window_width, window_height, "Snake_Game");

    Game game = Game();


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        game.draw();
        game.movement();
        game.foodAte();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
