#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// function to find the dominator from the array. The dominator of array is the value that occurs in more than half of the elements of array.
int solution(vector<int> &array)
{
    // map to to store the frequency of elements in an array
    unordered_map<int, int> freqMap;

    int dominator = -1;
    int maxFrequency = 0;
    int length = array.size();

    // for loop to find the frequency of each element. And update the maximum frequency element if it exists. Hence update the dominator
    for (int index = 0; index < length; index++)
    {
        int num = array[index];
        freqMap[num]++;
        if (freqMap[num] > maxFrequency)
        {
            maxFrequency = freqMap[num];
            dominator = num;
        }
    }

    // check if the frequency of the dominator is greater than half of the array. If this is true, then return the first occured index of the dominator.
    if (maxFrequency > length / 2)
    {
        for (int index = 0; index < length; index++)
        {
            if (array[index] == dominator)
            {
                return index;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> array = {3, 4, 3, 2, 3, -1, 3, 3};
    cout << "The dominator are at: " << solution(array);
    return 0;
}
