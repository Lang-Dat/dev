/**
 *	author: Lang Dat
 *	create: 12.10.2022 52.11.19
**/
// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("./TACHSO.INP", "r", stdin);
    freopen("./TACHSO.OUT", "w", stdout);

    
    string str, tmp = "";
    vector<string> ans;
    getline(cin, str, '\0');
    for (int i = 0; i < str.size(); i++) { 
        if (str[i] >= '0' && str[i] <= '9')
            tmp += str[i];
        else if (!tmp.empty()) {
            ans.push_back(tmp);
            tmp = "";
        }
    }
    if (!tmp.empty()) ans.push_back(tmp);
    for (string a : ans)
        cout << a << "\n";
    if (ans.empty())
        cout << "No";

    return 0;
}