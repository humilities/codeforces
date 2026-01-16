//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    map<int, int> cnt;
//
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        cnt[a[i]]++;
//    }
//
//    bool merged;
//    do {
//        merged = false;
//        map<int, int> temp = cnt;
//        for (auto& p : temp) {
//            int exp = p.first;  
//            int count = p.second; 
//            if (count >= 2) {
//                merged = true;
//                int num_pairs = count / 2;
//                int rem = count % 2;
//
//                cnt[exp] = rem;
//                if (rem == 0) {
//                    cnt.erase(exp);
//                }
//                cnt[exp + 1] += num_pairs;
//            }
//        }
//    } while (merged);
//
//    if (cnt.empty()) {
//      
//        cout << 1 << endl;
//        return 0;
//    }
//
//    int max_exp = cnt.rbegin()->first;
//    int missing = 0;
//    int last = -1; 
//
//    for (auto& p : cnt) {
//        int curr = p.first;
//        
//        if (curr > last + 1) {
//            missing += (curr - (last + 1));
//        }
//        last = curr;
//    }
//
//    //(¶µµ×£©
//    if (last < max_exp) {
//        missing += (max_exp - last);
//    }
//
//    cout << missing << endl;
//
//    return 0;
//}