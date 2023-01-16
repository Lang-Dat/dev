/**
 *	author: Lăng Trọng Đạt
 *	create: 31-12-2022 26:41:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 5*1e5 + 5;
static int64_t pre_sum[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./GROWING.INP", "r", stdin);
    freopen("./GROWING.OUT", "w", stdout);
    #endif

    int n, d, l, r, k;

    std::cin >> n >> d;
    while (std::cin >> l >> r >> k) {
        pre_sum[l] += k;
        pre_sum[r+1] -= k;
    }

    for (int i = 1; i <= n; i++) {
        pre_sum[i] += pre_sum[i-1];
        std::cout << pre_sum[i] << " ";
    }
    return 0;
}