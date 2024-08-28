
// #include <iostream>
// #include <vector>
// #include <climits>
// #include <algorithm>
// using namespace std;

// int  solution(vector<int> &A, int n){
//     vector<int>  result;
//        for(int i=1;i<n-1;i++){
//          if(A[i]>A[i-1]&& A[i]>A[i+1]){
//             result.push_back(i);
//          }
//     }

// }

// int main()
// {

//     vector<int> A={1,2,3,4,3,4,1,2,3,4,6,2};
//     int n = A.size();
//     cout << "The result is : " << solution(A, n) << endl;
//     return 0;
// }


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> &A) {
    int n = A.size();
    vector<int> peaks;

    for (int i = 1; i < n - 1; ++i) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            peaks.push_back(i);
        }
    }

    if (peaks.empty()) return 0;


    int maxBlocks = 0;
    for (int K = 1; K <= n; ++K) {
        if (n % K == 0) { 
            int blockSize = n / K;
            int peakIndex = 0;
            bool valid = true;

            for (int i = 0; i < K; ++i) {
                bool blockHasPeak = false;
                while (peakIndex < peaks.size() && peaks[peakIndex] < (i + 1) * blockSize) {
                    if (peaks[peakIndex] >= i * blockSize) {
                        blockHasPeak = true;
                        break;
                    }
                    ++peakIndex;
                }
                if (!blockHasPeak) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                maxBlocks = max(maxBlocks, K);
            }
        }
    }

    return maxBlocks;
}

int main() {
    vector<int> A = {1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
    cout << "The result is: " << solution(A) << endl;
    return 0;
}












