#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> a;
bool vis[1000005];

void pre() {
  for (int i = 2; i <= 1000003; i++) {
    if (!vis[i])
      a.push_back(i);

    for (int j : a) {
      if (j * i > 1000005)
        break;
      vis[i * j] = true;
      if (i % j == 0)
        break;
    }
  }
}

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++) {
    ll r = round(sqrt(a[i]));

    if (a[i] >= 4 && r * r == a[i] && !vis[r])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}
