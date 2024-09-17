#include <iostream>
#include <vector>
using namespace std;

// function to find the minimum number of blocks for making the stone wall.
int solution(vector<int> &array)
{
    int length = array.size();
    vector<int> blocks;
    int totalBlocks = 0;

    // iterate in the array and push the element in the blocks vector if there last element is less than current element of array. Else pop it.
    for (int height = 0; height < length; height++)
    {
        while (!blocks.empty() && blocks.back() > array[height])
        {
            blocks.pop_back();
        }

        if (blocks.empty() || blocks.back() < array[height])
        {
            blocks.push_back(array[height]);
            totalBlocks++;
        }
    }

    return totalBlocks;
}

int main()
{
    vector<int> array = {8, 8, 5, 7, 9, 8, 7, 4, 8};
    cout << "The result is: " << solution(array) << endl;
    return 0;
}
