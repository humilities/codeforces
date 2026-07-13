#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n);
  vector<int> b(m);

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  string str;
  cin >> str;

  vector<bool> dead(n);
  map<int, vector<int>> se;

  sort(b.begin(), b.end());

  for (int i = 0; i < n; i++) {
    if (b[0] < a[i]) {
      int left = a[i] - (*(lower_bound(b.begin(), b.end(), a[i]) - 1));
      se[-left].push_back(i);
    }
    if (b[m - 1] > a[i]) {
      int right = *(lower_bound(b.begin(), b.end(), a[i])) - a[i];
      se[right].push_back(i);
    }
  }

  int ret = n;
  int pos = 0;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'L')
      pos--;
    else
      pos++;

    for (int j : se[pos]) {
      if (dead[j])
        continue;

      dead[j] = true;
      ret--;
    }
    se[pos].clear();

    cout << ret << " ";
  }

  cout << endl;
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
