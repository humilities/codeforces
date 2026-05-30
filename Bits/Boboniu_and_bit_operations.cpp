#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <string>
#include <set>

typedef long long ll;
using namespace std;

const int maxn = 205;
int a[maxn], b[maxn];
vector<int>C[maxn];
int n, m;

void Clear(int pos, int n) {
   for (int i = 1;i <= n;i++) {
       vector<int>tmp;
       for (int j = 0;j < C[i].size();j++) {
           int v = C[i][j];
           if ((v & (1 << pos)) == 0) {
               tmp.push_back(v);
           }
       }
       C[i].clear();
       C[i] = tmp;
   }
}

int main() {
   cin>>n>>m;
   for (int i = 1;i <= n;i++) {
       cin>>a[i];
   }
   for (int i = 1;i <= m;i++) {
       cin>>b[i];
   }
   for (int i = 1;i <= n;i++) {
       for (int j = 1;j <= m;j++) {
           C[i].push_back(a[i] & b[j]);
       }
   }

   ll ans = 0;
   for (int i = 30;i >= 0;i--) {
       int cnt = 0;
       for (int j = 1;j <= n;j++) {
           int flag = 0;
           vector<int>tmp;
           for (int k = 0;k < C[j].size();k++) { 
               int v = C[j][k];
               if ((v & (1 << i)) == 0) flag = 1;
           }
           if (flag) cnt++;
       }
       if (cnt == n) { 
           Clear(i, n);
       }
       else {
           ans |= (1 << i); 
       }
   }
   printf("%lld\n", ans);
   return 0;
}
