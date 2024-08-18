#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//function to find minimum number of blocks used to make the stone wall
int solution(vector<int> &A) {
    int length = A.size();
    stack<int> blocks;
    int totalBlocks = 0;

    for (int index = 0; index < length; index++) { 
        int height = A[index];

        while (!blocks.empty() && blocks.top() > height) {
            blocks.pop();
        }
        
        if (blocks.empty() || blocks.top() < height) {
            blocks.push(height);
            totalBlocks++;
        }
    }
    
    return totalBlocks;
}



int main()
{
    vector<int> A={8,8,5,7,9,8,7,4,8};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}



// }
// int solution(vector<int> &A) {
//     int n=A.size();
//     if(n==0){
//         return 0;
//     }
//     int count=0;
//     for(int i=0;i<n;i++){
//         for(int j=i+1;j>=0; j--)
//         if(A[j]!=A[i]){
//             count++;
//             break;
//         }
//     }

//     return count;
    
// }



// int solution(vector<int> &A) {
//     int n = A.size();
//     if(n == 0) {
//         return 0;
//     }
//     int count = 0;
//     stack<int> s;
//     for(int i = 0; i < n; i++) {
//         while(!s.empty() && s.top() < A[i]) {
//             s.pop();
//         }
//         if(s.empty()) {
//             count++;
//         }
//         s.push(A[i]);
//     }
//     return count;
// }


// int solution(vector<int> &A) {
//     int n=A.size();
//     stack<int> blocks;
//     int totalBlocks = 0;

//         for (int height=0;height<n;height++) {
//             while (!blocks.empty() && blocks.top() > A[height-1]) {
//                 blocks.pop();
//             }
//             if (blocks.empty() || blocks.top() < A[height-1]) {
//                 blocks.push(A[height-1]);
//                 totalBlocks++;
//             }
//     }=
//     return totalBlocks;
// }
