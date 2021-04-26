
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <unordered_set>
using namespace std;

void generateBoard(vector<vector<string>> &solutions, vector<int> &queens)
{
    auto board = vector<string>();
    for (int i = 0; i < queens.size(); i++)
    {
        string row = string(queens.size(), '.');
        row[queens[i]] = 'Q';
        board.push_back(row);
    }

    solutions.push_back(board);
}
void backtrack(vector<vector<string>> &solutions, vector<int> &queens, unordered_set<int> &columns, unordered_set<int> &diag1, unordered_set<int> &diag2, int row, int n)
{
    if (row == n)
    {
        generateBoard(solutions, queens);
    }
    for (int i = 0; i < n; i++)
    {
        if (columns.find(i) != columns.end())
        {
            // queen already in this column.
            continue;
        }
        if (diag1.find(row - i) != diag1.end())
        {
            // queen already in this diag1
            continue;
        }
        if (diag2.find(row + i) != diag2.end())
        {
            // queen already in this diag2
            continue;
        }

        // otherwise, place one queen at i!
        queens[row] = i;
        columns.insert(i);
        diag1.insert(row - i);
        diag2.insert(row + i);
        backtrack(solutions, queens, columns, diag1, diag2, row + 1, n);
        queens[row] = -1;
        columns.erase(i);
        diag1.erase(row - i);
        diag2.erase(row + i);
    }
}
vector<vector<string>> solveNQueens(int n)
{
    auto solutions = vector<vector<string>>();
    auto queens = vector<int>(n, -1); // n ints with value 0
    auto columns = unordered_set<int>();
    auto diag1 = unordered_set<int>(); // row + col = k2
    auto diag2 = unordered_set<int>(); // row - col = k1
    int row = 0;
    backtrack(solutions, queens, columns, diag1, diag2, row, n);
    // generateBoard(solutions, queens);
    return solutions;
}
int main(int argc, char **argv)
{
    int N = 8;
    vector<vector<string>> solutions = solveNQueens(N);
    for (int i = 0; i < solutions.size(); i++)
    {
        cout << "board " << i << ": " << endl;
        vector<string> board = solutions[i];
        for (int row = 0; row < N; row++)
        {
            cout << board[row] << endl;
        }
        cout << endl;
    }

    system("PAUSE");
}