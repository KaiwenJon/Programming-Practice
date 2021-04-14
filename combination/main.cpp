
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
void backtrack(vector<vector<int>> &res, vector<int> &output, int head, vector<int> &array, int k)
{
    if (k == 0)
    {
        res.push_back(output);
        // cout << endl;
    }
    for (int i = head; i < array.size(); i++)
    {
        // cout << head;
        output.push_back(array[i]);
        backtrack(res, output, i + 1, array, k - 1);
        output.pop_back();
    }
}

vector<vector<int>> combine(vector<int> array, int k)
{
    vector<vector<int>> res;
    vector<int> output;
    backtrack(res, output, 0, array, k);
    return res;
}

int main(int argc, char **argv)
{
    // Construct the objects
    vector<int> numbers;
    int n = 5;
    int k = 3;
    cout << "Combination: " << k << " out of " << n << " objects " << endl;
    cout << "objects array: ";
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        numbers.push_back(i);
    }
    cout << endl;

    vector<vector<int>> result = combine(numbers, k);
    for (int i = 0; i < result.size(); i++)
    {
        vector<int> element = result[i];
        printVector(element);
        cout << endl;
    }

    system("PAUSE");
}