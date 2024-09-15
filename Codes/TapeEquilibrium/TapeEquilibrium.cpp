#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to return the minimum absolute difference between the sum of the first part and the sum of the second part.
int solution(vector<int> &A)
{
    int length = A.size();

    if (length <= 1)
    {
        return 0;
    }

    int totalSum = 0;
    int sum1 = 0;

    for (int index = 0; index < length; index++)
    {
        totalSum += A[index];
    }

    int minimumResult = abs(A[0] - (totalSum - A[0]));

    for (int index = 0; index < length - 1; index++)
    {
        sum1 += A[index];
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
    vector<int> A = {3, 1, 2, 4, 3};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}
