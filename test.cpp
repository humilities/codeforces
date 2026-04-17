#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    lin(i, 0, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    vector<int> res;
    vector<bool> used(n, false);
    bitset<20001> can;

    can[0] = 1;

    lin(j, 0, n) {
        bool found = false;
        lin(i, 0, n) {
            if (!used[i] && !can[a[i]]) {
                res.push_back(a[i]);
                used[i] = true;
                found = true;
                
                can |= (can << a[i]);
                break;
            }
        }

        if (!found) {
            cout << -1 << "\n";
            return;
        }
    }

    lin(i, 0, n) cout << res[i] << (i == n - 1 ? "" : " ");
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) 
      solve();

    return 0;
}