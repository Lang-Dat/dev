/**
 *	author : Lăng Trọng Đạt
 *	creater: 15-01-2023 08:05:02
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 2*1e5 + 5;
static int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./DARR.INP", "r", stdin);
    freopen("./DARR.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    sort(nums, nums + n);
    int best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 2, ind = i; ind != n and best < nums[i] - 1; j++) {
            ind = lower_bound(nums + ind + 1, nums + n, nums[i] * j) - nums;
            best = max(best, nums[ind - 1] % nums[i]);
        }
    }
    std::cout << best << "";
    return 0;
}