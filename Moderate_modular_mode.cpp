//#include <iostream>
//using namespace std;
//
//typedef long long ll;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int t;
//    cin >> t;
//    while (t--) {
//        ll x, y;
//        cin >> x >> y;
//
//        ll n;
//        if (y < x) {
//            n = x + y;
//        }
//        else {
//            if (y % x == 0) {
//                n = x;
//            }
//            else {
//                n = y - (y % x) / 2;
//            }
//        }
//
//        cout << n << "\n";
//    }
//
//    return 0;
//}