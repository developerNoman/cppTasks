#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int solution(vector<int> &A)
{
    int n = A.size();
    unordered_map<int, int> frequency;
    for (int num : A)
    {
        frequency[num]++;
    }

    int leader = -1;

    for (const auto &entry : frequency)
    {
        int num = entry.first;
        int count = entry.second;

        if (count > n / 2)
        {
            leader = num;
            break;
        }
    }

    if (leader == -1)
    {
        return 0;
    }

    int leftLeaderCount = 0;
    int rightLeaderCount = frequency[leader];
    int equiLeaders = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == leader)
        {
            leftLeaderCount++;
            rightLeaderCount--;
        }

        if (leftLeaderCount > (i + 1) / 2 && rightLeaderCount > (n - i - 1) / 2)
        {
            equiLeaders++;
        }
    }

    return equiLeaders;
}

int main()
{
    vector<int> A = {4, 3, 4, 4, 4, 2};
    cout << solution(A) << endl;
    return 0;
}
