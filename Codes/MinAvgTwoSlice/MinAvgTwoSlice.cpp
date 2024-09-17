#include <iostream>
#include <vector>
#include <cfloat>
#include <algorithm>
using namespace std;

// function to find the minimal average of any slice containing at least two elements.
int solution(vector<int> &array)
{
    int length = array.size();

    if (length < 2)
    {
        return -1;
    }

    double minAvg = DBL_MAX;
    int minPos = 0;

    // find the minimum average for every two elements and store the index in minPosition variable if there is a minimum average of some slice.
    for (int index = 0; index < length - 1; ++index)
    {
        double avg = (array[index] + array[index + 1]) / 2.0;
        if (avg < minAvg)
        {
            minAvg = avg;
            minPos = index;
        }
    }

    // find the minimum average for every three elements and store the index in minPosition variable if there is a minimum average of some slice.
    for (int index = 0; index < length - 2; ++index)
    {
        double avg = (array[index] + array[index + 1] + array[index + 2]) / 3.0;
        if (avg < minAvg)
        {
            minAvg = avg;
            minPos = index;
        }
    }

    return minPos;
}

int main()
{
    vector<int> array = {4, 2, 2, 5, 1, 5, 8};
    cout << "The result is: " << solution(array) << endl;
    return 0;
}