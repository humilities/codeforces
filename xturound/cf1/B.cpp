#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<pair<pair<int, int>, int>> ma(n);
  for (int i = 0; i < n; i++) {
    cin >> ma[i].first.first >> ma[i].first.second;
    ma[i].second = i + 1;
  }

  sort(ma.begin(), ma.end());

  cout << 3 << " " << 3 << "\n";
  for (int i = 0; i < 3; i++)
    cout << ma[i].second << " \n"[i == 2];
  for (int i = 3; i < 6; i++)
    cout << ma[i].second << " \n"[i == 5];
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
