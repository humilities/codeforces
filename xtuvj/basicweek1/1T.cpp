#include <bits/stdc++.h>

using namespace std;

int ma[10];

void solve() {
  int n;
  cin >> n;

  memset(ma, 0, sizeof(ma));

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;

    ma[val % 10]++;
  }

  vector<int> chu;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < min(3, ma[i]); j++) {
      chu.push_back(i);
    }
  }

  int length = chu.size();
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      for (int k = j + 1; k < length; k++) {
        if ((chu[i] + chu[j] + chu[k]) % 10 == 3) {
          cout << "YES" << endl;
          return;
        }
      }
    }
  }

  cout << "NO" << endl;
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
