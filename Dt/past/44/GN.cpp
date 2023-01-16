/**
 *	author: Lăng Trọng Đạt
 *	create: 03-01-2023 03:24:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
int m;

int counting(int start) {
    int count = 0;
    for (int i = 0, j = start; i < m; i++, j++)
        count += (t[i] == s[j]);

    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./GN.INP", "r", stdin);
    freopen("./GN.OUT", "w", stdout);
    #endif

    std::cin >> t >> s;
    
    m = t.size();
    int ans = 0;

    for (int i = 0; i + m <= s.size(); i++)
        ans += counting(i);

    std::cout << ans << "";

    return 0;
}