#include <windows.h>
#include <iostream>
#include "Spaceship.h"

using namespace std;

class Bullet
{
    private:
        int x, y;
        static const int B_SPEED = 1, DELAY = 10;

    public:
        Bullet(){}
        Bullet(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        void gotoxy(int x,int y)
        {  
            COORD coord;
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }

        void travel()
        {
            gotoxy(x, y);
            cout << "||\n";
            y -= B_SPEED;
        }

        bool hit(HitBox hB)
        {
            return (hB.pointInside(Point(x, y)));
        }

        bool end()
        {
            return (y < 0);
        }
};