
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// function to find the minimal nucleotide from a range of sequence DNA
vector<int> solution(string &str, vector<int> &pQuery, vector<int> &qQuery)
{
    int length = pQuery.size();
    vector<int> result;
    result.reserve(length);

    // store the impacts against nucleotides
    unordered_map<char, int> items = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

    int start;
    int end;
    char minCharacter;

    // processing the queries. Check the minimum Character from P to Q index in the string.
    for (int queryIndex = 0; queryIndex < length; ++queryIndex)
    {
        start = pQuery[queryIndex];
        end = qQuery[queryIndex];
        minCharacter = str[start];

        if (minCharacter != 'A')
        {
            for (int index = start; index <= end; ++index)
            {
                if (str[index] < minCharacter)
                {
                    minCharacter = str[index];

                    if (minCharacter == 'A')
                    {
                        break;
                    }
                }
            }
        }

        result.emplace_back(items[minCharacter]);
    }

    return result;
}

int main()
{
    vector<int> pQuery = {2, 5, 0};
    vector<int> qQuery = {4, 5, 6};
    string str = "CAGCCTA";

    vector<int> result = solution(str, pQuery, qQuery);
    int resultSize = result.size();

    cout << "The result is : " << endl;
    for (int index = 0; index < resultSize; index++)
    {
        cout << result[index] << ' ';
    }
    return 0;
}

// vector<int> solution(string &s, vector<int> &P, vector<int> &Q) {
//     int length = P.size();
//     vector<int> result;
//     result.reserve(length);

//     unordered_map<char, int> items = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

//     int n = s.size();

//     vector<vector<int>> minChar(n, vector<int>(n, -1));

//     for (int i = 0; i < length; ++i) {
//         int start = P[i];
//         int end = Q[i];

//         if (minChar[start][end] == -1) {
//             char minCharacter = s[start];

//             for (int index = start; index <= end; ++index) {
//                 if (s[index] < minCharacter) {
//                     minCharacter = s[index];
//                 }
//             }
//             minChar[start][end] = items[minCharacter];
//         }

//         result.push_back(minChar[start][end]);
//     }

//     return result;
// }