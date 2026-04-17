//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//void solve() {
//    int n, m;
//    cin >> n >> m;
//
//    vector<pair<int, int>> segments(m);
//    for (int i = 0; i < m; i++) {
//        cin >> segments[i].first >> segments[i].second;
//        segments[i].first--;
//        segments[i].second--;
//    }
//
//    int q;
//    cin >> q;
//    vector<int> changes(q);
//    for (int i = 0; i < q; i++) {
//        cin >> changes[i];
//        changes[i]--;
//    }
//
//    int answer = -1;
//
//    for (int k = 1; k <= q; k++) {
//        vector<int> a(n, 0);
//        for (int i = 0; i < k; i++) {
//            a[changes[i]] = 1;
//        }
//
//        vector<int> pre(n + 1, 0);
//        for (int i = 0; i < n; i++) {
//            pre[i + 1] = pre[i] + a[i];
//        }
//
//        bool found = false;
//        for (int i = 0; i < m; i++) {
//            int l = segments[i].first;
//            int r = segments[i].second;
//            int length = r - l + 1;
//            int ones = pre[r + 1] - pre[l];
//
//            if (ones > length / 2) {
//                found = true;
//                break;
//            }
//        }
//
//        if (found) {
//            answer = k;
//            break;
//        }
//    }
//
//    cout << answer << endl;
//}
//
//int main() {
//    int t;
//    cin >> t;
//
//    while (t--) {
//        solve();
//    }
//
//    return 0;
//}