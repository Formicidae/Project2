#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

string checkRows(int *sudokuPtr)
{
    int count;
    for(int i = 0;i < 9;i++)
    {
        for(int searchN = 1;searchN < 10;searchN++)
        {
            for(int j = 0;j < 9;j++)
            {
                if(*(sudokuPtr + (i*9) + j) == searchN){
                    count++;
                }
            }
            if(count > 1)
            {
                ostringstream  oss;
                oss << searchN;
                string one = oss.str();
                ostringstream  oss1;
                oss1 << i;
                string two = oss1.str();
               return "Multiple " + one + " in row " + two;
            }
            count = 0;
        }
    }
    return "";
}

string checkColumns(int *sudokuPtr)
{
    int count;
    for(int i = 0;i < 9;i++)
    {
        for(int searchN = 1;searchN < 10;searchN++)
        {
            for(int j = 0;j < 9;j++)
            {
                if(*(sudokuPtr + (j*9) + i) == searchN){
                    count++;
                }
            }
            if(count > 1)
            {
                ostringstream  oss;
                oss << searchN;
                string one = oss.str();
                ostringstream  oss1;
                oss1 << i;
                string two = oss1.str();
               return "Multiple " + one + " in row " + two;
            }
            count = 0;
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
            for(int j = 8; j > -1;j--)
            {
                //cout << "line: " << iline << endl;
                *(ptr + (i*9) + (j)) = iline % 10;
                iline /= 10;
            }

        }
        /*
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
        */

        for(int i =0;i<9;i++)
        {
            for(int j =0;j<9;j++)
            {
                cout << sudoku[(i*9) + j];
            }
            cout << endl;
        }


        solutions << puzzleNumber << endl;
        string rows = checkRows(sudoku);
        if( rows != "")
        {
            solutions << puzzleNumber << "    Invalid    " << rows;
        }
        else{
            string columns = checkColumns(sudoku);
            if(columns != ""){
                solutions << puzzleNumber << "    Invalid    " << columns;
            }
            else{
                string squares = "";

                if(squares != "")
                {
                    solutions << puzzleNumber << "    Invalid    " << squares;
                }
                else{
                    solutions << puzzleNumber << "    Valid";
                }
            }
        }



        looping = false;

    }




    return 0;
}
