#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> &A) {
    int length = A.size();
    int intersections = 0;

    
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (i + A[i] >= j - A[j]) {
                ++intersections;
            }
        }
    }

    return intersections;
}

int main() {
    vector<int> A = {1, 5, 2, 1, 4, 0};
    cout << "The result is: " << solution(A) << endl;
    return 0;
}
