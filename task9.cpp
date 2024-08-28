#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the most frequent element
int solution(vector<int> &A) {
    unordered_map<int, int> freqMap; 
    int dominator = -1;
    int maxFrequency = 0;
    
    int length=A.size();
    for (int index=0; index<length;index++) {
        int num = A[index];
        freqMap[num]++;
        if (freqMap[num] > maxFrequency) {
            maxFrequency = freqMap[num];
            dominator = num;
        }
    }
    

    return dominator;
}

int main() {
    vector<int> A = {3, 4, 3, 2, 3, -1, 3, 3};
    int dominator = solution(A);
    cout << "The dominator are at: ";
        for (int i = 0; i < A.size(); i++) {
        if (A[i] == dominator) {
            cout << i << " ";
        }
    }
    
    return 0;
}





// int solution(vector<int> &A, int n){
//       unordered_inputMap<int, int> inputMap; 
//     int num;
//     int maxFreq = 0;
//     for(int i = 0; i < n; i++){
//         if(inputMap.count(A[i]) > 0){
//             inputMap[A[i]]++;
//         } else {
//             inputMap[A[i]] = 1;
//         }
//         if(inputMap[A[i]] > maxFreq){
//             maxFreq = inputMap[A[i]];
//             num = A[i];
//             return
//         }
//     }
//     return num;
// }

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// using namespace std;

// //function use to find dominator(most occuring number)
// int solution(vector<int> &A) {
//     int length = A.size();
//     unordered_map<int, int> inputMap; 
//     int dominator = -1;
//     int maxFreq = 0;
    
//     for (int i = 0; i < length; i++) {
//         inputMap[A[i]]++;   //3-->1,
//         if (inputMap[A[i]] > maxFreq) {
//             maxFreq = inputMap[A[i]];
//             dominator = A[i];
//         }
//     }

//     if (maxFreq > length / 2) {
//         for (int i = 0; i < length; i++) {
//             if (A[i] == dominator) {
//                    return dominator;
//             }
//         }
//     }
    
//     return -1;
// }
// int main() {
//     vector<int> A = {3, 4, 3, 2, 3, -1, 3, 3};
//     int result = solution(A);
//     cout << "The result is: " ;
//     for(int i=0;i<A.size();i++){
//         if(A[i]==result){
//             cout<<i<<" ";
//         }
//     }
//     return 0;
// }