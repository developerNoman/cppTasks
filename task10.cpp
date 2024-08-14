// #include <iostream>
// #include <vector>
// #include <climits>
// #include <algorithm>
// using namespace std;

//  int solution(vector<int> &A, int n){
//          int count=0;
//         for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(A[i]>A[j]){
//                 count++;
//             }
//             else if(A[i]<=A[j]){
//                 break;
//             }
//     }
//     }
//     return count;
// }

// int main()
// {
//     vector<int> A={4,3,4,4,4,2};
//     int n = A.size();
//     cout << "The result is : " << solution(A, n) << endl;
//     return 0;
// }
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int>& A) {
    int n = A.size();
    int size = 0, candidate = -1;

    // Step 1: Find the candidate for leader
    for (int num : A) {
        if (size == 0) {
            candidate = num;
            size++;
        } else {
            if (num == candidate) {
                size++;
            } else {
                size--;
            }
        }
    }

    // Step 2: Verify if candidate is actually the leader
    int leader = -1, leaderCount = 0;
    for (int num : A) {
        if (num == candidate) {
            leaderCount++;
        }
    }

    if (leaderCount > n / 2) {
        leader = candidate;
    } else {
        return 0;  // No leader, so no equi leaders
    }

    // Step 3: Count equi leaders
    int equiLeaders = 0, leftLeaderCount = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == leader) {
            leftLeaderCount++;
        }

        int leftSize = i + 1;
        int rightSize = n - leftSize;

        if (leftLeaderCount > leftSize / 2 && (leaderCount - leftLeaderCount) > rightSize / 2) {
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

