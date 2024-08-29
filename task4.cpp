#include <iostream>
#include <vector>
#include <cfloat>
#include <algorithm>
using namespace std;

// function to find the minimal average of any slice containing at least two elements.
int solution(vector<int> &A) {
    int length = A.size();
    if (length < 2) return -1; 

    for(int i=0;i<length;i++){
 double minAvg = DBL_MAX;
 cout<<minAvg<<endl;
    }
    double minAvg = DBL_MAX;
    int minPos = 0;



    for (int index = 0; index < length - 1; ++index) {
        double avg = (A[index] + A[index + 1]) / 2.0;
        if (avg < minAvg) {
            minAvg = avg;
            minPos = index;
        }
    }

    for (int index= 0; index < length - 2; ++index) {
        double avg = (A[index] + A[index + 1] + A[index + 2]) / 3.0;
        if (avg < minAvg) {
            minAvg = avg;
            minPos = index;
        }
    }

    return minPos;
}

int main() {
    vector<int> A = {4, 2, 2, 5, 1, 5, 8};
    cout << "The result is: " << solution(A) << endl;
    return 0;
}




//  int solution(vector<int> &A, int n){
//         int avg = 0;
//         int sum=0;
//         int count=0;
//         int minavg=INT_MAX;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<=n;j++){
//     for(int k=i; k<=j; k++){
//         sum +=A[k];
//         count++;
//     }
//     avg=sum/count;
//     minavg=min(avg,minavg);
//     avg=0;
//     }
//     }
//      return minavg;
// }

// int solution(vector<int> &A) {
//     int size = A.size();
//     if (size < 2) return -1; 


//     double minAvg = DBL_MAX;
//     int minPos = 0;

//     for (int length = 2; length <= size; length++) {
//         for (int i = 0; i <= size - length; i++) {

//             double sum = 0;
//             for (int j = 0; j < length; j++) {
//                 sum += A[i + j];
//             }
//             double avg = sum / length;
//             if (avg < minAvg) {
//                 minAvg = avg;
//                 minPos = i;
//             }
//         }
//     }
//     return minPos;
// }