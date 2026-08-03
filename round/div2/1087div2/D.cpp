#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
  struct Color {
    int count;
    char name;
  };

  vector<Color> c(3);
  cin >> c[0].count >> c[1].count >> c[2].count;
  c[0].name = 'R';
  c[1].name = 'G';
  c[2].name = 'B';

  string res = "";
  while (true) {
    sort(c.begin(), c.end(),
         [](const Color &a, const Color &b) { return a.count > b.count; });

    bool placed = false;
    for (int i = 0; i < 3; ++i) {
      if (c[i].count <= 0)
        continue;

      char current = c[i].name;
      int n = res.length();

      if (n >= 1 && res[n - 1] == current)
        continue;
      if (n >= 3 && res[n - 3] == current)
        continue;

      res += current;
      c[i].count--;
      placed = true;
      break;
    }

    if (!placed)
      break;
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
