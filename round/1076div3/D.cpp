#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];

  sort(a.rbegin(), a.rend());

  ll sco = 0;
  ll cnt = 0;

  for (int i = 0; i < n; i++) {
    cnt += b[i];

    if (cnt > n)
      break;

    ll dif = a[cnt - 1];
    sco = max(sco, (dif * (i + 1)));
  }

  cout << sco << endl;
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
