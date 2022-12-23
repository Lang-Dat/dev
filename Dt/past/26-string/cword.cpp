/**
 *	author: Lăng Trọng Đạt
 *	create: 14-12-2022 19:33:21
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./cword.INP", "r", stdin);
    // freopen("../../chuyen_de/4_XAU_B16_18/Xau1/CWORD/test01/cword.INP", "r", stdin);
    freopen("./cword.OUT", "w", stdout);
    #endif

    int64_t w = 0, c = 0, ans = 0;
    int n;
    string str;
    std::cin >> n >> str;

    for (char c : str)
        w += c == 'W';
    for (char x : str) {
        if (x == 'C') c++;
        else if (x == 'W') w--;
        else ans += c * w;
    }

    std::cout << ans << "";

    return 0;
}