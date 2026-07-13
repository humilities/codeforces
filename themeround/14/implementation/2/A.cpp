#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

struct a {
  int i;
  int j;
};

bool compa(const a &a1, const a &a2) { return a1.i < a2.i; }

void solve() {
  int n;
  cin >> n;

  vector<a> b(n);
  lin(k, 0, n) cin >> b[k].i;
  lin(k, 0, n) cin >> b[k].j;

  sort(b.begin(), b.end(), compa);

  lin(k, 0, n) cout << b[k].i << " \n"[k == n - 1];
  lin(k, 0, n) cout << b[k].j << " \n"[k == n - 1];
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
