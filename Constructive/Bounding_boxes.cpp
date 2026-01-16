#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return;

    long long W_max = LLONG_MAX;
    long long H_max = LLONG_MAX;
    long long D_max = LLONG_MAX;
    
    for (int i = 0; i < n; ++i) {
        vector<int> dims(3);
        if (!(cin >> dims[0] >> dims[1] >> dims[2])) break;
        
        sort(dims.begin(), dims.end());
        
        W_max = min(W_max, (long long)dims[0]);
        
        H_max = min(H_max, (long long)dims[1]);
        
        D_max = min(D_max, (long long)dims[2]);
    }
    long long V_max = W_max * H_max * D_max;

    cout << V_max << "\n";
}

int main() {
    solve();
    return 0;
}