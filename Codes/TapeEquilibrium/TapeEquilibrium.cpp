#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to return the minimum absolute difference between the sum of the first part and the sum of the second part.
int solution(vector<int> &array)
{
    int length = array.size();

    if (length <= 1)
    {
        return 0;
    }

    int totalSum = 0;
    int sum1 = 0;

    // find the sum of all elements of the array
    for (int index = 0; index < length; index++)
    {
        totalSum += array[index];
    }

    int minimumResult = abs(array[0] - (totalSum - array[0]));

    // find the absolute difference between the sum of the first part and the sum of the second part. Find the sum1 using the next index added in previous sum. Find the sum2 by subtracting sum1 fromm total.
    for (int index = 0; index < length - 1; index++)
    {
        sum1 += array[index];
        int sum2 = totalSum - sum1;
        int result = abs(sum1 - sum2);
        if (result < minimumResult)
        {
            minimumResult = result;
        }
    }

    return minimumResult;
}

int main()
{
    vector<int> array = {3, 1, 2, 4, 3};
    cout << "The result is : " << solution(array) << endl;
    return 0;
}
