/**
 *	author: Lăng Trọng Đạt
 *	create: 29-12-2022 35:33:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e6 + 5;
static int l[LIM], r[LIM];
int n, c_l = 0, c_r = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./PARADE.INP", "r", stdin);
    freopen("./PARADE.OUT", "w", stdout);
    #endif

    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> l[i] >> r[i];
        c_l += l[i];
        c_r += r[i];
    }

    int ans = INT32_MAX;
    for (int i = 0; i < n; i++) {
        if (std::abs(c_l - c_r - 2*l[i]) < ans)
            ans = std::abs(c_l - c_r - 2*l[i]);
        if (std::abs(c_r - c_l - 2*r[i]) < ans)
            ans = std::abs(c_r - c_l - 2*r[i]);
    }
    std::cout << ans << "";
    return 0;
}