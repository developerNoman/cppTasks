#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> &A)
{
    unordered_map<int, int> freqMap;
    int dominator = -1;
    int maxFrequency = 0;
    int length = A.size();
    for (int index = 0; index < length; index++)
    {
        int num = A[index];
        freqMap[num]++;
        if (freqMap[num] > maxFrequency)
        {
            maxFrequency = freqMap[num];
            dominator = num;
        }
    }
    if (maxFrequency > length / 2)
    {
        for (int index = 0; index < length; index++)
        {
            if (A[index] == dominator)
            {
                return index;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> A = {3, 4, 3, 2, 3, -1, 3, 3};
    cout << "The dominator are at: " << solution(A);
    return 0;
}
