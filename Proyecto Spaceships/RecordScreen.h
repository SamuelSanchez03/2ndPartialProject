#include <iostream>
#include <fstream>
#include <windows.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

#define KEY_RETURN 0x0D

class RecordScreen
{
        
    public:
        
        RecordScreen(){}

        void print()
        {
            string line;
            int index = 0;
            ifstream reader;
            reader.open("Records.txt", ios::in);
            cout << "-----------HIGHEST SCORES-----------\n";
            while(index < 5 && !reader.eof())
            {
                getline(reader, line);
                cout << index+1 << "\t" << line << endl;
                index++;
            }
            reader.close();

            cout << "\n\n\n\nPress Enter to Go Back\n";
        }

        vector<string> split(string s, char regex)
        {
            vector<string> res;
            string aux = "";
            for(int i=0; i<s.length(); i++)
            {
                if(s[i] != regex)
                    aux += s[i];
                else
                {
                    res.push_back(aux);
                    aux = "";
                }
            }
            return res;
        }

        int getNumericValue(string line)
        {
            int index = line.length()-1;
            string aux = "", aux2 = "";
            
            while(line[index] != ' ')
            {
                aux2 = aux;
                aux = line[index] + aux;
                index--;
            }

            return stoi(aux);
        }

        void modify(string nickname, int score)
        {
            ifstream reader;
            ofstream writer;
            reader.open("Records.txt", ios::in);

            string bu = "", aux, newValue = nickname + " " + to_string(score);
            vector<string> scores;
            while(!reader.eof())
            {
                getline(reader, aux);

                bu += aux + "\n";
            }
            scores = split(bu, '\n');
            int values [scores.size()];

            if(scores[scores.size()-1] == "\n")
                scores.pop_back();

            for(int i=0; i<scores.size(); i++)
            {
                values[i] = getNumericValue(scores[i]);
            }

            if(score > values[0])
                scores.insert(scores.begin(), newValue);
            else if(score < values[scores.size()-1])
                scores.push_back(newValue);
            else
            {
                for(int i = 1; i<scores.size()-1; i++)
                {
                    if(score > values[i])
                    {
                        scores.insert(scores.begin()+i, newValue);
                        break;
                    }
                }
            }

            writer.open("Records.txt");

            for(auto it = scores.begin(); it != scores.end(); it++)
            {
                if(it != scores.begin())
                    writer << endl;
                writer << *it;
            }

            writer.close();
        }

        int selection(int c)
        {
            if(c = getch() == KEY_RETURN)
                return 1;
            else 
                return 0;
        }
};