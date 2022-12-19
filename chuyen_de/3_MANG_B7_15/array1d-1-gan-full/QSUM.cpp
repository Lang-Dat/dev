/**
 *	author: Lăng Trọng Đạt
 *	create: 17-12-2022 24:16:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
static int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./QSUM.INP", "r", stdin);
    freopen("./QSUM.OUT", "w", stdout);
    #endif

    int n, q, l, r;
    std::cin >> n >> q;
    //int nums[n + 1];
    nums[0] = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
        nums[i] += nums[i-1];
    }
        
    while (std::cin >> l >> r)
        std::cout << nums[r] - nums[l-1] << "\n";
    return 0;
}