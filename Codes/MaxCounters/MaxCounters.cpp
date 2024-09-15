#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all counters to current maximummum.
vector<int> solution(vector<int> &A, int N)
{
    int length = A.size();

    vector<int> counter(N, 0);

    int maximum = 0;
    int lastUpdated = 0;

    for (int i = 0; i < length; i++)
    {
        if (A[i] <= N)
        {
            int index = A[i] - 1;
            counter[index] = max(counter[index], lastUpdated);
            counter[index]++;
            maximum = max(maximum, counter[index]);
        }
        else
        {
            lastUpdated = maximum;
        }
    }

    for (int i = 0; i < N; i++)
    {
        counter[i] = max(counter[i], lastUpdated);
    }

    return counter;
}

int main()
{
    vector<int> A = {3, 4, 4, 6, 1, 4, 4};
    int N = 5;
    vector<int> result = solution(A, N);
    cout << "The result is: [ ";
    for (int i : result)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
    return 0;
}
