#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> &A) {
    int n=A.size();
    if (n <= 1) return 0; 
    
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += A[i];
    }
    int minimumResult = abs(A[0]-(totalSum-A[0])); 
    int sum1 = 0; 
    
    for (int k = 0; k < n - 1; k++) {
        sum1 += A[k];
        int sum2 = totalSum - sum1;
        int result = abs(sum1 - sum2);
        if (result < minimumResult) {
            minimumResult = result;
        }
    }
    
    return minimumResult;
}

int main()
{
    vector<int> A={3,1,2,4,3};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}

//  int solution(vector<int> &A, int n){
//     int minimumResult=0;
//      for(int k=1;k<n;k++){
//         int sum1 = 0, sum2 = 0;
//     for(int i=0; i<k; i++){
//         sum1 += A[i];
//     }
//     for(int i=k; i<n; i++){
//         sum2 += A[i];
//     }
//     if(k==1){
//         minimumResult=abs(sum1-sum2);
//     }
//     int result=abs(sum1-sum2);
//        if(result<minimumResult){
//         minimumResult=result;
//        }
//     }
//     return minimumResult;
// }