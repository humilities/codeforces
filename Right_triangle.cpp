//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    vector<vector<char>> grid(n, vector<char>(m));
//    for (int i = 0; i < n; ++i) {
//        string s;
//        cin >> s;
//        for (int j = 0; j < m; ++j) {
//            grid[i][j] = s[j];
//        }
//    }
//
//    vector<vector<int>> left(n, vector<int>(m, 0));
//    for (int i = 0; i < n; ++i) {
//        left[i][0] = 0;
//        for (int j = 1; j < m; ++j) {
//            if (grid[i][j - 1] == '*') {
//                left[i][j] = left[i][j - 1] + 1;
//            }
//            else {
//                left[i][j] = left[i][j - 1];
//            }
//        }
//    }
//
//    vector<vector<int>> right(n, vector<int>(m, 0));
//    for (int i = 0; i < n; ++i) {
//        right[i][m - 1] = 0;
//        for (int j = m - 2; j >= 0; --j) {
//            if (grid[i][j + 1] == '*') {
//                right[i][j] = right[i][j + 1] + 1;
//            }
//            else {
//                right[i][j] = right[i][j + 1]; 
//            }
//        }
//    }
//
//    vector<vector<int>> up(n, vector<int>(m, 0));
//    for (int j = 0; j < m; ++j) {
//        up[0][j] = 0;
//        for (int i = 1; i < n; ++i) {
//            if (grid[i - 1][j] == '*') {
//                up[i][j] = up[i - 1][j] + 1;
//            }
//            else {
//                up[i][j] = up[i - 1][j];
//            }
//        }
//    }
//
//    vector<vector<int>> down(n, vector<int>(m, 0));
//    for (int j = 0; j < m; ++j) {
//        down[n - 1][j] = 0; 
//        for (int i = n - 2; i >= 0; --i) {
//            if (grid[i + 1][j] == '*') {
//                down[i][j] = down[i + 1][j] + 1;
//            }
//            else {
//                down[i][j] = down[i + 1][j];
//            }
//        }
//    }
//
//    ll total = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            if (grid[i][j] == '*') {
//                int horizontal = left[i][j] + right[i][j];
//                int vertical = up[i][j] + down[i][j]; 
//                total += (ll)horizontal * vertical;
//            }
//        }
//    }
//
//    cout << total << endl;
//    return 0;
//}