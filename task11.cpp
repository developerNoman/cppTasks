#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

 int solution(vector<int> &A, int n){
        int sum=0;
        int count=0;
        int maxSum=0;
    for(int i=0;i<n;i++){
     for(int j=i+1;j<=n;j++){
    for(int k=i; k<=j; k++){
        sum +=A[k];
    }
    maxSum=max(sum,maxSum);
    sum=0;
    }
    }
     return maxSum;
}

int main()
{
    vector<int> A={3,2,-6,4,0};
    int n = A.size();
    cout << "The result is : " << solution(A, n) << endl;
    return 0;
}
