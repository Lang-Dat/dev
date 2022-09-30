#pragma GCC optimize("O3")

#include <iostream>
#include <map>
using namespace std;
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("BAI2.INP", "r", stdin);
	freopen("BAI2.OUT", "w", stdout);
	string s; getline(cin, s);
	map<char, int> mp;
	int len = s.size();
	for (int i = 0 ; i < len ; ++i)
		mp[toupper(s[i])]++;
	cout << mp.size() << "\n";
	for (pair<char, int> it : mp)
		cout << it.first << " " << it.second << "\n";
}