/**
 *	author : Lăng Trọng Đạt
 *	creater: 31-01-2023 21:30:49
**/
#include <iostream>
#include <algorithm>
using namespace std;

int SecondDivisor(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return i;
    }
    return n;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SecondDivisor.INP", "r", stdin);
    freopen("./SecondDivisor.OUT", "w", stdout);
    #endif

    int64_t n, tmp, ans = 0;
    std::cin >> n;
    while (std::cin >> tmp) {
        ans += SecondDivisor(tmp);
    }

    std::cout << ans << "";
    return 0;
}