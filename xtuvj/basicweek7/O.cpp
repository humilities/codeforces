#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int get(const string &s, int l, int r, char c) {
  int cnt = 0;

  lin(i, l, r + 1) if (s[i] != c) cnt++;

  return cnt;
}

int dv(const string &s, int l, int r, char tar) {
  if (l == r)
    return (s[l] == tar) ? 0 : 1;
  int mid = l + (r - l) / 2;

  int c1 = get(s, l, mid, tar);
  int cr = dv(s, mid + 1, r, tar + 1);
  int i = c1 + cr;

  int o1 = get(s, mid + 1, r, tar);
  int o2 = dv(s, l, mid, tar + 1);
  int j = o1 + o2;

  return min(i, j);
}

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  cout << dv(s, 0, n - 1, 'a') << "\n";
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
