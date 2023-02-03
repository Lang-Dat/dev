/**
 *	author : Lăng Trọng Đạt
 *	creater: 30-01-2023 14:02:43
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int tong_uoc[LIM];

void tinh_tong_uoc() {
    for (int i = 1; i < LIM; i++) {
        for (int j = 1; j * i < LIM; j++)
            tong_uoc[i*j] += i;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./SPP.INP", "r", stdin);
    freopen("./SPP.OUT", "w", stdout);
    #endif

    tinh_tong_uoc();

    int a, b, ans = 0;
    std::cin >> a >> b;

    for (int i = a; i <= b; i++) {
        ans += tong_uoc[i] > 2 * i;
    }

    std::cout << ans << "";
    return 0;
}