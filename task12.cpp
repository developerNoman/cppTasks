#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

//function to return maximum double slice sum
int solution(const vector<int> &A) {
    int length = A.size();
    if (length < 4) return 0; 

    vector<int> endPosition(length, 0);
    vector<int> startPosition(length, 0);

 
    for (int index = 1; index < length - 1; ++index) {
        endPosition[index] = max(0, endPosition[index - 1] + A[index]);
    }

    for (int index = length- 2; index> 0; --index) {
        startPosition[index] = max(0, startPosition[index + 1] + A[index]);
    }

    int maxSum= 0;
    for (int index = 1; index < length - 1; ++index) {
        maxSum = max(maxSum, endPosition[index - 1] + startPosition[index + 1]);
    }

    return maxSum;
}
int main()
{
    vector<int> A = {3, 2, 6, -1, 4, 5, -1, 2};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}

// int solution(vector<int> &A)
// {
//     int n = A.size();
//     int Sum=A[0];
//     int maxSum=A[0];
//     for (int i = 0; i < n - 2; i++)
//     {
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                Sum=A[i+1]+A[j+1]+A[k+1];
//                maxSum=max(Sum,maxSum);
//             }
//     }
// }
// return maxSum;
// }
