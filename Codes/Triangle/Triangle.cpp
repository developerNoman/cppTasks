#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to check a triangle can be built from a given set of edges.
int solution(vector<int> &array)
{
    int length = array.size();

    if (length < 3)
    {
        return 0;
    }

    sort(array.begin(), array.end());

    // iterate over the loop and check that from any three pairs. The sum of every two should be greater than third.
    for (int index = 0; index < length - 2; ++index)
    {
        if (static_cast<long long>(array[index]) + array[index + 1] > array[index + 2])
        {
            return 1;
        }
    }

    return 0;
}
int main()
{
    vector<int> array = {10, 2, 5, 1, 8, 20};
    cout << "The result is : " << solution(array) << endl;
    return 0;
}
