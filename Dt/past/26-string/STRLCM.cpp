/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 19:23:21
**/
#include <iostream>
#include <algorithm>
using namespace std;

string operator*(string &str, int n) {
    string res = "";
    for (int i = 0; i < n; i++)
        res += str;
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./STRLCM.INP", "r", stdin);
    // freopen("../../chuyen_de/4_XAU_B16_18/Xau1/STRLCM/test01/STRLCM.INP", "r", stdin);
    freopen("./STRLCM.OUT", "w", stdout);
    #endif

    int t;
    string s1, s2;
    std::cin >> t;
    while (std::cin >> s1 >> s2) {
        int lcm = s1.size()*s2.size() / __gcd(s1.size(), s2.size());
        string res = s1 * (lcm / s1.size());
        if (res == s2 * (lcm / s2.size()))
            std::cout << res << "\n";
        else std::cout << -1 << "\n";
    }

    return 0;
}