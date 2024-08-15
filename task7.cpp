#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


int solution(string &S){
    int n=S.size();
     if(n==0){
        return 1;
    }
    if (n==1){
        return 0;
    }
    stack<char> s1;
    for (int i=0;i<n;i++){
        if(S[i]=='('){
            s1.push(S[i]);//1(,2(,4(,5(,8(
        }
        else{
            if(s1.empty() || s1.top()!= '('){//3),6),7),9),10)
                return 0;
            }
            s1.pop();
        }
    }
    if(s1.empty()){
        return 1;
    }
    return 0;
}
int main()
{
    string s="(()(())())";
    cout << "The result is : " << solution(s)<< endl;
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

//     // stack<char> s1;
//     // for (int i=0; i<n; i++) 
//     // {
//     //     s1.push(S[i]);
//     // }
//     if(leftBrace==rightBrace){
//         return 1;
//     }
    
//     return 0;

// }