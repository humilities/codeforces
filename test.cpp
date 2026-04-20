#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

vector<int> mask;
bool rea[66000];

void initb(){
    lin(i,0,4){
        int ma=0;
        lin(j,0,4) ma|=(1<<(i*4+j));

        mask.push_back(ma);
    }

    lin(j,0,4){
        int ma=0;
        lin(i,0,4) ma|=(1<<(i*4+j));

        mask.push_back(ma);
    }

    lin(i,0,3){
        lin(j,0,3){
            int ma=0;
            ma|=(1<<(i*4+j));
            ma|=(1<<(i*4+j+1));
            ma|=(1<<((i+1)*4+j));
            ma|=(1<<((i+1)*4+j+1));

            mask.push_back(ma);
        }
    }
}

void bfs(){
    rea[0]=true;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        auto to=q.front();
        q.pop();

        for(auto ma:mask){
            int ne=to^ma;
            if(!rea[ne]){
                rea[ne]=true;
                q.push(ne);
            }
        }
    }
}

int tob(string s){
    int res=0;
    lin(i,0,16) if(s[i]=='1') res|=(1<<i);

    return res;
}

void solve() {
    string s1,s2;
    cin>>s1>>s2;

    int tar1=tob(s1);
    int tar2=tob(s2);

    if(rea[tar1^tar2]) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    initb();
    bfs();

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}