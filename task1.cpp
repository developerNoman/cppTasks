#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 int solution(vector<int> &A, int n){
    int minimumResult=0;
     for(int k=1;k<n;k++){
        int sum1 = 0, sum2 = 0;
    for(int i=0; i<k; i++){
        sum1 += A[i];
    }
    for(int i=k; i<n; i++){
        sum2 += A[i];
    }
    if(k==1){
        minimumResult=abs(sum1-sum2);
    }
    int result=abs(sum1-sum2);
       if(result<minimumResult){
        minimumResult=result;
       }
    }
    return minimumResult;
}

int main()
{
    vector<int> A={3,1,2,4,3};
    int n = A.size();
    cout << "The result is : " << solution(A, n) << endl;
    return 0;
}



// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int difference(int A[], int n, int k){
//     int sum1 = 0, sum2 = 0;
//     for(int i=0; i<k; i++){
//         sum1 += A[i];
//     }
//     for(int i=k; i<n; i++){
//         sum2 += A[i];
//     }
//     return abs(sum1 - sum2);
// }

// int main()
// {
//     int A[] = { 3,1,2,4,3 };
//     int n = sizeof(A)/sizeof(A[0]);
//     int k = 3;
//     cout << "The result is : " << difference(A, n, k) << endl;
//     return 0;
// }