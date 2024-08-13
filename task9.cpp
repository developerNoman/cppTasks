#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int solution(vector<int> &A, int n){
    unordered_map<int, int> map; 
    int num;
    int maxFreq = 0;
    for(int i = 0; i < n; i++){
        if(map.count(A[i]) > 0){
            map[A[i]]++;
        } else {
            map[A[i]] = 1;
        }
        if(map[A[i]] > maxFreq){
            maxFreq = map[A[i]];
            num = A[i];
        }
    }
    return num;
}
int main()
{
    vector<int> A={3,4,3,2,3,-1,3,3};
    int n = A.size();
    int num=solution(A, n);
    cout << "The result is : " << endl;
    for(int i = 0; i < n; i++){
        if(A[i]==num){
            cout<< i <<" ";
        }
    }
    return 0;
}
