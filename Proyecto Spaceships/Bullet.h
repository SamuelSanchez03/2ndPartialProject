#include <windows.h>
#include <iostream>

using namespace std;

class Bullet
{
    private:
        int x, y;
        const int B_SPEED = 1, DELAY = 10;

    public:
        Bullet(int x, int y)
        {
            this->x = x;
            this->y = y;
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

        void travel()
        {
            while(y >= 0)
            {
                gotoxy(x, y);
                cout << "||\n";
                Sleep(DELAY);
                y -= B_SPEED;
                system("cls");
            }
        }
};