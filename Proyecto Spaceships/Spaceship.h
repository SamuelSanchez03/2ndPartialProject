#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <map>
#include <vector>
#include <time.h>
#include "HitBox.h"

using namespace std;

#define SMALL 0
#define MEDIUM 1
#define BIG 2

class Spaceship
{
    private:
        map<int, vector<string>> sprites;
        map<int, Point> dimensions;
        vector<string> smallE = {"    __\n", "____\\/____\n", "\\___  ___/\n", "    \\/\n"};
        vector<string> medium = {"      ____\n", "      \\  /\n","_______\\/_______\n", "\\______  ______/\n", "   |   \\/   |\n"};
        vector<string> big = {"         ______\n", "         \\    /\n", "          \\  /\n", "___________\\/___________\n", "\\                      /\n", " \\                    /\n", "  \\______      ______/\n", "     |    \\  /    |\n", "           \\/"};
        
        Point dimSmall = Point(10, 4);
        Point dimMedium = Point(16, 5);
        Point dimBig = Point(24, 9);

        int size, score, mSpeed, dX, dY;
        Point start;
        bool dead;
        vector<string> sprite;
        int values[3] = {500, 250, 150};
        static const int WIDTH = 135, HEIGHT = 40, UPPER_LIMIT = 30;
        HitBox hitBox;

        void createMap()
        {
            sprites.insert(pair<int, vector<string>> (SMALL, smallE));
            sprites.insert(pair<int, vector<string>> (MEDIUM, medium));
            sprites.insert(pair<int, vector<string>> (BIG, big));

            dimensions.insert(pair<int, Point> (SMALL, dimSmall));
            dimensions.insert(pair<int, Point> (MEDIUM, dimMedium));
            dimensions.insert(pair<int, Point> (BIG, dimBig));
        }

    public: 
        Spaceship(){}

        Spaceship(int size)
        {
            srand(time(0));
            createMap();
            this->size = size;
            sprite = sprites.find(size)->second;
            score = values[size];
            start = Point(9 + (rand()%130), 1);

            switch(size)
            {
                case 0:
                    mSpeed = 3;
                    break;
                case 1: 
                    mSpeed = 2;
                    break;
                case 2:
                    mSpeed = 1;
                    break;
            }
            dead = false;
            hitBox = HitBox(start.getX(), start.getX() + dimensions.find(size)->second.getX(), start.getY(), start.getY() + dimensions.find(size)->second.getY());
        }

        void bury()
        {
            start = Point(-1, -1);
            hitBox = HitBox(-1, -1, -1, -1);
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
            if(!dead)
            {
                for(int i=0; i<sprite.size(); i++)
                {
                    gotoxy(start.getX(), start.getY()+i);
                    cout << sprite[i];
                }
            }
        }

        void move()
        {
            if(!dead)
            {
                gotoxy(start.getX(), start.getY());
                draw();
                start.moveY(mSpeed);
                hitBox.moveHB(mSpeed);
            }
        }

        HitBox getHitBox()
        {
            return hitBox;
        }

        void gotShot()
        {
            dead = true;
        }

        bool isDead()
        {
            return dead;
        }

        int giveScore()
        {
            return score;
        }

        bool reachEnd()
        {
            return (start.getY() > HEIGHT);
        }
};