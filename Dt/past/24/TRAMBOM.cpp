/**
 *	author: Lăng Trọng Đạt
 *	create: 12-12-2022 11:34:20
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 1e5 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./TRAMBOM.INP", "r", stdin);
    freopen("./TRAMBOM.OUT", "w", stdout);
    #endif

    int n, k, best = INT32_MAX;
    std::cin >> n >> k;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    sort(nums, nums + n);

    for (int i = 0; i + k - 1 < n; i++) {
        best = min(best, nums[i+k-1] - nums[i]);
    }

    std::cout << best << "";

    return 0;
}