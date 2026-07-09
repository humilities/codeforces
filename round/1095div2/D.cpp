#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;

    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }

    int idx = 0; 
    while (true) {
        auto it = a.find(idx);
        
        if (it != a.end()) {
            a.erase(it);
            idx++;
        }
        else if (!a.empty()) {
            auto it = prev(a.end());
            if (*it >= 2 * idx + 1) {
                a.erase(it);
                idx++;
            } else {
                break;
            }
        } 
        else {
            break;
        }
    }

    cout << idx << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while (t--)
     solve();

    return 0;
}