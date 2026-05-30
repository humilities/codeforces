#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  ll k;
  cin >> n >> k;

  ll sum = 0;
  lin(i, 1, n + 1) sum += abs((n - i + 1) - i);

  if (k % 2 != 0 || k > sum) {
    cout << "No" << "\n";
    return;
  }

  vector<int> p(n + 1);
  lin(i, 1, n + 1) p[i] = i;

  int l = 1, r = n;
  while (l < r && k > 0) {
    ll ctr = 2LL * (r - l);

    if (k >= ctr) {
      swap(p[l], p[r]);
      k -= ctr;
      l++;
      r--;
    } else {
      int tar = l + (int)(k / 2);
      swap(p[l], p[tar]);
      k = 0;
    }
  }

  cout << "Yes" << "\n";
  lin(i, 1, n + 1) cout << p[i] << " \n"[i == n];
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
