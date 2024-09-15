#include <iostream>
#include <vector>
using namespace std;

int solution(const vector<int> &A)
{
    int length = A.size();
    vector<int> blocks;
    int totalBlocks = 0;

    for (int height = 0; height < length; height++)
    {
        while (!blocks.empty() && blocks.back() > A[height])
        {
            blocks.pop_back();
        }

        if (blocks.empty() || blocks.back() < A[height])
        {
            blocks.push_back(A[height]);
            totalBlocks++;
        }
    }

    return totalBlocks;
}

int main()
{
    vector<int> A = {8, 8, 5, 7, 9, 8, 7, 4, 8};
    cout << "The result is: " << solution(A) << endl;
    return 0;
}

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
