#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int cnt[1000005];

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);
    int mn = 0;

    lin(i, 0, n) {
        cin >> a[i];
        if (a[i] < 1000005) {
            cnt[a[i]]++;
            mn = max(mn, a[i]);
        }
    }

    multiset<int> b;
    int idx = 0;

    while (cnt[idx]) {
        lin(j, 0, cnt[idx] - 1) b.insert(idx);
        idx++;
    }

    lin(i, idx, mn + 1)
        lin(j, 0, cnt[i]) b.insert(i);

    while (true) {
        auto it = b.lower_bound(2 * idx);

        if (it != b.end()) {
            b.erase(it);
            idx++;

            while (cnt[idx]) {
                lin(j, 0, cnt[idx] - 1) b.insert(idx);
                idx++;
            }
        } else break;
    }

    cout <<idx<< "\n";

    lin(i, 0, mn + 1) cnt[i] = 0;
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