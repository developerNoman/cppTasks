#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    int n = A.size();
    if (n < 3) return 0;
    sort(A.begin(), A.end());
     
     for (int i = 0; i < n - 2; ++i) {
      // if (A[i] + A[i + 1] > A[i + 2]) {
        if (static_cast<long long>(A[i]) + A[i + 1] > A[i + 2]) {
            return 1;
        }
    }

    return 0;
}
int main()
{
    vector<int> A={10,2,5,1,8,20};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}


// int solution(vector<int> &A){
//         int n=A.size();
//         for(int i=0;i<n-2;i++){
//         for(int j=i+1;j<n-1;j++){
//         for(int k=j+1; k<n; k++){
//           if((A[i]+A[j]>A[k]) && (A[j]+A[k]>A[i]) && (A[i]+A[k]>A[j])){
//             return 1;
//           }
//     }
//     }
//     }
//     return 0;
// }