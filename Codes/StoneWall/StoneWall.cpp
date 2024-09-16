#include <iostream>
#include <vector>
using namespace std;

// function to find the minimum number of blocks for making the stone wall.
int solution(const vector<int> &A)
{
    int length = A.size();
    vector<int> blocks;
    int totalBlocks = 0;

    for (int height = 0; height < length; height++)
    {
        while (!blocks.empty() && blocks.back() > A[height])
        {
            blocks.pop_back();
        }

        if (blocks.empty() || blocks.back() < A[height])
        {
            blocks.push_back(A[height]);
            totalBlocks++;
        }
    }

    return totalBlocks;
}

int main()
{
    vector<int> A = {8, 8, 5, 7, 9, 8, 7, 4, 8};
    cout << "The result is: " << solution(A) << endl;
    return 0;
}
