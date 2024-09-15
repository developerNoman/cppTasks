#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// function to find maximum sum of a compact subsequence of array elements.
int solution(vector<int> &A)
{
    int length = A.size();
    if (length == 2)
    {
        return max(A[0], max(A[1], A[0] + A[1]));
    }

    int maxSum = A[0];
    int currentSum = A[0];

    for (int index = 1; index < length; index++)
    {
        currentSum = max(A[index], currentSum + A[index]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
int main()
{
    vector<int> A = {3, 2, -6, 4, 0};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}
