#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> freq(n + 2, 0);
  vector<vector<int>> buc(n + 1);
  for (int i = 0; i < n; i++)
    freq[a[i]]++;

  for (int i = 0; i <= n + 1; i++)
    if (freq[i] <= n)
      buc[freq[i]].push_back(i);

  int mex = 0;
  while (freq[mex])
    mex++;

  vector<bool> in(n + 2, false);
  int sei = 0;

  for (auto x : buc[0]) {
    if (x <= mex && x <= n) {
      in[x] = true;
      sei++;
    }
  }

  cout << sei;
  for (int k = 1; k <= n; k++) {
    int las = n - k + 1;
    if (las >= 0 && las <= mex && in[las]) {
      in[las] = false;
      sei--;
    }

    for (auto x : buc[k]) {
      if (x <= mex && x <= n - k) {
        if (!in[x]) {
          in[x] = true;
          sei++;
        }
      }
    }

    cout << " " << sei;
  }

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
