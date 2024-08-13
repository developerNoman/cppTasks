#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

 int solution(vector<int> &A, int n){
        int avg = 0;
        int sum=0;
        int count=0;
        int minavg=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
    for(int k=i; k<=j; k++){
        sum +=A[k];
        count++;
    }
    avg=sum/count;
    minavg=min(avg,minavg);
    avg=0;
    }
    }
     return minavg;
}

int main()
{
    vector<int> A={4,2,2,5,1,5,8};
    // vector<int> A={1,1,2,5,1,5,8};
    int n = A.size();
    cout << "The result is : " << solution(A, n) << endl;
    return 0;
}
