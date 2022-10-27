#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "TitleScreen.h"
#include <pthread.h>
#include "Player.h"
#include "RecordScreen.h"
#include "FinalScreen.h"
#include <signal.h>

using namespace std;

#define KEY_SPACE 0x20

Player player = Player();
Spaceship enemy;
int score = 0, enemyCount = 0;
char result = 'U';


void *bullet (void* args)
{
    if(player.shoot(enemy))
        enemy.gotShot();

    pthread_exit(NULL);
}

void *pMovement (void* args)
{
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_t shooting;
    int resS;
    int c;
    while(result == 'U')
    {
        system("cls");
        player.draw();
        c = getch();
        if(c != KEY_SPACE)
            player.move(getch());
        else    
            resS = pthread_create(&shooting, NULL, bullet, NULL);

        system("cls");
    }

    player.bury();
    pthread_exit(NULL);
}

void *eMovement(void* args)
{
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    int size = 2;
    if(enemyCount > 2)
        size--;
    if(enemyCount > 5)
        size--;
    enemy = Spaceship(size); 
    while(!enemy.isDead() && !enemy.reachEnd())
    {
        enemy.move();
        player.draw();
        Sleep(300);
        system("cls");
    }

    if(enemy.isDead())
    {
        enemy.bury();
        score += enemy.giveScore();
        enemyCount++;
        return (void*)1;
    }
    
    if(enemy.reachEnd())
    {
        return (void*)0;
    }
    pthread_exit(NULL);
}

int main()
{
    int sel = -1, res, res2, enemyLimit = 14;
    void* resEnemy = (void*)1;
    string nickname;

    system("cls");
    cout << "Enter your nickname: ";
    cin >> nickname;
    system("cls");
    cout << "Welcome " << nickname << endl;
    Sleep(1000);

    TitleScreen tscreen = TitleScreen();
    RecordScreen recordScreen = RecordScreen();
    FinalScreen finalScreen = FinalScreen();

    pthread_t pM, enemies, print;

    while(sel == -1)
    {
    beginning:
        tscreen.print(nickname);
        sel = tscreen.selection(0);
        system("cls");
    }

    if(sel == 0)
    {
        result = 'U';
        score = 0, enemyCount = 0, resEnemy = (void*)1;
        player.setStart(65, 30);
        res = pthread_create(&pM, NULL, &pMovement, NULL);
        //pthread_join(pM, NULL);
        while((int)resEnemy != 0 && enemyCount <= enemyLimit)
        {
            res2 = pthread_create(&enemies, NULL, &eMovement, NULL);
            pthread_join(enemies, &resEnemy);
        }

        pthread_cancel(pM);
        pthread_cancel(enemies);

        if((int)resEnemy == 0)
            result = 'L';
        if(enemyCount >= enemyLimit)
            result = 'W';

        recordScreen.modify(nickname, score);
        int selF = 0;
        while(selF == 0)
        {
            finalScreen.printResult(result, score);
            selF = finalScreen.selection(0);
            system("cls");
        }
        enemyCount = 0;
        sel = -1;
        goto beginning;
    }
    else if(sel == 1)
    {
        int selR = 0;
        while(selR == 0)
        {
            recordScreen.print();
            selR = recordScreen.selection(0);
            system("cls");
        }
        sel = -1;
        goto beginning;
    }

    pthread_exit(NULL);
}