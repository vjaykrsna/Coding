#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long lcm(long long a, long long b) {
    return (a * (b / gcd(a, b)));
}

int countSubsets(vector<int>& A, int K) {
    int N = A.size();
    int count = 0;
    
    int totalSubsets = 1 << N;
    
    for (int subsetMask = 1; subsetMask < totalSubsets; ++subsetMask) {
        long long subsetLCM = 1;
        bool valid = true;
        
        for (int i = 0; i < N; ++i) {
            if (subsetMask & (1 << i)) {
                subsetLCM = lcm(subsetLCM, A[i]);
                if (subsetLCM > K && subsetLCM % K != 0) {
                    valid = false;
                    break;
                }
            }
        }
        
        if (valid && subsetLCM % K == 0) {
            ++count;
        }
    }
    
    return count;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int result = countSubsets(A, K);
    cout << result << endl;
    
    return 0;
}
