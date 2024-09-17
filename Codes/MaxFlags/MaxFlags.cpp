#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// function to find the maximum flags that are set on peaks
int solution(vector<int> &array)
{
    vector<int> peaks;
    int length = array.size();

    // find the peak from the array and store the peak index in the peaks vector
    for (int index = 1; index < length - 1; index++)
    {
        if (array[index] > array[index - 1] && array[index] > array[index + 1])
        {
            peaks.push_back(index);
        }
    }

    int peakSize = peaks.size();

    if (peakSize == 0)
    {
        return 0;
    }

    int maxFlags = 1;
    int leftSide = 1;
    int rightSide = peakSize;

    // we have to move from leftside to the rightside of the peaks to place the flags on it. We should only place the flags on peaks it means the maximum flags should be equal to peak size.
    while (leftSide <= rightSide)
    {
        int currentFlags = (leftSide + rightSide) / 2;
        int flags = 1;
        int lastFlag = peaks[0];

        // iterate over the peaks. If the distance between the last peak of flag and current peak is greater than or equal to flags hodling. We can place the flags.
        for (int peakIndex = 1; peakIndex < peakSize; peakIndex++)
        {
            if (peaks[peakIndex] - lastFlag >= currentFlags)
            {
                flags++;
                lastFlag = peaks[peakIndex];
                if (flags == currentFlags)
                {
                    break;
                }
            }
        }

        if (flags >= currentFlags)
        {
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

    vector<int> array = {1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
    cout << "The result is : " << solution(array) << endl;
    return 0;
}
