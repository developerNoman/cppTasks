#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// vector<int> solution(string &s, vector<int> &P, vector<int> &Q) {
//     int n = P.size();
//     vector<int> result;
//     string temp;
//     for (int i = 0; i < n; i++) {
//         temp = s.substr(P[i], Q[i] - P[i] + 1);
//     }
//         int impact = 4;
//         for (char c : temp) {
//             if (c == 'A')
//             {    
//                 impact=1;
//                 result.push_back(impact);
//             }
//             else if (c == 'C' && impact > 2) 
//             {
//                 impact=2;
//                 result.push_back(impact);
//             }
//             else if (c == 'G' && impact > 3)  {
//                 impact=3;
//                 result.push_back(impact);
//             }
//             else{
//                 result.push_back(impact);
//             }
//         }
//     return result;
// }
vector<int> solution(string &s, vector<int> &P, vector<int> &Q) {
    int n1 = P.size();
    vector<int> result;
    result.reserve(n1);
    unordered_map<char, int> items = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    string temp="";
    for (int i = 0; i < n1; i++) {
        temp = s.substr(P[i], Q[i] - P[i] + 1);
        sort(temp.begin(), temp.end());
        result.emplace_back(items[temp[0]]);
    }
    return result;
}
int main()
{
    vector<int> P={2,5,0};
    vector<int> Q={4,5,6};
    string S="CAGCCTA";

    vector<int> result=solution(S,P,Q);
    cout << "The result is : "  <<endl;
    for(int i = 0; i < result.size(); i++){
            cout<< result[i]<<' ';        
    }
    return 0;
}



// string solution(string &s,vector<int> &P,vector<int> &Q){
//     int n1=P.size();
//     int n2=Q.size();
//     string result;
//     for (int i=0;i<n1;i++){
//         for(int j=0;j<n2;j++){
//                 for(int k=P[i];k<=Q[j];k++){
//                     // if(P[i]==2 && Q[j]==4){
//                     result.push_back(s[k]);
//                     // }
//                 }
//             }
//     }
//    return result;
// }







// vector<int>  solution(string &s, vector<int> &P, vector<int> &Q) {
//     int n1 = P.size();
//     string result;
//     for (int i = 0; i < n1; i++) {
//     
//         string temp = s.substr(P[i], Q[i]-P[i]+1);
     
//         for (int j=0;j<=temp.size();j++) {
    
//             result.push_back(temp[j]);
//        
//                }
//     }
//     vector<int> temp;
//     for(int i=0; i<=result.size(); i++){
//         if(result[i]=='A'){
//             temp[i]=1;
//         }
//         else if(result[i]=='C'){
//                  temp[i]=2;
//         }

//         else if(result[i]=='G'){
//                   temp[i]=3;
//         }
//         else{
//                   temp[i]=4;
//         }
//     }
    
//     sort(temp.begin(),temp.end());
//     vector<int> temp2;
//     temp.push_back(temp[0]);
//     return temp;
// }


