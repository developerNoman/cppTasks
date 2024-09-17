#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to find maximum sum of a compact subsequence of array elements.
int solution(vector<int> &array)
{
    int length = array.size();

    if (length == 2)
    {
        return max(array[0], max(array[1], array[0] + array[1]));
    }

    int maxSum = array[0];
    int currentSum = array[0];

    // itereate in the array and pick the maximum sum from current index. Then pick the maximum sum from the overall array
    for (int index = 1; index < length; index++)
    {
        currentSum = max(array[index], currentSum + array[index]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main()
{
    vector<int> array = {3, 2, -6, 4, 0};
    cout << "The result is : " << solution(array) << endl;
    return 0;
}
