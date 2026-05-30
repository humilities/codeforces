#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  ll c1 = 0;
  ll cn = 0;
  vector<ll> a(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  vector<ll> cha(n + 1);
  for (int i = 2; i < n; i++) {
    cha[i] = (a[i + 1] + a[i - 1] - 2 * a[i]) / 2;
  }

  for (int i = 2; i < n; i++) {
    c1 += cha[i] * abs(i - 1);
    cn += cha[i] * abs(i - n);
  }

  ll g1 = a[1] - c1;
  ll gn = a[n] - cn;

  cha[n] = g1 / (n - 1);
  cha[1] = gn / (n - 1);

  for (int i = 1; i <= n; i++)
    cout << cha[i] << (i == n ? "\n" : " ");
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
