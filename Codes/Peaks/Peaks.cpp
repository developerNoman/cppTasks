
#include <iostream>
#include <vector>

using namespace std;

// function to find the number of peaks in each block where the blocks should be evenly divided
int solution(vector<int> &array)
{

    int length = array.size();

    vector<int> peaks;

    for (int index = 1; index < length - 1; ++index)
    {
        if (array[index] > array[index - 1] && array[index] > array[index + 1])
        {
            peaks.push_back(index);
        }
    }

    if (peaks.empty())
    {
        return 0;
    }

    int peakSize = peaks.size();

    int maxBlocks = 0;
    int peakIndex;
    int blockSize;
    bool valid;
    bool blockHasPeak;

    for (int blocks = 1; blocks <= length; ++blocks)
    {
        if (length % blocks == 0)
        {
            blockSize = length / blocks;
            peakIndex = 0;
            valid = true;

            for (int currentBlock = 0; currentBlock < blocks; ++currentBlock)
            {
                blockHasPeak = false;
                while (peakIndex < peakSize && peaks[peakIndex] < (currentBlock + 1) * blockSize)
                {
                    if (peaks[peakIndex] >= currentBlock * blockSize)
                    {
                        blockHasPeak = true;
                        break;
                    }
                    ++peakIndex;
                }
                if (!blockHasPeak)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                maxBlocks = max(maxBlocks, blocks);
            }
        }
    }

    return maxBlocks;
}

int main()
{
    vector<int> A = {1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2};
    cout << "The result is: " << solution(A) << endl;
    return 0;
}
