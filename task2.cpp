#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

//Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all counters to current maximummum.
vector<int> solution(vector<int> &A, int N) {
    int length = A.size();
    vector<int> counter(N, 0);
    int maximum = 0;
    int lastUpdated = 0;

    for (int i = 0; i < length; i++) {
        if (A[i] <= N) {
            int index = A[i] - 1;
            counter[index] = max(counter[index], lastUpdated);
            counter[index]++;
            maximum = max(maximum, counter[index]);
        } else {
            lastUpdated = maximum;
        }
    }
    for (int i = 0; i < N; i++) {
        counter[i] = max(counter[i], lastUpdated);
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
//     int maximum = 0;
//     for (int i = 0; i < n; i++) {
//         if (A[i] <= N) {
//             int temp = A[i] - 1;
//             counter[temp]++;
//             maximum = max(maximum, counter[temp]);
//         } else {
//             for (int j = 0; j < N; j++) {
//                 if(counter[j] < maximum){
//                 counter[j] = maximum;
//                 }
//             }
//         }
//     }
//     return counter;
// }

//   vector<int> A={3,4,4,6,1,4,4};
// vector<int> solution(vector<int> &A, int N) {
//     int length = A.size();
//     vector<int> counter(N, 0);
//     int maximum = 0;
//     int lastUpdated = 0;

//     for (int i = 0; i < length; i++) {
//         if (A[i] <= N) {
//             int index = A[i] - 1;//index 3->2  , index 4->3 , index 4->3 ,index 6->5 (now else),index 1->0
//             counter[index] = max(counter[index], lastUpdated);//(0,0), (0,0), (1,0),(0,2),(2,2),(3,2)
//             counter[index]++;// (0, 0, 1, 0, 0), (0, 0, 1, 1, 0) ,(0, 0, 1, 2, 0),(3,0,1,2,0),(3,0,1,3,0)(3,0,1,4,0)
//             maximum = max(maximum, counter[index]);//maximum=1 , maximum=1  , maximum=2,maximum=2
//         } else {
//             lastUpdated = maximum; //when index 6->5 => lastUpdated=2
//         }
//     }
//     for (int i = 0; i < N; i++) {
//         counter[i] = max(counter[i], lastUpdated);//(3,0,1,4,0)
//     }

//     return counter;
// }