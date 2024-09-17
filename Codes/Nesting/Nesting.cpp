#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// function which is used for parenthesis match ().
int solution(string &str)
{
    int length = str.size();

    if (length == 0)
    {
        return 1;
    }

    if (length == 1)
    {
        return 0;
    }

    stack<char> bracesStack;

    // loop iterates in the array and push "(" in  the stack and the pop the "(" if there is ")" where the stack top should have "("
    for (int index = 0; index < length; index++)
    {
        if (str[index] == '(')
        {
            bracesStack.push(str[index]);
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