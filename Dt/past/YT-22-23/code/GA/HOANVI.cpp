#include <iostream>
#include <algorithm>
using namespace std;

bool check(string s)
{
	sort(s.begin(), s.end());
	int len = s.size();
	for (int i = 1 ; i < len ; ++i)
		if (int(s[i])!=int(s[i-1])+1) return false;
	return true;
}

string catxau(int l, int r, string s)
{
	string ans = "";
	for (int i = l ; i <= r ; ++i)
		ans += s[i];
	return ans;
}

int main()
{
    freopen("./HOANVI.INP", "r", stdin);
    freopen("./HOANVI.OUT", "w", stdout);
	string s, result = ""; cin >> s;
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		for (int j = i ; j < len ; ++j)
		{
			string ns = catxau(i,j,s);
			if (ns.size() > result.size() && check(ns))
				result = ns; 
		}
	}
	cout << result;
}