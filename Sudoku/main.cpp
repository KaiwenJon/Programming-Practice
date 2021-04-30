
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "rapidcsv.h"
#include "sudoku.h"
using namespace std;

void printBoard(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
int main(int argc, char **argv)
{
    vector<vector<char>> board;
    rapidcsv::Document doc("./sudoku.csv", rapidcsv::LabelParams(-1, -1));
    for (int i = 0; i < 9; i++)
    {
        vector<char> row = doc.GetRow<char>(i);
        board.push_back(row);
    }

    cout << "Before: " << endl;
    printBoard(board);
    Sudoku solver;
    solver.solveSudoku(board);
    cout << "\nAfter: " << endl;
    printBoard(board);

    return 0;
}