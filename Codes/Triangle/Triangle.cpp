#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// function to check a triangle can be built from a given set of edges.
int solution(vector<int> &A)
{
    int length = A.size();
    if (length < 3)
        return 0;
    sort(A.begin(), A.end());

    for (int index = 0; index < length - 2; ++index)
    {
        if (static_cast<long long>(A[index]) + A[index + 1] > A[index + 2])
        {
            return 1;
        }
    }

    return 0;
}
int main()
{
    vector<int> A = {10, 2, 5, 1, 8, 20};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}
