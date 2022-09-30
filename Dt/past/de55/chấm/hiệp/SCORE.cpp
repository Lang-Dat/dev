#pragma GCC optimize("O3")

#include <iostream>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
string s1, s2;
string tmp;
int n;
int L[(int)1e4][(int)1e4];
int LCS()
{
	int len = n;
	for (int i = 0 ; i <= len ; ++i)
		for (int j = 0 ; j <= len ; ++j)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else
			{
				if (s1[i - 1] == s2[j - 1])
					L[i][j] = L[i - 1][j - 1] + 1;
				else
					L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
		}
	return L[len][len];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
		freopen("SCORE.INP", "r", stdin);
		freopen("SCORE.OUT", "w", stdout);
	cin >> n;
	for (int i = 1 ; i <= n ; ++i)
	{
		cin >> tmp;
		s1 += tmp;
	}
	for (int i = 1 ; i <= n ; ++i)
	{
		cin >> tmp;
		s2 += tmp;
	}
	// cout << LCS();
	cout << s1;
}