/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 05:18:08
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);
    #endif

    int n;
    string str;
    std::cin >> n >> str;

    int ans = 0, count = 0;
    for (char i : str) {
        if (i == '1') {
            ans += ++count;
        } else count = 0;
    }

    std::cout << ans << "";
    return 0;
}