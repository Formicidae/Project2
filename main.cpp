#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

string checkRows(int *sudokuPtr)
{
    int count = 0;
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
                cout << endl << "count: " << count << endl;
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
    int count = 0;
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
               return "Multiple " + one + " in column " + two;
            }
            count = 0;
        }
    }
    return "";
}

string squarePrint(int r, int c)
{
    string output = "";
    switch(r){
        case 0: output += "Upper"; break;
        case 3: output += "Middle"; break;
        case 6: output += "Lower"; break;
    }
    switch(c){
        case 0: output += " Left"; break;
        case 3: output += " Middle"; break;
        case 6: output += " Right"; break;
    }
    return output;
}

string checkSquares(int *sudokuPtr)
{
    for(int rowStart = 0;rowStart < 7;rowStart += 3){
        for(int colStart = 0;colStart < 7;colStart += 3){
            int count = 0;
            for(int num = 1;num < 10;num++){
                for(int r = rowStart; r < rowStart + 3;r++){
                    for(int c = colStart;c < colStart + 3;c++){
                        if(*(sudokuPtr + (r*9) + c) == num){
                            count++;
                        }
                    }
                }
                if(count > 1){
                    ostringstream oss;
                    oss << num;
                    string number = oss.str();
                    return "multiple " + number + "s in " + squarePrint(rowStart,colStart);
                }
                count = 0;
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
    int iline;
    looping = true;
    while(looping)
    {
        //getline(puzzles,puzzleNumber);
        puzzles >> puzzleNumber;

        if(!puzzles.good())
        {
            looping = false;
            cout << "Breaking";
            break;
        }
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

        for(int i =0;i<9;i++)
        {
            for(int j =0;j<9;j++)
            {
                cout << sudoku[(i*9) + j];
            }
            cout << endl;
        }
        cout << endl;


        //solutions << puzzleNumber << endl;
        string rows = checkRows(sudoku);
        if( rows != "")
        {
            solutions << puzzleNumber << "    Invalid    " << rows << endl;
        }
        else{
            string columns = checkColumns(sudoku);
            if(columns != ""){
                solutions << puzzleNumber << "    Invalid    " << columns << endl;
            }
            else{
                string squares = checkSquares(sudoku);

                if(squares != "")
                {
                    solutions << puzzleNumber << "    Invalid    " << squares << endl;
                }
                else{
                    solutions << puzzleNumber << "    Valid" << endl;
                }
            }
        }
        //getline(puzzles,puzzleNumber);
        //cout << endl << "line: " << puzzles << endl;
    }




    return 0;
}
