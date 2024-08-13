#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &A, int N) {
    int n = A.size();
    vector<int> counter(N, 0);
    int maxi = 0;
    int last_update = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] <= N) {
            int index = A[i] - 1;
            counter[index] = max(counter[index], last_update);
            counter[index]++;
            maxi = max(maxi, counter[index]);
        } else {
            last_update = maxi;
        }
    }

    // Apply last_update to all elements
    for (int i = 0; i < N; i++) {
        counter[i] = max(counter[i], last_update);
    }

    return counter;
}

int main()
{
    vector<int> A={3,4,4,6,1,4,4};
    int N=5;
    vector<int> result = solution(A,N);
    cout << "The result is: [ ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << "]" << endl;
    return 0;
}
//    (0, 0, 1, 0, 0)
//     (0, 0, 1, 1, 0)
//     (0, 0, 1, 2, 0)
//     (2, 2, 2, 2, 2)
//     (3, 2, 2, 2, 2)
//     (3, 2, 2, 3, 2)
//     (3, 2, 2, 4, 2)

//  vector<int> solution(vector<int> &A,int N){
//      int n = A.size();
//      vector <int> counter(N);
//      for(int i=0;i<n;i++){
//         if(A[i]<=N){
//         counter[A[i]-1]+=1;
//         }
//         else{
//             int max=*max_element(counter.begin(), counter.end());
//             fill(counter.begin(),counter.end(),max);
//         }
//      }
//      return counter;
// }

// vector<int> solution(vector<int> &A, int N) {
//     int n = A.size();
//     vector<int> counter(N, 0);
//     int maxi = 0;
//     for (int i = 0; i < n; i++) {
//         if (A[i] <= N) {
//             int temp = A[i] - 1;
//             counter[temp]++;
//             maxi = max(maxi, counter[temp]);
//         } else {
//             for (int j = 0; j < N; j++) {
//                 if(counter[j] < maxi){
//                 counter[j] = maxi;
//                 }
//             }
//         }
//     }
//     return counter;
// }