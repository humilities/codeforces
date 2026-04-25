#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

struct card{
    int id;
    int tp;
};

void solve() {
  int n,m;
  cin>>n>>m; 
  
  vector<card> ca(n+1);
  lin(i,1,n+1){
    string s;
    cin>>s;

    ca[i].tp=s[0]-'A';
    ca[i].id=stoi(s.substr(1));
  }

  vector<vector<int>> cnt(m+1,vector<int>(5,0));
  vector<int> co(m+1,0);

  int num=0;
  int len=n+1;
  int al=1,ar=n;

  int l=1;
  lin(r,1,n+1){
    int id=ca[r].id;
    int ty=ca[r].tp;

    if(cnt[id][ty]==0){
        co[id]++;

        if(co[id]==5) num++;
    }

    cnt[id][ty]++;
    while(num){
        if(r-l+1<len){
            len=r-l+1;
            al=l;
            ar=r;
        }

        int lid=ca[l].id;
        int lty=ca[l].tp;

        cnt[lid][lty]--;
        if(cnt[lid][lty]==0){
            if(co[lid]==5) num--;

            co[lid]--;
        }

        l++;
    }
  }


  cout<<al<<" "<<ar<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int t;
    //cin >> t;

    //while (t--)
        solve();

    return 0;
}