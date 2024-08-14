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
            int index = A[i] - 1;//index 3->2  , index 4->3 , index 4->3 ,index 6->5 (now else),index 1->0
            counter[index] = max(counter[index], last_update);//(0,0), (0,0), (1,0),(0,2),(2,2),(3,2)
            counter[index]++;// (0, 0, 1, 0, 0), (0, 0, 1, 1, 0) ,(0, 0, 1, 2, 0),(3,0,1,2,0),(3,0,1,3,0)(3,0,1,4,0)
            maxi = max(maxi, counter[index]);//maxi=1 , maxi=1  , maxi=2,maxi=2
        } else {
            last_update = maxi; //when index 6->5 => last_update=2
        }
    }
    for (int i = 0; i < N; i++) {
        counter[i] = max(counter[i], last_update);//(3,0,1,4,0)
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