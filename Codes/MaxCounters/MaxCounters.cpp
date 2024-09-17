#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all counters to current maximummum.
vector<int> solution(vector<int> &array, int numberOfCounters)
{
    int length = array.size();

    vector<int> counter(numberOfCounters, 0);

    int maximum = 0;
    int lastUpdated = 0;

    // loop which iterate in an array and increase counter value by one. If there is a value which is greater than numberOfcounters, set that as last maximum value occured in an array.
    for (int arrayIndex = 0; arrayIndex < length; arrayIndex++)
    {
        if (array[arrayIndex] <= numberOfCounters)
        {
            int index = array[arrayIndex] - 1;
            counter[index] = max(counter[index], lastUpdated);
            counter[index]++;
            maximum = max(maximum, counter[index]);
        }
        else
        {
            lastUpdated = maximum;
        }
    }

    // in counter array, set the maximum value if we have lesser value as compare to last element.
    for (int index = 0; index < numberOfCounters; index++)
    {
        counter[index] = max(counter[index], lastUpdated);
    }

    return counter;
}

int main()
{
    vector<int> array = {3, 4, 4, 6, 1, 4, 4};
    int numberOfCounters = 5;
    vector<int> result = solution(array, numberOfCounters);

    cout << "The result is: [ ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}
