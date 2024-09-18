#include <iostream>
#include <vector>
using namespace std;

// function to find the intersection of discs.
int solution(vector<int> &array)
{
    size_t length = array.size();
    size_t intersections = 0;

    // for loop to check the intersection of current and its next disc. If the center+radius of first disc is greater than or equal to center-radius of second. There's an intersection.
    for (size_t index = 0; index < length; ++index)
    {
        for (size_t nextIndex = index + 1; nextIndex < length; ++nextIndex)
        {
            if ((array[index] + array[nextIndex]) >= (nextIndex - index))
            {
                ++intersections;
                if (intersections > 10000000)
                {
                    return -1;
                }
            }
        }
    }

    return intersections;
}

int main()
{
    vector<int> array = {1, 5, 2, 1, 4, 0};
    cout << "The result is: " << solution(array) << endl;
    return 0;
}
