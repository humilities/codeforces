#include <bits/stdc++.h>

#define lin(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
using ll = long long;

int f(string& s,int pos){
    int cnt=0;

    lin(i,pos,s.length()){
        if(s[i]=='(') cnt++;
        else if(s[i]==')') cnt--;

        if(cnt==0) return i;
    }

    return -1;
}

ll solve(string s) {
    if(s.length()==1) return s[0]-'0';
    //if(s.length()==3 && s[0]=='(' && s[2]==')') return s[1]-'0';

    ll sum=0;
    int idx=0;
    while(idx<s.length()){
        if(s[idx]=='('){
            int r=f(s,idx);
            sum+=solve(s.substr(idx+1,r-idx-1));

            idx=r+1;
        }else if(isdigit(s[idx]))
            sum+=s[idx]-'0',idx++;
        else idx++;
    }

    return sum*sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //int t;
    //cin >> t;

    //while (t--)
    string s;
    while(cin>>s)
        cout<<solve(s)<<"\n";

    return 0;
}