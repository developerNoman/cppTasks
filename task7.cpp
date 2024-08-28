#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

//function which is used for parenthesis match ().
int solution(string &S){
    int length=S.size();
     if(length==0){
        return 1;
    }
    if (length==1){
        return 0;
    }

    stack<char> bracesStack;
    for (int index=0;index<length;index++){
        if(S[index]=='('){
            bracesStack.push(S[index]);
        }
        else{
            if(bracesStack.empty() || bracesStack.top()!= '('){
                return 0;
            }
            bracesStack.pop();
        }
    }
    if(bracesStack.empty()){
        return 1;
    }
    return 0;
}
int main()
{
    string str="(()(())())";
    cout << "The result is : " << solution(str)<< endl;
    return 0;
}



// int solution(string &S){
//     int n=S.size();
//     if (n<=1){
//         return 0;
//     }
//     int leftBrace=0;
//     int rightBrace=0;
//     for (int i=0;i<n;i++){
//         if(S[i]=='('){
//             leftBrace++;
//         }
//         else
//             {
//         rightBrace++;
//             }
//     }

//     // stack<char> bracesStack;
//     // for (int i=0; i<n; i++) 
//     // {
//     //     bracesStack.push(S[i]);
//     // }
//     if(leftBrace==rightBrace){
//         return 1;
//     }
    
//     return 0;

// }



// int solution(string &S){
//     int n=S.size();
//      if(n==0){
//         return 1;
//     }
//     if (n==1){
//         return 0;
//     }
//     stack<char> bracesStack;
//     for (int i=0;i<n;i++){
//         if(S[i]=='('){
//             bracesStack.push(S[i]);//1(,2(,4(,5(,8(
//         }
//         else{
//             if(bracesStack.empty() || bracesStack.top()!= '('){//3),6),7),9),10)
//                 return 0;
//             }
//             bracesStack.pop();
//         }
//     }
//     if(bracesStack.empty()){
//         return 1;
//     }
//     return 0;
// }