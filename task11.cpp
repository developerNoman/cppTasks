#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

//function to find maximum sum of a compact subsequence of array elements.
int solution(vector<int> &A) {
    int length = A.size();
    if (length == 2) {
        return max(A[0],max(A[1], A[0]+A[1]));
    }

    int maxSum = A[0];
    int currentSum = A[0];

    for (int index = 1; index < length; i++) {
        currentSum = max(A[i], currentSum + A[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}
int main()
{
    vector<int> A={3,2,-6,4,0};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}


// int solution(vector<int> &A) {
//      int n=A.size(); 
//     if (n == 2) {
//         return A[0] + A[1];
//     }

//     int maxSum = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         int sum = 0;
//         for (int j = i; j < n; j++) {
//             sum += A[j];
//             maxSum = max(maxSum, sum);
//         }
//     }

//     return maxSum;
// }

// int solution(vector<int> &A) {
//     int n = A.size();
//     if (n == 2) {
//         return max(A[0],max(A[1], A[0]+A[1]));
//     }
//  vector<int> A={3,2,-6,4,0};
//     int maxSum = A[0];//3
//     int currentSum = A[0];//3

//     for (int i = 1; i < n; i++) {
//         currentSum = max(A[i], currentSum + A[i]);//(2,5)->5,(-6,-1)->-1,(4,3)->4,(0,4)->4
//         maxSum = max(maxSum, currentSum);//(3,5)->5,(5,-1)->5,(5,4)->5,(5,4)------->5
//     }
//     return maxSum;
// }