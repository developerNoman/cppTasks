#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> &A)
{
    size_t length = A.size();
    size_t intersections = 0;

    for (size_t index = 0; index < length; ++index)
    {
        for (size_t nextIndex = index + 1; nextIndex < length; ++nextIndex)
        {
            if (A[index] + A[nextIndex] >= nextIndex - index)
            {
                ++intersections;

                if (intersections > 10000000)
                {
                    return -1;
                }
            }
        }
    }

    return intersections;
}

int main()
{
    vector<int> A = {1, 5, 2, 1, 4, 0};
    cout << "The result is: " << solution(A) << endl;
    return 0;
}

// if (i + A[i] >= j - A[j]) && (j + A[j] >= i - A[i])