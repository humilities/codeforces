#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin>>n;

	string str;
	cin>>str;

	int length=str.length();

	for(int i=0;i<=length-4;i++)
	{
		if(str.find("2026")!=string::npos) {cout<<0<<endl;return;}

		else if(str.find("2025")==string::npos) {cout<<0<<endl;return;}

		else{cout<<1<<endl;return;}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--)
	{
		solve();
	}

	return 0;
}