#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int sudoku[9][9];
    ifstream puzzles("puzzles.txt");
    ofstream solutions("solutions.txt");
    bool looping;
    string puzzleNumber;
    string line;
    char chars[1];
    char ch;
    while(looping)
    {
        getline(puzzles,puzzleNumber);
        //cout << line;
        for(int i = 0; i < 9;i++)
        {
            getline(puzzles,line);
            //cout << line;
            for(int j = 0; j < 9;j++)
            {
                chars = line.substr(j).c_str();
                ch = chars[0];
                //cout << ch << endl;
                sudoku[i][j] = ch;
            }

        }
        cout << sudoku[0][0] << endl;
        cout << sudoku[0][1] << endl;
        cout << sudoku[0][2] << endl;
        cout << sudoku[0][3] << endl;
        cout << sudoku[0][4] << endl;
        cout << sudoku[0][5] << endl;
        cout << sudoku[0][6] << endl;
        cout << sudoku[0][7] << endl;
        cout << sudoku[0][8] << endl;
        cout << sudoku[0][9] << endl;
        looping = false;

    }




    return 0;
}
