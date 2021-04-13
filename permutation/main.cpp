
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

void printVector(vector<int> element)
{
    for (int i = 0; i < element.size(); i++)
    {
        cout << element[i] << " ";
    }
}

void backtrack(vector<vector<int>> &res, vector<int> &output, int head, int len)
{
    if (head == len)
    {
        res.push_back(output);
        return;
    }
    for (int i = head; i < len; i++)
    {
        swap(output[i], output[head]);
        backtrack(res, output, head + 1, len);
        swap(output[i], output[head]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    backtrack(res, nums, 0, (int)nums.size());
    return res;
}

int main(int argc, char **argv)
{
    // Construct the objects
    vector<int> numbers;
    ;
    int total = 6;
    for (int i = 0; i < total; i++)
    {
        numbers.push_back(i);
    }

    vector<vector<int>> result = permute(numbers);
    for (int i = 0; i < result.size(); i++)
    {
        vector<int> element = result[i];
        printVector(element);
        cout << endl;
    }

    system("PAUSE");
}