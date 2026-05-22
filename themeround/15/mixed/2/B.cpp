#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int x;
  cin >> x;

  vector<int> a(33, 0);
  for (int i = 0; i < 31; i++) {
    if ((x >> i) & 1)
      a[i] = 1;
  }

  for (int i = 0; i < 32; i++) {
    if (a[i] > 1) {
      a[i] -= 2;
      a[i + 1] += 1;
    }

    if (a[i] == 1 && a[i + 1] == 1) {
      a[i] = -1;
      a[i + 1] += 1;
    }
  }

  int len = 32;
  while (len > 1 && a[len - 1] == 0)
    len--;

  cout << len << "\n";
  for (int i = 0; i < len; i++)
    cout << a[i] << (i == len - 1 ? "" : " ");
  cout << "\n";
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
