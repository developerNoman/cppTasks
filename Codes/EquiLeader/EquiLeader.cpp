#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// function to find the equileader in the vector. Leader is the number which occur more then half in the array. The equileaders are that leaders which occur more than half in subarrays.
int solution(vector<int> &array)
{

    int length = array.size();

    // map to store the frequency of element
    unordered_map<int, int> frequency;

    // find frequency of each element of array and store it in frequency map
    for (int index = 0; index < length; ++index)
    {
        frequency[array[index]]++;
    }

    int leader = -1;

    // logic to find the leader (the number that occur more than half in an array)
    for (auto it = frequency.begin(); it != frequency.end(); ++it)
    {
        int num = it->first;
        int count = it->second;
        if (count > length / 2)
        {
            leader = num;
            break;
        }
    }

    int leftLeaderCount = 0;
    int rightLeaderCount = frequency[leader];
    int equiLeaders = 0;

    // logic to find the equileader (the leader that occur more than half in subarrays)
    for (int index = 0; index < length - 1; ++index)
    {
        if (array[index] == leader)
        {
            leftLeaderCount++;
            rightLeaderCount--;
        }

        if (leftLeaderCount > (index + 1) / 2 && rightLeaderCount > (length - index - 1) / 2)
        {
            equiLeaders++;
        }
    }

    return equiLeaders;
}

int main()
{
    vector<int> array = {4, 3, 4, 4, 4, 2};
    cout << solution(array) << endl;
    return 0;
}
