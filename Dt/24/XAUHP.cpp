/**
 *	author: Lăng Trọng Đạt
 *	create: 12-12-2022 14:24:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string &str) {
    for (int l = 1, r = str.size() - 1 - 1; l < str.size(); l++, r--) {
        if (std::abs(str[l] - str[l-1]) != std::abs(str[r] - str[r+1]))
            return false;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./XAUHP.INP", "r", stdin);
    freopen("./XAUHP.OUT", "w", stdout);
    #endif

    int n;
    string str;
    std::cin >> n;
    while (std::cin >> str) {
        std::cout << (check(str) ? "YES" : "NO") << "\n";
    }

    return 0;
}