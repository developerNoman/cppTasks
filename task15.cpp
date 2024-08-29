#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;

//function used to find the non divisors of all elements in array

// vector<int> solution(vector<int> &A) {
//     int length = A.size();
//     unordered_map<int, int> result;

//     vector<int> sortedA = A;
//     sort(sortedA.begin(), sortedA.end(), greater<int>());

//     for (int i = 0; i < length; ++i) {
//         if (result.find(sortedA[i]) == result.end()) {
//             int count = 0;
//             for (int j = i+1; j < length; ++j) {
//                 if (sortedA[i] % sortedA[j] != 0) {
//                     ++count;
//                 }
//             }
//             result[sortedA[i]] = count;
//         }
//     }


std::vector<int> solution(std::vector<int> &A) {
    int length = A.size();
    std::unordered_map<int, int> result;

    std::vector<int> sortedA = A;
    std::sort(sortedA.begin(), sortedA.end(), std::greater<int>());

    for (int i = 0; i < length; ++i) {
        if (result.find(sortedA[i]) == result.end()) {
            int count = 0;

            // Count non-divisors for sortedA[i]
            for (int j = i + 1; j < length; ++j) {
                if (sortedA[i] % sortedA[j] != 0) {
                    ++count;
                }
            }

            // Include the count of non-divisors from previous iterations
            if (i > 0) {
                count += result[sortedA[i-1]];
            }

            result[sortedA[i]] = count;
        }
    }

    for (int i = 0; i < length; i++) {
        A[i] = result[A[i]];
    }

    return A;
}


//     for (int i = 0; i < length; i++) {
//         A[i] = result[A[i]];
//     }

//     return A;
// }

int main()
{
    vector<int> A = {3, 1, 2, 3, 6};//6,3,3,2,1
    vector<int> result = solution(A);
    cout << "The result is: [ ";
    for (int i : result)
    {
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


// vector<int> solution(vector<int> &A){
//    int n = A.size();
//    vector<int> B=A;
//     unordered_map<int, int> result;
//     sort(A.begin(), A.end(), greater<int>());
//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (i != j && A[i] % A[j] != 0)
//             {
//                 count++;
//             }
//         }
//         result[A[i]] = count;
//     }
//   for (auto it = result.begin(); it != result.end(); it++)
// {
//     int val = it->first;
//     int count = it->second;
//     for (int i = 0; i < B.size(); i++)
//     {
//         if (B[i] == val || B[i-1]==val)
//         {
//             B[i] = count;
//         }
//     }
// }
//     return B;
//  }  







// vector<int> solution(vector<int> &A) {
//     int n = A.size();
//     int maxElem = *max_element(A.begin(), A.end());
    
//     vector<int> frequency(maxElem + 1, 0);
//     vector<int> nonDivisors(maxElem + 1, n);
    
//     for (int i = 0; i < n; i++) {
//         frequency[A[i]]++;
//     }
    

//     for (int i = 1; i <= maxElem; i++) {
//         if (frequency[i] > 0) {
//             for (int j = i; j <= maxElem; j += i) {
//                 nonDivisors[j] -= frequency[i];
//             }
//         }
//     }
    
//     for (int i = 0; i < n; i++) {
//         A[i] = nonDivisors[A[i]];
//     }
    
//     return A;
// }


// vector<int> solution(vector<int>& A) {
//     int n = A.size();
//     unordered_map<int, int> freq;
//     for (int num : A) {
//         freq[num]++;
//     }
    
//     vector<intvector<int> solution(vector<int>& A) {
//     int n = A.size();
//     unordered_map<int, int> freq;
//     for (int num : A) {
//         freq[num]++;
//     }
    
//     vector<int> result(n, 0);
    
//     for (int i = 0; i < n; ++i) {
//         int num = A[i];
//         int divisor_count = 0;
        
//         for (int j = 1; j <= sqrt(num); ++j) {
//             if (num % A[j] == 0) {
//                 divisor_count += freq[A[j]];
//                 if (A[j] != num / A[j]) {
//                     divisor_count += freq[num / A[j]];
//                 } 
//                 }
//             }
//         result[i] = n - divisor_count;
//     }
    
//     return result;
// }> result(n, 0);
    
//     for (int i = 0; i < n; ++i) {
//         int num = A[i];
//         int divisor_count = 0;
        
//         for (int j = 1; j <= sqrt(num); ++j) {
//             if (num % A[j] == 0) {
//                 divisor_count += freq[A[j]];
//                 if (A[j] != num / A[j]) {
//                     divisor_count += freq[num / A[j]];
//                 } 
//                 }
//             }
//         result[i] = n - divisor_count;
//     }
    
//     return result;
// }