//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main() {
//	int length;
//	//int minus;
//	cin >> length;
//
//	vector<int> a(length);
//
//	for (int i = 0;i < length;i++) {
//		cin >> a[i];
//
//		if (i >= 1) {
//			if (a[i] - a[i - 1] >= 2) {
//				cout << "NO" << endl;
//				break;
//			}
//		}
//	}
//
//
//	bool flag = true;
//	while (!a.empty()) {
//		int height_val = 0;
//		int height_idx = -1;
//
//		for (int i = 0;i < length;i++) {
//			if (a[i] > height_val) {
//				height_val = a[i];
//				height_idx = i;
//			}
//		}
//
//		if (height_idx > 0 && height_idx < length - 1) {
//			if (abs(a[height_idx - 1] - a[height_idx + 1]) >= 2) {
//				flag = false;
//				break;
//			}
//
//			if (abs(a[height_idx] - a[length - 1]) >= 2) {
//				flag = false;
//				break;
//			}
//		}
//
//		if (height_idx != -1) {
//			a.erase(a.begin() + height_idx);
//		}
//	}
//
//	if (!flag) {
//		cout << "NO" << endl;
//	}
//
//	else {
//		cout << "YES" << endl;
//	}
//
//	return 0;
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    vector<int> stacks = a;
//    vector<int> output;
//
//    while (!stacks.empty()) {
//        bool changed;
//        do {
//            changed = false;
//            for (int i = 0; i < stacks.size() - 1; ++i) {
//                if (abs(stacks[i] - stacks[i + 1]) >= 2) {
//                    changed = true;
//                    if (stacks[i] > stacks[i + 1]) {
//                        stacks[i]--;
//                        stacks[i + 1]++;
//                    }
//                    else {
//                        stacks[i]++;
//                        stacks[i + 1]--;
//                    }
//                }
//            }
//        } while (changed);
//
//        int max_height = *max_element(stacks.begin(), stacks.end());
//        int idx = find(stacks.begin(), stacks.end(), max_height) - stacks.begin();
//
//        output.push_back(stacks[idx]);
//        stacks.erase(stacks.begin() + idx);
//    }
//
//    vector<int> sorted_a = a;
//    sort(sorted_a.begin(), sorted_a.end());
//    vector<int> reversed_sorted(sorted_a.rbegin(), sorted_a.rend());
//
//    if (output == reversed_sorted) {
//        cout << "YES" << endl;
//    }
//    else {
//        cout << "NO" << endl;
//    }
//
//    return 0;
//}