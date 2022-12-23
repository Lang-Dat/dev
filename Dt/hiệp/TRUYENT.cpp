#include<iostream>
#include<vector>
using namespace std;
#define ull unsigned long long

int n;
string s, pre, s1;

bool xet()
{
	pre = "";
	while(pre.size() < n) pre += s1;
	for (int i = 0; i < n; ++i)
		if (s[i] != pre[i])
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("TRUYENT.INP", "r", stdin);
	freopen("TRUYENT.OUT", "w", stdout);
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == s[0] && i != 0)
		{
			if (xet())
			{
				cout << i;
				return 0;
			}
		}
		s1 += s[i];
	}
	cout << s.size();
}