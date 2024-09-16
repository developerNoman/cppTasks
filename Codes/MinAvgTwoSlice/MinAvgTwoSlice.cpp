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
        return -1;

    double minAvg = DBL_MAX;
    int minPos = 0;

    for (int index = 0; index < length - 1; ++index)
    {
        double avg = (array[index] + array[index + 1]) / 2.0;
        if (avg < minAvg)
        {
            minAvg = avg;
            minPos = index;
        }
    }

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
    vector<int> A = {4, 2, 2, 5, 1, 5, 8};
    cout << "The result is: " << solution(A) << endl;
    return 0;
}