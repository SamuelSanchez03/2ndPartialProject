#include <iostream>
#include <fstream>
#include <windows.h>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

class RecordScreen
{
    private:
        ifstream reader;
        ofstream writer;
        
    public:
        RecordScreen()
        {
            reader.open("Records.txt", ios::in);
            writer.open("Records.txt", ios::app);
        }

        ~RecordScreen()
        {
            reader.close();
            writer.close();
        }

        void print()
        {
            string line;
            
            cout << "-----------HIGHEST SCORES-----------\n";
            for(int i=0; i<5; i++)
            {
                getline(reader, line);
                cout << i+1 << "\t" << line << endl;
            }
        }

        vector<string> split(string s, char regex)
        {
            vector<string> res;
            string aux;
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
            res.push_back(aux);
            return res;
        }

        int getNumericValue(string line)
        {
            int index = line.length()-1;
            string aux = "";
            
            while(line[index] != ' ')
            {
                aux += line[index];
                index--;
            }

            return stoi(aux);
        }

        void modify(string nickname, int score)
        {
            string bu = "", aux, newValue = nickname + "" + to_string(score);
            vector<string> scores;
            while(!reader.eof())
            {
                getline(reader, aux);
                bu += aux;
            }
            scores = split(bu, '\n');
            int values [scores.size()];

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
                for(int i = scores.size()-2; i>=0; i--)
                {
                    if(score < values[i])
                    {
                        scores.insert(scores.begin()+i+1, newValue);
                        break;
                    }
                }
            }
        }
};