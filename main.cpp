#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

string checkRows(int *sudokuPtr)
{
    int count;
    for(int search = 1;search < 10;search++)
    {
        for(int i = 0;i < 9;i++)
        {
            for(int j = 0;j < 9;j++)
            {
                if(*(sudokuPtr + (i*9) + j) == search){
                    count++;
                }
            }
            if(count > 1)
            {
                return "Multiple " + search + " in row " + i;
            }
        }
    }
    return "";
}


int main()
{
    int sudoku[81];
    ifstream puzzles("puzzles.txt");
    ofstream solutions("solutions.txt");
    bool looping;
    string puzzleNumber;
    string line;
    char chars[1];
    char ch;
    int iline;
    while(looping)
    {
        getline(puzzles,puzzleNumber);
        //cout << line;
        for(int i = 0; i < 9;i++)
        {
            //getline(puzzles,line);
            //cout << line;
            int* ptr;
            ptr = sudoku;
            puzzles >> iline;
            for(int j = 0; j < 9;j++)
            {
                //puzzles >> iline;
                //sudoku[i][j] = iline /
                cout << "line: " << iline << endl;
                //chars = line.substr(j).c_str();
                //ch = chars[0];
                //cout << ch << endl;
                //sudoku[i][j] = ch;
                cout << iline / (100000000 / (int)pow(10,j)) << endl;
                *(ptr + (i*9) + (j)) = iline / (100000000 / (int)pow(10,j));
                //cout << *(ptr) << endl;
                iline %= (100000000 / (int)pow(10,j));
                cout << sudoku[j] << endl;
            }

        }
        cout << "Line: " << endl;
        cout << sudoku[0] << endl;
        cout << sudoku[1] << endl;
        cout << sudoku[2] << endl;
        cout << sudoku[3] << endl;
        cout << sudoku[4] << endl;
        cout << sudoku[5] << endl;
        cout << sudoku[6] << endl;
        cout << sudoku[7] << endl;
        cout << sudoku[8] << endl;

        for(int i =0;i<9;i++)
        {
            for(int j =0;j<9;j++)
            {
                cout << sudoku[(i*9) + j];
            }
            cout << endl;
        }
        looping = false;

    }




    return 0;
}
