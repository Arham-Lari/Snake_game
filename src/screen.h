#pragma once
#include <iostream>
#include <ratio>
#include <vector>
class Screen
{
    public:
        Screen(int width, int hight)
            : row(hight/40),col(width/40),cell_size(40) {};
        void draw();
        bool insideBondary(int , int );

    private:
        int row;
        int col ;
        int cell_size;
};
