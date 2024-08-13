#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

 vector<int> solution(vector<int> &A,int N){
     int n = A.size();
     vector <int> counter(N);
     for(int i=0;i<n;i++){
        if(A[i]<=N){
        counter[A[i]-1]+=1;
        }
        else{
            int max=*max_element(counter.begin(), counter.end());
            fill(counter.begin(),counter.end(),max);
        }
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
