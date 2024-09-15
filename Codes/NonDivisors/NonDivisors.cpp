#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

// Function to find the non-divisors of every number in an array
vector<int> solution(vector<int> &A)
{
    int length = A.size();
    unordered_map<int, int> result;

    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<int>());
    int count = 0;
    int current = 0;
    int i, j;

    for (i = 0; i < length; ++i)
    {
        current = sortedA[i];
        if (result.find(current) == result.end())
        {
            count = i;

            for (j = i + 1; j < length; ++j)
            {

                if (current % sortedA[j] != 0)
                {
                    ++count;
                }
            }

            result[current] = count;
        }
    }

    for (i = 0; i < length; i++)
    {
        A[i] = result[A[i]];
    }

    return A;
}
int main()
{
    vector<int> A = {3, 1, 2, 3, 6}; // 1,2,3,3,6
    vector<int> result = solution(A);

    for (int r : result)
    {
        cout << r << " ";
    }

    return 0;
}

// vector<int> solution(vector<int> &A)
// {
//     int length = A.size();

//     vector<int> sortedA = A;
//     sort(sortedA.begin(), sortedA.end(), greater<int>());

//     vector<int> result(length, 0);

//     int count = 0;
//     for (int i = 0; i < length; ++i)
//     {
//         int current = sortedA[i];

//         if (i > 0 && current == sortedA[i - 1])
//         {
//             continue;
//         }

//         count = i;
//         for (int j = i + 1; j < length; ++j)
//         {
//             if (current % sortedA[j] != 0)
//             {
//                 ++count;
//             }
//         }
//         for (int k = 0; k < length; ++k)
//         {
//             if (A[k] == current)
//             {
//                 result[k] = count;
//             }
//         }
//     }

//     return result;
// }

// vector<int> solution(vector<int> &A)
// {
//     int length = A.size();
//     unordered_map<int, int> result;

//     vector<int> sortedA = A;
//     sort(sortedA.begin(), sortedA.end(), greater<int>());
//     int count = 0;
//     int current = 0;
//     int i, j;

//     for (i = 0; i < length; ++i)
//     {
//         current = sortedA[i];
//         if (result.find(current) == result.end())
//         {
//             count = i;

//             for (j = i + 1; j < length; ++j)
//             {

//                 if (current % sortedA[j] != 0)
//                 {
//                     ++count;
//                 }
//             }

//             result[current] = count;
//         }
//     }

//     for (i = 0; i < length; i++)
//     {
//         A[i] = result[A[i]];
//     }

//     return A;
// }