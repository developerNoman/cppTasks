#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(vector<int>& A) {
    int size;
    for (int num : A) {
        if (size == 0) {
            leadingNumber = num;
            size++;
        } else {
            if (num == leadingNumber) {
                size++;
            } else {
                size--;
            }
        }
    }
       int n = A.size();
    
    sort(A.begin(), A.end());
    

    int leadingNumber = A[n / 2];
    
    
    int count = 0;
    for (int num : A) {
        if (num == leadingNumber) {
            count++;
        }
    }
    int leader = -1;

    if (count > n / 2) {
       leader=leadingNumber;
    } else {
        return -1; 
    }
    // If there's no leader, return 0
    if (leader == -1) return 0;
    
    int equiLeaders = 0;
    int leftLeaderCount = 0;
    int totalLeaderCount = 0;
    
    // Count total occurrences of the leader
    for (int num : A) {
        if (num == leader) {
            totalLeaderCount++;
        }
    }
    
    // Traverse the array and count equi leaders
    for (int i = 0; i < n; i++) {
        if (A[i] == leader) {
            leftLeaderCount++;
        }
        int leftSize = i + 1;
        int rightSize = n - leftSize;
        
        // Check if the leader is the majority in both parts
        if (leftLeaderCount > leftSize / 2 && 
            (totalLeaderCount - leftLeaderCount) > rightSize / 2) {
            equiLeaders++;
        }
    }
    
    return equiLeaders;
}

// #include <vector>
// #include <algorithm>
// #include<iostream>
// using namespace std;

// int solution(vector<int> &A) {
//     int n = A.size();
    
//     sort(A.begin(), A.end());
    
//     int leadingNumber = A[n / 2];
    
//     int count = 0;
//     for (int num : A) {
//         if (num == leadingNumber) {
//             count++;
//         }
//     }
    
//     if (count <= n / 2) {
//         return 0;
//     }
    
//     int leader = leadingNumber;
//     int leftLeaderCount = 0;
//     int rightLeaderCount = count;
//     int equiLeaders = 0;
    
//     for (int i = 0; i < n - 1; i++) {
//         if (A[i] == leader) {
//             leftLeaderCount++;
//             rightLeaderCount--;
//         }
        
       
//         if (leftLeaderCount > (i + 1) / 2 && rightLeaderCount > (n - i - 1) / 2) {
//             equiLeaders++;
//         }
//     }
    
//     return equiLeaders;
// }

// int main() {
//     vector<int> A = {4, 3, 4, 4, 4, 2};
//     cout << "The number of equi leaders is: " << solution(A) << endl;
//     return 0;
// }

