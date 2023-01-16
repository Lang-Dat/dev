/**
 *	author: Lăng Trọng Đạt
 *	create: 31-12-2022 41:27:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

string strs[1005];

int LCP(string s1, string s2, int best) {
    // longest common prefix
    int n = min(s1.size(), s2.size());

    for (int i = 1; i <= best and i < n; i++) {
        if (s1[s1.size() - i] != s2[s2.size() - i]) 
            return i - 1;
    }
    return n;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./LYRICS.INP", "r", stdin);
    freopen("./LYRICS.OUT", "w", stdout);
    #endif

    int n, m;
    string str;
    std::cin >> n >> m;
    getline(cin, str);
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        strs[i] = str;
    }

    int best = strs[0].size();

    for (int i = 0; i + m < n and best > 0; i++) {
        best = min(best, LCP(strs[i], strs[i+m], best));
    }

    std::cout << best << "";
    return 0;
}