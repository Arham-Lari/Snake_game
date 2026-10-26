#pragma once
#include <iostream>
#include <ratio>
#include <raylib.h>
#include <vector>
class Screen
{
    public:
        Screen()
            : row(GetScreenHeight()/40),col(GetScreenWidth()/40),cell_size(40) {};
        void draw();
        bool insideBondary(int , int ); 
        int row;
        int col ;
        

    private:
        int cell_size;
};
