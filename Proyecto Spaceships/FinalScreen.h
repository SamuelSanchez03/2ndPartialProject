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

        void printResult(char result, int score)
        {
            if(result == 'W')
                printWin();
            else if(result == 'L')
                printDefeat();

            cout << "\nYour score: " << score << endl << "Press Enter to Exit\n";
        }

        int selection(int c)
        {
            if(c = getch() == KEY_RETURN)
                return 1;
            else
                return 0;
        }

        void printWin()
        {
            for(int i=0; i<3; i++)
                cout << victory[i];
        }

        void printDefeat()
        {
            for(int i=0; i<3; i++)
                cout << defeat[i];
        }
};