#include<iostream>
#include<string>
#include <conio.h>
#include <windows.h>
#include "Spaceship.h"
#include "Bullet.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 0x0D
#define KEY_SPACE 0x20
 

class Player
{
    private:
        string sprite [4] = {"______||______\n","\\____    ____/\n","     \\  /\n","      \\/\n"};
        Point start;
        const int mSpeed = 5;
        const int WIDTH = 300, HEIGHT = 300, UPPER_LIMIT = 0;

    public:
        Player(int x, int y)
        {
            start = Point(x, y);
        }

        void gotoxy(int x,int y)
        {  
            HANDLE hcon;  
            hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
            COORD dwPos;  
            dwPos.X = x;  
            dwPos.Y= y;  
            SetConsoleCursorPosition(hcon,dwPos);  
        }

        void draw()
        {
            for(int i=0; i<4; i++)
            {
                gotoxy(start.getX(), start.getY()+i);
                cout << sprite[i];
            }
        }

        void move(char c)
        {
            switch(c)
            {
                case KEY_UP:
                    start.moveY(-mSpeed);
                    break;
                case KEY_DOWN:
                    start.moveY(mSpeed);
                    break;
                case KEY_RIGHT:
                    start.moveX(mSpeed);
                    break;
                case KEY_LEFT:
                    start.moveX(-mSpeed);
                    break;
            }
        }

        void shoot()
        {
            Bullet shot = Bullet(start.getX() + 6, start.getY() -1);
            shot.travel();
        }

        bool outOfBounds()
        {
            if(start.getX() < 0 || start.getX() > WIDTH)
                return true;
            
            if(start.getY() < UPPER_LIMIT || start.getY() > HEIGHT)
                return true;

            return false;
        }
};