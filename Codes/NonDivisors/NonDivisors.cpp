#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to find the non-divisors of every number in an array.
vector<int> solution(vector<int> &array)
{
    int length = array.size();

    unordered_map<int, int> nonDivisorsMap;
    unordered_map<int, int> countMap;

    // count map to store the occurance of every number in a map.
    for (int index = 0; index < length; ++index)
    {
        countMap[array[index]]++;
    }

    // sort the array so we can easily check the previous number is equal to current number or not
    vector<int> sortedArray = array;
    sort(sortedArray.begin(), sortedArray.end());

    int previousNumber = -1;
    int nonDivisors = 0;
    int countDivisor = 0;
    int divisor = 1;

    for (int arrayIndex = 0; arrayIndex < length; ++arrayIndex)
    {
        int currentNumber = sortedArray[arrayIndex];
        if (currentNumber == previousNumber)
        {
            nonDivisorsMap[currentNumber] = nonDivisors;
        }
        else
        {
            countDivisor = 0;

            // divide the numbers with the divisors from 1 to square root of the processing elements.
            for (divisor = 1; divisor <= sqrt(currentNumber); ++divisor)
            {
                if (currentNumber % divisor == 0)
                {

                    countDivisor += countMap[divisor];

                    // The added case here which check for pair divisor (means if number is divisble by the divisor. Its result will also be the divisor of that number)
                    if (divisor != currentNumber / divisor)
                    {
                        auto it = countMap.find(currentNumber / divisor);
                        if (it != countMap.end())
                        {
                            countDivisor += it->second;
                        }
                        else
                        {
                            countDivisor += 0;
                        }
                    }
                }
            }

            nonDivisors = length - countDivisor;
            nonDivisorsMap[currentNumber] = nonDivisors;

            previousNumber = currentNumber;
        }
    }

    // place the nondivisors of the element at there index
    for (int index = 0; index < length; index++)
    {
        array[index] = nonDivisorsMap[array[index]];
    }

    return array;
}

int main()
{
    vector<int> array = {3, 1, 2, 3, 6};
    vector<int> result = solution(array);
    int resultSize = result.size();

    for (int index = 0; index < resultSize; index++)
    {
        cout << result[index] << " ";
    }

    return 0;
}
