#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ma = -2e9;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      vector<int> out;
      vector<int> in;

      int sum = 0;
      for (int f = 0; f < n; f++) {
        if (f >= i && f <= j)
          in.push_back(a[f]), sum += a[f];
        else
          out.push_back(a[f]);
      }

      sort(in.begin(), in.end());
      sort(out.begin(), out.end(), greater<>());

      for (int j = 0; j < min(k, min((int)in.size(), (int)out.size())); j++) {
        if (in[j] < out[j])
          sum += out[j] - in[j];
        else
          break;
      }

      ma = max(ma, sum);
    }
  }

  cout << ma << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t;
  // cin >> t;

  // while (t--)
  solve();

  return 0;
}
