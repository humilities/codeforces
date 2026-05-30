#include <iostream>
#include <string>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int x = 0, y = 0;
  for (char c : s) {
    if (c == 'N')
      y++;
    else if (c == 'S')
      y--;
    else if (c == 'E')
      x++;
    else if (c == 'W')
      x--;
  }
  if (x % 2 != 0 || y % 2 != 0) {
    cout << "NO" << endl;
    return;
  }
  if (x == 0 && y == 0 && n == 2) {
    cout << "NO" << endl;
    return;
  }
  string res(n, 'R');

  int target_x = x / 2;
  int target_y = y / 2;
  if (x == 0 && y == 0) {
    bool h_got_ns = false, h_got_ew = false;
    for (int i = 0; i < n; ++i) {
      if (!h_got_ns && (s[i] == 'N' || s[i] == 'S')) {
        res[i] = 'H';
        char comp = (s[i] == 'N' ? 'S' : 'N');
        for (int j = 0; j < n; ++j) {
          if (i != j && s[j] == comp) {
            res[j] = 'H';
            h_got_ns = true;
            break;
          }
        }
        if (h_got_ns)
          break;
      }
      if (!h_got_ew && (s[i] == 'E' || s[i] == 'W')) {
        res[i] = 'H';
        char comp = (s[i] == 'E' ? 'W' : 'E');
        for (int j = 0; j < n; ++j) {
          if (i != j && s[j] == comp) {
            res[j] = 'H';
            h_got_ew = true;
            break;
          }
        }
        if (h_got_ew)
          break;
      }
    }
  } else {
    int cur_x = 0, cur_y = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'N' && cur_y < target_y && target_y > 0) {
        res[i] = 'H';
        cur_y++;
      } else if (s[i] == 'S' && cur_y > target_y && target_y < 0) {
        res[i] = 'H';
        cur_y--;
      } else if (s[i] == 'E' && cur_x < target_x && target_x > 0) {
        res[i] = 'H';
        cur_x++;
      } else if (s[i] == 'W' && cur_x > target_x && target_x < 0) {
        res[i] = 'H';
        cur_x--;
      }
    }
  }

  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
