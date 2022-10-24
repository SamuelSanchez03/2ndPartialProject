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
        vector<string> smallE = {"    __\n", "____\\/____\n", "\\___  ___/\n", "    \\/\n"};
        vector<string> medium = {"      ____\n", "      \\  /\n","_______\\/_______\n", "\\______  ______/\n", "   |   \\/   |\n"};
        vector<string> big = {"         ______\n", "         \\    /\n", "          \\  /\n", "___________\\/___________\n", "\\                      /\n", " \\                    /\n", "  \\______      ______/\n", "     |    \\  /    |\n", "           \\/"};
        int size, score, mSpeed = 1;
        Point start;
        bool dead;
        vector<string> sprite;
        int values[3] = {500, 250, 150};
        const int WIDTH = 300, HEIGHT = 100, UPPER_LIMIT = 0;

        void createMap()
        {
            sprites.insert(pair<int, vector<string>> (SMALL, smallE));
            sprites.insert(pair<int, vector<string>> (MEDIUM, medium));
            sprites.insert(pair<int, vector<string>> (BIG, big));
        }

    public: 
        Spaceship()
        {
            srand(time(NULL));
            createMap();
            size = rand()%3;
            sprite = sprites.find(size)->second;
            score = values[size];
            start = Point(9 + (rand()%80), 1);
            dead = false;
        }

        Spaceship(int size)
        {
            srand(time(NULL));
            createMap();
            this->size = size;
            sprite = sprites.find(size)->second;
            score = values[size];
            start = Point(9 + (rand()%80), 1);
            dead = false;
        }

        void setMSpeed(int mSpeed)
        {
            this->mSpeed = mSpeed;
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
            system("cls");
            for(int i=0; i<sprite.size(); i++)
            {
                gotoxy(start.getX(), start.getY()+i);
                cout << sprite[i];
            }
        }

        void move()
        {
            while(start.getY() < HEIGHT && dead == false)
            {
                gotoxy(start.getX(), start.getY());
                draw();
                start.moveY(mSpeed);
                Sleep(10);
            }
        }

        

        int giveScore()
        {
            if(dead)
                return score;
            else 
                return 0;
        }
};