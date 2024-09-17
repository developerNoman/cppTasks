#include <iostream>
#include <vector>
using namespace std;

// function to return maximum double slice sum. For example we have {3, 2, 6, -1, 4, 5, -1, 2}, its leftSide sum is {0, 2, 8, 7, 11, 16, 15, 0} and right side sum is {0, 16, 14, 8, 9, 5, 0, 0}. Overall Sum is ; max(0,0+14)=>14, max(14,2+8)=>14, max(14,8+9)=>17, max(17,7+5)=>17,max(17,11+0)=>17,max(17,16+0)=>17
int solution(vector<int> &array)
{
    int length = array.size();

    // if length is less than or equal to 3, there is no possibility to get double slice sum.
    if (length <= 3)
    {
        return 0;
    }

    vector<int> leftSideSum(length, 0);
    vector<int> rightSideSum(length, 0);

    int tempMax = 0;
    int maxDoubleSliceSum = 0;

    // find the sum from left side of the array separately and store in separate leftSideSum vector
    for (int index = 1; index < length - 1; ++index)
    {
        tempMax = leftSideSum[index - 1] + array[index];
        if (tempMax > 0)
        {
            leftSideSum[index] = tempMax;
        }
    }

    // find the sum from right side of the array separately and store in separate rightSideSum vector
    for (int index = length - 2; index > 0; --index)
    {
        tempMax = rightSideSum[index + 1] + array[index];
        if (tempMax > 0)
        {
            rightSideSum[index] = tempMax;
        }
    }

    // ignore the index "i" because its not included in left side and right side. So add most left side index value (index-1) and most right side index value (index+1) and check if it is greater than the previous maximum double slice sum.
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
    vector<int> array = {3, 2, 6, -1, 4, 5, -1, 2};
    cout << "The result is : " << solution(array) << endl;
    return 0;
}
