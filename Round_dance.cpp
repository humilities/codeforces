//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int n;
//        cin >> n;
//        vector<int> a(n);
//        for (int i = 0; i < n; i++) {
//            cin >> a[i];
//            a[i]--;
//        }
//
//        vector<bool> vis(n, false);
//        int components = 0;
//        bool has_chain = false;
//
//        for (int i = 0; i < n; i++) {
//            if (!vis[i]) {
//                components++;
//                int cur = i;
//                while (!vis[cur]) {
//                    vis[cur] = true;
//                    cur = a[cur];
//                }
//            }
//        }
//
//        // 检查是否有"链"结构（非双向边）
//        for (int i = 0; i < n; i++) {
//            if (a[a[i]] != i) {
//                has_chain = true;
//                break;
//            }
//        }
//
//        int max_dances = components;
//        int min_dances = components;
//
//        if (has_chain) {
//            min_dances = components - 1;
//            if (min_dances < 1) min_dances = 1;
//        }
//
//        cout << min_dances << " " << max_dances << "\n";
//    }
//    return 0;
//}