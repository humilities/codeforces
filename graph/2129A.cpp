#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 2), b(n + 2);
  vector<int> fla(n + 4, 1);

  for (int i = 1; i <= n; i++)
    cin >> a[i] >> b[i];

  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        continue;

      if (a[j] <= a[i] && b[i] <= b[j])
        fla[i] = 0;
    }
    if (fla[i] == 1)
      ans.push_back(i);
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " \n"[i == (ans.size() - 1)];
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
