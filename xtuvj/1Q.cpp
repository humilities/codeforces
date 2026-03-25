#include <bits/stdc++.h>

using namespace std;

int ma[26];

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  for (int i = 0; i < n; i++)
    ma[s[i] - 'a']++;

  string ans;
  for (int i = 0; i < 26; i++) {
    if (ma[i])
      while (ma[i]--)
        ans += i + 'a';
  }

  cout << ans << endl;
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
