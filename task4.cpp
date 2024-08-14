

#include <iostream>
#include <vector>
#include <cfloat>
#include <algorithm>
using namespace std;

// int solution(vector<int> &A) {
//     int n = A.size();
//     if (n < 2) return -1; 

//     double min_avg = DBL_MAX;
//     int min_pos = 0;


//     for (int i = 0; i < n - 1; ++i) {
//         double avg = (A[i] + A[i + 1]) / 2.0;
//         if (avg < min_avg) {
//             min_avg = avg;
//             min_pos = i;
//         }
//     }

//     for (int i = 0; i < n - 2; ++i) {
//         double avg = (A[i] + A[i + 1] + A[i + 2]) / 3.0;
//         if (avg < min_avg) {
//             min_avg = avg;
//             min_pos = i;
//         }
//     }

//     return min_pos;
// }
int solution(vector<int> &A) {
    int n = A.size();
    if (n < 2) return -1; 


    double min_avg = DBL_MAX;
    int min_pos = 0;

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {

            double sum = 0;
            for (int j = 0; j < length; j++) {
                sum += A[i + j];
            }
            double avg = sum / length;
            if (avg < min_avg) {
                min_avg = avg;
                min_pos = i;
            }
        }
    }

    return min_pos;
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

