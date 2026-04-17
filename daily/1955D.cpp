#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, k;
  int cnt = 0;
  cin >> n >> m >> k;

  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= m; i++)
    cin >> b[i];

  map<int, int> has1;
  for (int i = 1; i <= m; i++)
    has1[b[i]]++;

  int ans = 0;
  map<int, int> has2;

  for (int i = 1; i <= m; i++) {
    if (has2[a[i]] < has1[a[i]])
      cnt++;

    has2[a[i]]++;
  }

  if (cnt >= k)
    ans++;

  for (int i = m + 1; i <= n; i++) {
    int lef = a[i - m];
    int rig = a[i];

    if (has2[lef] <= has1[lef])
      cnt--;
    has2[lef]--;

    if (has2[rig] < has1[rig])
      cnt++;
    has2[rig]++;

    if (cnt >= k)
      ans++;
  }

  cout << ans << endl;

  has1.clear();
  has2.clear();
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
