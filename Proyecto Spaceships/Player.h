#include<iostream>
#include<string>
#include <conio.h>
#include <windows.h>
#include "Bullet.h"
#include <vector>

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
        static const int WIDTH = 200, HEIGHT = 60, UPPER_LIMIT = 0;
        vector<Bullet> bullets;

    public:
        Player(){}

        void setStart(int x, int y)
        {
            start = Point(x, y);
        }

        void gotoxy(int x,int y)
        {  
            COORD coord;
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

        bool shoot(Spaceship enemy)
        {
            int index = bullets.size()-1;
            bool end = false, hit = false;
            Bullet shot = Bullet(start.getX() + 6, start.getY() -1);
            bullets.push_back(shot);
            while(!shot.end() && !shot.hit(enemy.getHitBox()))
            {
                shot.travel();
                draw();              
                if(shot.hit(enemy.getHitBox()))
                {
                    hit = true;
                    break;
                }

                if(shot.end())
                {
                    end = true;
                    break;
                }

                Sleep(50);
                system("cls");
            }

            system("cls");
            draw();

            bullets.erase(bullets.begin() + index);
            if(hit)
                return true;
            else   
                return false;
        }

        bool outOfBounds()
        {
            if(start.getX() < 0 || start.getX() > WIDTH)
                return true;
            
            if(start.getY() < UPPER_LIMIT || start.getY() > HEIGHT)
                return true;

            return false;
        }

        void bury()
        {
            start = Point(0, 0);
        }
};