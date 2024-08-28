// // #include <iostream>
// // #include <vector>
// // #include <climits>
// // #include <algorithm>
// // using namespace std;

// //  int solution(vector<int> &A, int n){
// //          int count=0;
// //         for(int i=0;i<n-1;i++){
// //         for(int j=i+1;j<n;j++){
// //             if(A[i]>A[j]){
// //                 count++;
// //             }
// //             else if(A[i]<=A[j]){
// //                 break;
// //             }
// //     }
// //     }
// //     return count;
// // }

// // int main()
// // {
// //     vector<int> A={4,3,4,4,4,2};
// //     int n = A.size();
// //     cout << "The result is : " << solution(A, n) << endl;
// //     return 0;
// // }
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;

// int solution(vector<int>& A) {
//     // for (int num : A) {
//     //     if (size == 0) {
//     //         candidate = num;
//     //         size++;
//     //     } else {
//     //         if (num == candidate) {
//     //             size++;
//     //         } else {
//     //             size--;
//     //         }
//     //     }
//     // }
//        int n = A.size();
    
//     sort(A.begin(), A.end());
    

//     int candidate = A[n / 2];
    
    
//     int count = 0;
//     for (int num : A) {
//         if (num == candidate) {
//             count++;
//         }
//     }
//     int leader = -1;

//     if (count > n / 2) {
//        leader=candidate;
//     } else {
//         return -1; 
//     }
//     // If there's no leader, return 0
//     if (leader == -1) return 0;
    
//     int equiLeaders = 0;
//     int leftLeaderCount = 0;
//     int totalLeaderCount = 0;
    
//     // Count total occurrences of the leader
//     for (int num : A) {
//         if (num == leader) {
//             totalLeaderCount++;
//         }
//     }
    
//     // Traverse the array and count equi leaders
//     for (int i = 0; i < n; i++) {
//         if (A[i] == leader) {
//             leftLeaderCount++;
//         }
//         int leftSize = i + 1;
//         int rightSize = n - leftSize;
        
//         // Check if the leader is the majority in both parts
//         if (leftLeaderCount > leftSize / 2 && 
//             (totalLeaderCount - leftLeaderCount) > rightSize / 2) {
//             equiLeaders++;
//         }
//     }
    
//     return equiLeaders;
// }

#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int solution(vector<int> &A) {
    int n = A.size();
    
    sort(A.begin(), A.end());
    
    int candidate = A[n / 2];
    
    int count = 0;
    for (int num : A) {
        if (num == candidate) {
            count++;
        }
    }
    
    if (count <= n / 2) {
        return 0;
    }
    
    int leader = candidate;
    int leftLeaderCount = 0;
    int rightLeaderCount = count;
    int equiLeaders = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (A[i] == leader) {
            leftLeaderCount++;
            rightLeaderCount--;
        }
        
       
        if (leftLeaderCount > (i + 1) / 2 && rightLeaderCount > (n - i - 1) / 2) {
            equiLeaders++;
        }
    }
    
    return equiLeaders;
}

int main() {
    vector<int> A = {4, 3, 4, 4, 4, 2};
    cout << "The number of equi leaders is: " << solution(A) << endl;
    return 0;
}

