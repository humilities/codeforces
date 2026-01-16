#include <iostream>

using namespace std;
{
  int n;
  cin>>n;

	if(n==2) cout<<2<<endl;
	else if(n==3) cout<<3<<endl;
	else if(n>=4 && n&1) cout<<1<<endl;
	else cout<<0<<endl;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	while(t--)
	{
		solve();
  }

  return 0;
}

