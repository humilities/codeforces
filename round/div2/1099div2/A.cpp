#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> eve;
  vector<int> odd;

  for (int i = 0; i < (n + 1) / 2; i++)
    eve.push_back(2 * n - 2 * i);
  for (int i = 0; i < n / 2; i++)
    odd.push_back(2 * n - 1 - 2 * i);

  int idx1 = 0, idx2 = 0;
  for (int i = 0; i < n; i++) {
    if ((i & 1) == 0)
      cout << eve[idx1++] << " \n"[i == n - 1];
    else
      cout << odd[idx2++] << " \n"[i == n - 1];
  }
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
