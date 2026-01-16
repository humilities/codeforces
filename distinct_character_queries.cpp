//#include <iostream>
//#include <string>
//#include <set>
//using namespace std;
//
//const int MAXN = 1e5 + 5;
//char s[MAXN];
//set<int> posSet[26];
//
//int main() {
//    string input;
//    cin >> input;
//    int n = input.length();
//
//    for (int i = 1; i <= n; ++i) {
//        s[i] = input[i - 1];
//        posSet[s[i] - 'a'].insert(i);
//    }
//
//    int q;
//    cin >> q;
//
//    while (q--) {
//        int op;
//        cin >> op;
//
//        if (op == 1) {
//            int pos;
//            char newChar;
//            cin >> pos >> newChar;
//
//            char oldChar = s[pos];
//            posSet[oldChar - 'a'].erase(pos);
//            s[pos] = newChar;
//            posSet[newChar - 'a'].insert(pos);
//        }
//        else {
//            int l, r;
//            cin >> l >> r;
//
//            int count = 0;
//            for (int i = 0; i < 26; ++i) {
//                if (posSet[i].empty()) continue;
//                auto it = posSet[i].lower_bound(l);
//
//                if (it != posSet[i].end() && *it <= r) {
//                    count++;
//                }
//            }
//            cout << count << endl;
//        }
//    }
//    return 0;
//}