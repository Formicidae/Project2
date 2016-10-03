//Edward Bates emb160030 section 002
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
    //Loops through rows
    for(int i = 0;i < 9;i++)
    {
        //Loops through 1 through 9 to find duplicates
        for(int searchN = 1;searchN < 10;searchN++)
        {
            //Looks at each int in the row
            for(int j = 0;j < 9;j++)
            {
                //If it finds the number (searchN) that is it looking for it increases count
                if(*(sudokuPtr + (i*9) + j) == searchN){
                    count++;
                }
            }
            //If there are multiple of a value on the same line it prints the problem and gives rows number and numbers searched for
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
    //If there are no problems found a blank string is returned
    return "";
}

string checkColumns(int *sudokuPtr)
{
    int count = 0;
    //Loops through each column
    for(int i = 0;i < 9;i++)
    {
        //Loops through 1 through 9 to find duplicates
        for(int searchN = 1;searchN < 10;searchN++)
        {
            //Loops through going down the column
            for(int j = 0;j < 9;j++)
            {
                //If it finds the number its looking for count gets iterated
                if(*(sudokuPtr + (j*9) + i) == searchN){
                    count++;
                }
            }
            //If there are multiple of a value on the same line it prints the problem and gives rows number and numbers searched for
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
    //If no problems are found an empty string is returned
    return "";
}

//This method converts the int definition of which squares the error is in to a more readable string
string squarePrint(int r, int c)
{
    string output = "";
    //what set of rows the square is in
    switch(r){
        case 0: output += "Upper"; break;
        case 3: output += "Middle"; break;
        case 6: output += "Lower"; break;
    }
    //what set of columns the square is in
    switch(c){
        case 0: output += " Left"; break;
        case 3: output += " Middle"; break;
        case 6: output += " Right"; break;
    }
    return output;
}

string checkSquares(int *sudokuPtr)
{
    //This loops created the offset of the row start to read the square
    for(int rowStart = 0;rowStart < 7;rowStart += 3){
        //This loops created the offset of the column start to read the square
        for(int colStart = 0;colStart < 7;colStart += 3){
            int count = 0;
            //loops trough each 1 through 9 values
            for(int num = 1;num < 10;num++){
                //Loops through 3 row values starting from offset
                for(int r = rowStart; r < rowStart + 3;r++){
                    //Loops through 3 column values starting from offset
                    for(int c = colStart;c < colStart + 3;c++){
                        //if the desired number is found count is iterated
                        if(*(sudokuPtr + (r*9) + c) == num){
                            count++;
                        }
                    }
                }
                //If there are multiple of the same number is the square an string is return giving the number and location of square
                if(count > 1){
                    ostringstream oss;
                    oss << num;
                    string number = oss.str();
                    //square print is used to convert from row and column offset to a more readable string ex. "Upper Left"
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
    int* ptr = new int [81];
    ifstream puzzles("puzzles.txt");
    ofstream solutions("solutions.txt");
    bool looping;
    string puzzleNumber;
    string line;
    int iline;
    looping = true;
    //Loop through all given sudokus in the file
    while(looping)
    {
        //gets puzzle number as first line for output
        puzzles >> puzzleNumber;

        //Checks if the file is out of bounds. Effectively checking if its read all sudokus
        if(!puzzles.good())
        {
            looping = false;
            cout << "Program complete";
            break;
        }

        //Read sudoku in line by line, and then reads the line backwards with mod 10
        for(int i = 0; i < 9;i++)
        {
            puzzles >> iline;
            for(int j = 8; j > -1;j--)
            {
                *(ptr + (i*9) + (j)) = iline % 10;
                iline /= 10;
            }

        }

        //initiates the check of rows, if non-empty string is returned it is writtten to file and programs moves on
        string rows = checkRows(ptr);
        if( rows != "")
        {
            solutions << puzzleNumber << "    Invalid    " << rows << endl;
        }
        else{
            //If rows are valid it checks columns
            string columns = checkColumns(ptr);
            if(columns != ""){
                solutions << puzzleNumber << "    Invalid    " << columns << endl;
            }
            else{
                //If columns are good it checks squares
                string squares = checkSquares(ptr);

                if(squares != "")
                {
                    solutions << puzzleNumber << "    Invalid    " << squares << endl;
                }
                else{
                    //If no problems are found "Valid" is written to file
                    solutions << puzzleNumber << "    Valid" << endl;
                }
            }
        }
    }
    delete [] ptr;
    return 0;
}
