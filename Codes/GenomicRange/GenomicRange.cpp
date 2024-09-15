
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(string &s, vector<int> &P, vector<int> &Q)
{
    int n1 = P.size();
    vector<int> result;
    result.reserve(n1);

    unordered_map<char, int> items = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

    int n = s.size();

    for (int i = 0; i < n1; ++i)
    {
        int start = P[i];
        int end = Q[i];

        char min_char = s[start];
        if (min_char != 'A')
        {
            for (int j = start; j <= end; ++j)
            {
                if (s[j] < min_char)
                {
                    min_char = s[j];

                    if (min_char == 'A')
                    {
                        break;
                    }
                }
            }
        }

        result.push_back(items[min_char]);
    }

    return result;
}

int main()
{
    vector<int> P = {2, 5, 0};
    vector<int> Q = {4, 5, 6};
    string S = "CAGCCTA";

    vector<int> result = solution(S, P, Q);
    cout << "The result is : " << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    return 0;
}

// vector<int> solution(string &s, vector<int> &P, vector<int> &Q)
// {
//     int n1 = P.size();
//     vector<int> result;
//     result.reserve(n1);
//     unordered_map<char, int> items = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
//     string temp = "";
//     for (int i = 0; i < n1; i++)
//     {
//         temp = s.substr(P[i], Q[i] - P[i] + 1);
//         sort(temp.begin(), temp.end());
//         result.emplace_back(items[temp[0]]);
//     }
//     return result;
// }

// vector<int> solution(string &s, vector<int> &P, vector<int> &Q)
// {
//     int n1 = P.size();
//     vector<int> result;
//     result.reserve(n1);

//     unordered_map<char, int> items = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

//     char min_char = 'T';
//     int i, j;

//     for (i = 0; i < n1; i++)
//     {
//         min_char = 'T';
//         int pquery = P[i];
//         int qQuery = Q[i];
//         for (j = pquery; j <= qQuery; j++)
//         {
//             if (s[j] < min_char)
//             {
//                 min_char = s[j];
//             }
//             if (min_char == 'A')
//                 break;
//         }
//         result.push_back(items[min_char]);
//     }

//     return result;
// }

// vector<int> solution(string &s, vector<int> &P, vector<int> &Q)
// {
//     int n1 = P.size();
//     vector<int> result;
//     result.reserve(n1);

//     unordered_map<char, int> items = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
//     vector<int> impact(s.size());

//     for (int i = 0; i < s.size(); ++i)
//     {
//         impact[i] = items[s[i]];
//     } // 2,1,3,2,2,4,1

//     for (int i = 0; i < n1; ++i)
//     {
//         int start = P[i];
//         int end = Q[i];

//         auto minIt = min_element(impact.begin() + P[i], impact.begin() + Q[i] + 1);
//         result.emplace_back(*minIt);
//     }

//     return result;
// }

// vector<int> solution(string &s, vector<int> &P, vector<int> &Q)
// {
//     int n1 = P.size();
//     vector<int> result;
//     result.reserve(n1);

//     unordered_map<char, int> items = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

//     int n = s.size();
//     vector<vector<int>> minChar(n, vector<int>(n, INT_MAX));

//     for (int i = 0; i < n; ++i) {
//         char min_char = s[i];
//         for (int j = i; j < n; ++j) {
//             if (s[j] < min_char) {
//                 min_char = s[j];
//             }
//             minChar[i][j] = items[min_char];
//         }
//     }

//     for (int i = 0; i < n1; ++i)
//     {
//         result.push_back(minChar[P[i]][Q[i]]);
//     }

//     return result;
// }

// vector<int> solution(string &s, vector<int> &P, vector<int> &Q) {
//     int n1 = P.size();
//     vector<int> result;
//     result.reserve(n1);

//     unordered_map<char, int> items = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

//     int n = s.size();

//     vector<vector<int>> minChar(n, vector<int>(n, -1));

//     for (int i = 0; i < n1; ++i) {
//         int start = P[i];
//         int end = Q[i];

//         if (minChar[start][end] == -1) {
//             char min_char = s[start];

//             for (int j = start; j <= end; ++j) {
//                 if (s[j] < min_char) {
//                     min_char = s[j];
//                 }
//             }
//             minChar[start][end] = items[min_char];
//         }

//         result.push_back(minChar[start][end]);
//     }

//     return result;
// }