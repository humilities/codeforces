//#include<iostream>
//using namespace std;
//long long num[500005] = { 0 };
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> num[i];
//		if (i > 0)num[i] = num[i] + num[i - 1];
//	}
//	long long ans = 0;
//	int cnt = 0;
//	if (num[n - 1] % 3 == 0)
//	{
//		for (int i = 0;i < n - 1;i++)
//		{
//
//			if (num[i] == num[n - 1] / 3 * 2)
//				ans += cnt;
//			if (num[i] == num[n - 1] / 3)
//			{
//				cnt++;
//			}
//		}
//	}
//
//	cout << ans << endl;
//	return 0;
//}