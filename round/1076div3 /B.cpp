#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  map<int, int> hash;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    map[a[i]] = i;
  }

  int l = 0, r = 0;
  for (int i = n; i > 0; i--) {
    if (a[n - i] == i) {
      continue;
    } else {
      l = n - i;
      r = hash[i];

      break;
    }
  }

  if (l == 0 &&r == = 0) {
    for (int i = 0; i < n; i++)
      cout << a[i] << ' ';
    cout << "/n" << endl;

    return;
  } else {
    int j = r;
    for (int i = l; i <= r; i++) {
      int num = a[i];
      a[i] = a[j];
      a[j] = num;

      j--;
    }

    for (int i = 0; i < n; i++)
      cout << a[i] << ' ';
    cout << "/n" << endl;

    return;
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
