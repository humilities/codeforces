#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  ll tol = 0;
  lin(i, 0, n) {
    cin >> a[i];
    tol += a[i];
  }

  vector<ll> sm(n);
  sm[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; --i)
    sm[i] = min(a[i], sm[i + 1]);

  ll sum = 0;
  vector<int> freq(n + 1, 0);
  lin(i, 0, n) {
    sum += sm[i];
    if (sm[i] <= n)
      freq[sm[i]]++;
  }

  ll base = tol - sum;
  ll get = 0;

  lin(j, 0, n) {
    if (a[j] == sm[j]) {
      bool is = (j == n - 1 || a[j] < sm[j + 1]);
      if (is)
        get = max(get, (long long)freq[a[j]] - 1);
    }
  }

  cout << base + get << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
