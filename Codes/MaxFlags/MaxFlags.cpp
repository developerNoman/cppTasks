#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// function to find the maximum flags that are set on peaks
int solution(vector<int> &A)
{
    vector<int> peaks;
    int length = A.size();

    for (int index = 1; index < length - 1; index++)
    {
        if (A[index] > A[index - 1] && A[index] > A[index + 1])
        {
            peaks.push_back(index);
        }
    }

    if (peaks.size() == 0)
    {
        return 0;
    }

    int maxFlags = 1;
    int leftSide = 1;
    int rightSide = peaks.size();

    while (leftSide <= rightSide)
    {
        int currentFlags = (leftSide + rightSide) / 2;
        int flags = 1;
        int lastFlag = peaks[0];

        for (int i = 1; i < rightSide; i++)
        {
            if (peaks[i] - lastFlag >= currentFlags)
            {
                flags++;
                lastFlag = peaks[i];
                if (flags == currentFlags)
                {
                    break;
                }
            }
        }

        if (flags >= currentFlags)
        { // 3<4
            maxFlags = currentFlags;
            leftSide = currentFlags + 1;
        }
        else
        {
            rightSide = currentFlags - 1;
        }
    }

    return maxFlags;
}

int main()
{

    vector<int> A = {1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
    cout << "The result is : " << solution(A) << endl;
    return 0;
}
