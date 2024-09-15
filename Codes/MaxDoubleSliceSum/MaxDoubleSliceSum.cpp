#include <iostream>
#include <vector>
using namespace std;

// function to return maximum double slice sum. My approach is to find the sum from left side and right side separately and store in separate vector. Then at the end, simply ignore the index i because its not included in left side and right side. So we simply add most left side index value (index-1) and most right side index value (index+1)
int solution(vector<int> &A)
{
    int length = A.size();

    if (length <= 3)
    {
        return 0;
    }

    vector<int> leftSideSum(length, 0);
    vector<int> rightSideSum(length, 0);

    int tempMax = 0;
    int maxDoubleSliceSum = 0;

    for (int index = 1; index < length - 1; ++index)
    {
        tempMax = leftSideSum[index - 1] + A[index];
        if (tempMax > 0)
        {
            leftSideSum[index] = tempMax;
        }
    }

    for (int index = length - 2; index > 0; --index)
    {
        tempMax = rightSideSum[index + 1] + A[index];
        if (tempMax > 0)
        {
            rightSideSum[index] = tempMax;
        }
    }

    for (int index = 1; index < length - 1; ++index)
    {
        tempMax = leftSideSum[index - 1] + rightSideSum[index + 1];
        if (tempMax > maxDoubleSliceSum)
        {
            maxDoubleSliceSum = tempMax;
        }
    }

    return maxDoubleSliceSum;
}

int main()
{
    vector<int> A = {3, 2, 6, -1, 4, 5, -1, 2};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}
