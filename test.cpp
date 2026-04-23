#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

const int mn=200005;
int dis[mn];

void solve() {
    int x,y;
    cin>>x>>y;

    memset(dis,-1,sizeof(dis));
    queue<int> q;
    q.push(x);
    dis[x]=0;

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        int ne[4]={cur*2,cur+1,cur/2,cur-1};
        lin(i,0,4){
            int num=ne[i];

            if(num==y)  {cout<<dis[cur]+1<<"\n"; return;}
            if(num>=0 && num<mn && dis[num]==-1){
                dis[num]=dis[cur]+1;
                q.push(num);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}