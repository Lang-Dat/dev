#include <bits/stdc++.h>

using namespace std;
int n, res;
string s;
int main()
{
    freopen("prefixes.inp","r",stdin);
    freopen("prefixes.out","w",stdout);
    cin >> n >> s;
    for (int i=0; i<s.size(); i+=2)
    if (s[i] == s[i+1])
    {
        res++;
        if (s[i] == 'a') s[i] = 'b';
        else s[i] = 'a';
    }
    cout << res << '\n';
    cout << s;
    return 0;
}
