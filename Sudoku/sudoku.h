#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

class Sudoku
{
private:
    int row[9];
    int col[9];
    int block[3][3];
    vector<pair<int, int>> spaces;
    bool valid;

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        initializeBit(board);
        fillNum(board, 0);
    }

    void updateBit(int i, int j, int digit)
    {
        row[i] ^= (1 << (digit - 1));
        col[j] ^= (1 << (digit - 1));
        block[i / 3][j / 3] ^= (1 << (digit - 1));
    }
    int findLowestOne(int x)
    {
        x = x & (-x);
        return __builtin_ctz(x) + 1;
    }
    void fillNum(vector<vector<char>> &board, int fillPos)
    {
        if (fillPos == spaces.size())
        {
            valid = true;
            return;
        }
        int i = spaces[fillPos].first;
        int j = spaces[fillPos].second;
        int possiblePos = ~(row[i] | col[j] | block[i / 3][j / 3]) & 0x1ff;
        int digit;
        for (; possiblePos && !valid; possiblePos ^= (1 << (digit - 1)))
        {
            digit = findLowestOne(possiblePos);
            board[i][j] = digit + '0';
            updateBit(i, j, digit);
            fillNum(board, fillPos + 1);
            updateBit(i, j, digit);
        }
    }
    void initializeBit(vector<vector<char>> &board)
    {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(block, 0, sizeof(block));
        valid = false;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '_')
                {
                    spaces.emplace_back(i, j);
                }
                else
                {
                    int existDigit = board[i][j] - '0';
                    updateBit(i, j, existDigit);
                }
            }
        }
    }
};