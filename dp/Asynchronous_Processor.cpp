// #include <bits/stdc++.h>
// // #include<iostream>
// // #include<Bits.h>
// // #include<vector>
// // #include<algorithm>
// // #include<bitset>

// using namespace std;

// void Fast() {
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     ios_base::sync_with_stdio(false);
// }

// struct Op {
//     string op, t;
//     int x;
// };

// void solve() {
//     int n;
//     cin >> n;
//     vector<Op> ops(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> ops[i].op >> ops[i].x >> ops[i].t;
//     }
//     vector<int> summ(n + 1);
//     for (int i = 0; i < n; ++i) {
//         summ[i + 1] = summ[i];
//         if (ops[i].op == "+") {
//             summ[i + 1] += ops[i].x;
//         }
//     }
//     auto suff = [&summ](int i) {
//         return summ.back() - summ[i];
//         };

//     vector<int> aeq;
//     bitset<1000001> possible_s = 0;
//     bitset<1000001> sa = 1;
//     int sx = 0;
//     bool last_sx = true;
//     bitset<1000001> sx_sa = 1;
//     for (int i = 0; i < n; ++i) {
//         string op = ops[i].op, t = ops[i].t;
//         int x = ops[i].x;
//         if (t == "sync") {
//             if (op == "=") {
//                 sx = x;
//                 last_sx = true;
//                 sx_sa = sa << suff(i);
//                 possible_s = 0;
//             }
//             else {
//                 possible_s |= sa << suff(i);
//             }
//         }
//         else {
//             if (op == "=") {
//                 last_sx = false;
//                 aeq.emplace_back(x);
//                 possible_s = 0;
//             }
//             else {
//                 possible_s |= sa << suff(i);
//                 sa |= sa << x;
//             }
//         }
//     }
//     possible_s |= sa;

//     bitset<1000001> ans{};
//     for (int a : aeq) {
//         ans |= possible_s << a;
//     }
//     if (last_sx) {
//         ans |= sx_sa << sx;
//     }

//     cout << ans.count() << '\n';
// }

// int main() {
//     Fast();

//     int t = 1;
//     //cin >> t;
//     while (t--) {
//         solve();
//     }
// }


#include<bits/stdc++.h>

using namespace std;

struct Op{
    string op,sen;
    int val;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<Op> operations(n+1);
    for(int i=0;i<n;i++){
        cin>>operations[i].op>>operations[i].val>>operations[i].sen;
    }

    vector<int> sumn(n+1);
    for(int i=0;i<n;i++){
        sumn[i+1]=sumn[i];
        if(operations[i].op=="+"){
            sumn[i+1]+=operations[i].val;
        }
    }

    auto suff=[&sumn](int i){
        return sumn.back()-sumn[i];
    } ;

    vector<int> pos_async;
    bitset<1000005> possible_async=0;
    bitset<1000005> async_sum=1;
    int sync_x=0;
    bool last_sync=true;
    bitset<1000005> sync_sum=1;

    for(int i=0;i<n;i++){
        string op=operations[i].op;
        string sen=operations[i].sen;
        int x=operations[i].val;

        if(sen=="sync"){
            if(op=="="){
                last_sync=true;
                sync_x=x;
                sync_sum=async_sum<<suff(i);
                possible_async=0;
            }
            else{
                possible_async|=async_sum<<suff(i);
            }
        }
        else{
            if(op=="="){
                last_sync=false;
                pos_async.emplace_back(x);
                possible_async=0;
            }
            else{
                possible_async|=async_sum<<suff(i);
                async_sum|=async_sum<<x;
            }
        }
    }
    possible_async|=async_sum;

    bitset<1000005> ans;
    for(int a:pos_async){
        ans|=possible_async<<a;
    }
    if(last_sync){
        ans|=sync_sum<<sync_x;
    }

    cout<<ans.count()<<"\n";
    return 0;
}