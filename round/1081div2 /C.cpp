#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, h, k;
  int cnt = 0;
  int maxn = 0;
  cin >> n >> h >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt += a[i];
    if (a[i] > maxn)
      maxn = a[i];
  }

  int div = h / cnt;
  int rem = h % cnt;

  if (rem < a[maxn])
    cout << div * k + 1 << endl;
  else {
    int temp = a[maxn];
    a[maxn] = a[1];
    a[1] = temp;

    int num = 0, c = 0;
    for (int i = 0; i < n; i++) {
      if (num >= h)
        break;

      num += a[i];
      c++;
    }

    cout << div * k + c << endl;
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
