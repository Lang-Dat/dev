/**
 *	author: Lăng Trọng Đạt
 *	create: 18-12-2022 31:20:08
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e6 + 5;
static int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);
    #endif

    int n, m;
    std::cin >> n >> m;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
        
    int64_t best = 0;
    for (int l = 0, r = n - 1; l <= r and m > 0; m--) {
        (nums[l] < nums[r]) ? best += nums[r--] : best += nums[l++];
    }
    std::cout << best << "";
    return 0;
}