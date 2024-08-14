#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> &A){
   int n=A.size();
    vector<int>  result(n,0);
    int count=0;
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && A[i]%A[j]!=0){
                result[i]++;
            }
    }
    }
    return result;
}

int main()
{
    vector<int> A={3,1,2,3,6};
    vector<int> result = solution(A);
    cout << "The result is: [ ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << "]" << endl;
    return 0;
}


// vector<int> solution(vector<int> &A){
//    int n=A.size();
//     vector<int>  result(n,0);
//     int count=0;
//         for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(A[i]%A[j]!=0){
//                 count++;
//             }
//     }
//             result.push_back(count);
//             count=0;
//     }
//     return result;
// }