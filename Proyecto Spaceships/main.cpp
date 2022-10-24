#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "TitleScreen.h"
#include <pthread.h>
#include "Player.h"
#include "RecordScreen.h"

using namespace std;

#define KEY_SPACE 0x20

Player player = Player(10, 10);

void *bullet (void* args)
{
    player.shoot();

    pthread_exit(NULL);
}

void *printing (void* args)
{
    while(true)
        player.draw();
}

void *pMovement (void* args)
{
    pthread_t shooting;
    int resS;
    int c;
    while(true)
    {
        player.draw();
        c = getch();
        if(c != KEY_SPACE)
            player.move(getch());
        else    
        {
            resS = pthread_create(&shooting, NULL, bullet, NULL);
        }

        system("cls");
        
        if(player.outOfBounds())
            break;
    }
    pthread_exit(NULL);
}

void *eMovement(void* args)
{
    Spaceship enemy = Spaceship(3);
    enemy.move();
    pthread_exit(NULL);
}

int main()
{
    int sel = -1, res, res2, score, res3;
    bool end = false;
    string nickname;

    system("cls");
    cout << "Enter your nickname: ";
    cin >> nickname;
    system("cls");
    cout << "Welcome " << nickname << endl;
    system("pause");

    TitleScreen tscreen = TitleScreen();
    RecordScreen recordScreen;

    pthread_t pM, enemies[4], print;

    system("cls");
    while(true)
    {
        tscreen.print();
        sel = tscreen.selection(0);
        system("cls");
        if(sel != -1)
          break;
    }

    if(sel == 0)
    {
        //res3 = pthread_create(&print, NULL, printing, NULL);
        res = pthread_create(&pM, NULL, pMovement, NULL);
        //for(int i=0; i<4; i++)
            //res2 = pthread_create(&enemies[i], NULL, eMovement, NULL);
    }
    else if(sel == 1)
    {
        //recordScreen = RecordScreen();
    }

    pthread_exit(NULL);
}