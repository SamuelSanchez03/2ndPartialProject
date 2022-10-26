#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_RETURN 0x0D

class TitleScreen
{
    private:
        const string TITLE = "   _  _  _  _    _  _  _  _         _           _  _  _     _  _  _  _  _   _  _  _  _    _           _  _  _  _  _  _  _  _      _  _  _  _\n _(_)(_)(_)(_)_ (_)(_)(_)(_)_     _(_)_      _ (_)(_)(_) _ (_)(_)(_)(_)(_)_(_)(_)(_)(_)_ (_)         (_)(_)(_)(_)(_)(_)(_)(_)_  _(_)(_)(_)(_)_\n(_)          (_)(_)        (_)  _(_) (_)_   (_)         (_)(_)           (_)          (_)(_)         (_)   (_)   (_)        (_)(_)          (_)\n(_)_  _  _  _   (_) _  _  _(_)_(_)     (_)_ (_)            (_) _  _      (_)_  _  _  _   (_) _  _  _ (_)   (_)   (_) _  _  _(_)(_)_  _  _  _ \n";
        const string TITLE2 = "  (_)(_)(_)(_)_ (_)(_)(_)(_) (_) _  _  _ (_)(_)            (_)(_)(_)       (_)(_)(_)(_)_ (_)(_)(_)(_)(_)   (_)   (_)(_)(_)(_)    (_)(_)(_)(_)_\n _           (_)(_)          (_)(_)(_)(_)(_)(_)          _ (_)            _           (_)(_)         (_)   (_)   (_)            _           (_)\n(_)_  _  _  _(_)(_)          (_)         (_)(_) _  _  _ (_)(_) _  _  _  _(_)_  _  _  _(_)(_)         (_) _ (_) _ (_)           (_)_  _  _  _(_)\n  (_)(_)(_)(_)  (_)          (_)         (_)   (_)(_)(_)   (_)(_)(_)(_)(_) (_)(_)(_)(_)  (_)         (_)(_)(_)(_)(_)             (_)(_)(_)(_)";
        

        string play [3] = {"___  _    ____ _   _ ", "|__] |    |__|  \\_/  ", "|    |___ |  |   |   "};
        string records[3] = {"____ ____ ____ ____ ____ ___  ____ ", "|__/ |___ |    |  | |__/ |  \\ [__  ", "|  \\ |___ |___ |__| |  \\ |__/ ___] "};
        string pointerP [3] = {"\n", "/\\\n", "\\/\n"};
        string pointerR [3] = {"\n", "\n", "\n"};
        int sel = 0;

    public:
        TitleScreen(){}

        void print(string nickname)
        {
            system("cls");
            cout << TITLE << TITLE2 << endl;
            for(int i=0; i<3; i++)
            {
                cout << play[i] << pointerP[i];
            }

            for(int i=0; i<3; i++)
            {
                cout << records[i] << pointerR[i];
            }
            cout << "\n\n\nUser: " << nickname << endl;
        }

        int selection(int c)
        {
            string cambio;
            switch((c=getch())) 
            {
                case KEY_DOWN: case KEY_UP:
                    (sel == 0) ? sel = 1 : sel = 0;
                    if(sel == 0)
                    {
                        for(int i=1; i<3; i++)
                        {
                            cambio = pointerP[i];
                            pointerP[i] = pointerR[i];
                            pointerR[i] = cambio;
                        }
                    }
                    else
                    {
                        for(int i=1; i<3; i++)
                        {
                            cambio = pointerP[i];
                            pointerP[i] = pointerR[i];
                            pointerR[i] = cambio;
                        }
                    }
                    return -1;
                case KEY_RETURN:
                    system("cls");
                    return sel;
                default:
                    return -1;
            }
        }
};