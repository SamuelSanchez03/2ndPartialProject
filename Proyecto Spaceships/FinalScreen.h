#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

#define KEY_RETURN 0x0D

class FinalScreen
{
    private:
        string victory [3] = {"_  _ _ ____ ___ ____ ____ _   _\n", "|  | | |     |  |  | |__/  \\_/ \n", " \\/  | |___  |  |__| |  \\   | "};
        string defeat [3] = {"___  ____ ____ ____ ____ ___\n", "|  \\ |___ |___ |___ |__|  | \n", "|__/ |___ |    |___ |  |  |   \n"};

    public:
        FinalScreen(){}

        void gotoxy(int x,int y)
        {  
            COORD coord;
            coord.X = x;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        }

        void printResult(char result, int score)
        {
            if(result == 'W')
                printWin(score);
            else if(result == 'L')
                printDefeat(score);
        }

        int selection(int c)
        {
            if(c = getch() == KEY_RETURN)
                return 1;
            else
                return 0;
        }

        void printWin(int score)
        {
            for(int i=0; i<5; i++)
            {
                gotoxy(60, 15+i);
                if(i < 3)
                    cout << victory[i];
                else if(i == 3)
                    cout << "Your score: " << score << endl;
                else if(i == 4)
                    cout << "Press Enter to Exit\n";
            }
        }

        void printDefeat(int score)
        {
            for(int i=0; i<5; i++)
            {
                gotoxy(60, 15+i);
                if(i < 3)
                    cout << defeat[i];
                else if(i == 3)
                    cout << "Your score: " << score << endl;
                else if(i == 4)
                    cout << "Press Enter to Exit\n";
            }
        }
};