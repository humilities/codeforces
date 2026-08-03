#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

ll p[64];

void inser(ll x) {
  for (int i = 63; i >= 0; i--) {
    if (!(x >> i))
      continue;
    if (!p[i]) {
      p[i] = x;
      return;
    }

    x ^= p[i];
  }
}

void solve() {
  int n;
  cin >> n;

  ll ansa = 0;
  vector<ll> a(n);

  lin(i, 0, n) {
    cin >> a[i];
    ansa ^= a[i];
  }

  lin(i, 0, n) {
    ll num;
    cin >> num;

    inser(num ^ a[i]);
  }

  for (int i = 63; i >= 0; i--) {
    if ((ansa ^ p[i]) > ansa)
      ansa ^= p[i];
  }

  cout << ansa << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;
  //
  // while (t--)
  solve();

  return 0;
}
