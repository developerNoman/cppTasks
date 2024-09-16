#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to find the non-divisors of every number in an array. Used the count map to store the occurance of every element in a map. sort the array and divide its elements with the divisors from 1 to square root of the processing elements. The corner case here is a pair check which is also fulfilled.
vector<int> solution(vector<int> &array)
{
    int length = array.size();

    unordered_map<int, int> result;
    unordered_map<int, int> countMap;

    for (int index = 0; index < length; ++index)
    {
        countMap[array[index]]++;
    }

    vector<int> sortedArray = array;
    sort(sortedArray.begin(), sortedArray.end());

    int prevNum = -1;
    int nonDivisors = 0;

    for (int arrayIndex = 0; arrayIndex < length; ++arrayIndex)
    {
        int num = sortedArray[arrayIndex];
        if (num == prevNum)
        {
            result[num] = nonDivisors;
        }
        else
        {
            int countDivisor = 0;

            for (int index = 1; index <= sqrt(num); ++index)
            {
                if (num % index == 0)
                {

                    countDivisor += countMap[index];

                    if (index != num / index)
                    {
                        countDivisor += countMap[num / index];
                    }
                }
            }

            nonDivisors = length - countDivisor;
            result[num] = nonDivisors;

            prevNum = num;
        }
    }

    for (int index = 0; index < length; index++)
    {
        array[index] = result[array[index]];
    }

    return array;
}

int main()
{
    vector<int> A = {3, 1, 2, 3, 6};
    vector<int> result = solution(A);

    for (int index = 0; index < result.size(); index++)
    {
        cout << result[index] << " ";
    }

    return 0;
}
