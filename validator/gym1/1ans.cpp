#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % n != 0) {
        cout << -1 << endl;
        return;
    }

    ll avg = sum / n;
    ll ans = 0;
    ll balance = 0;

    for (int i = 0; i < n - 1; i++) {
        balance += (a[i] - avg);
        ans += abs(balance);
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}