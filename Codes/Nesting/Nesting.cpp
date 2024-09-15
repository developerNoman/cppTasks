#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// function which is used for parenthesis match ().
int solution(string &S)
{
    int length = S.size();
    if (length == 0)
    {
        return 1;
    }
    if (length == 1)
    {
        return 0;
    }

    stack<char> bracesStack;
    for (int index = 0; index < length; index++)
    {
        if (S[index] == '(')
        {
            bracesStack.push(S[index]);
        }
        else
        {
            if (bracesStack.empty() || bracesStack.top() != '(')
            {
                return 0;
            }
            bracesStack.pop();
        }
    }
    if (bracesStack.empty())
    {
        return 1;
    }
    return 0;
}
int main()
{
    string str = "(()(())())";
    cout << "The result is : " << solution(str) << endl;
    return 0;
}