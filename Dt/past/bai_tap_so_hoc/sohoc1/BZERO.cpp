/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 23:25:16
**/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt2 = 0, cnt5 = 0;

void phanTich2(int i) {
    while (i % 2 == 0) {
        i /= 2;
        cnt2++;
    }
}
void phanTich5(int i) {
    while (i % 5 == 0) {
        i /= 5;
        cnt5++;
    }
}
void solve1(int n) {
        for (int i = 1; i <= n; i++) {
            phanTich2(i); phanTich5(i);
        }
        // db(cnt2, cnt5)
        std::cout << min(cnt2, cnt5) << "";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BZERO.INP", "r", stdin);
    freopen("./BZERO.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;

    solve1(n);
    return 0;
}