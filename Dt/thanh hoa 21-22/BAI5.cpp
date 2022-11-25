/**
 *	author: Lăng Trọng Đạt
 *	create: 25-11-2022 30:59:15
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 1e5 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);
    #endif

    int n;
    std::cin >> n;
    //int nums[n];
    uint64_t ans = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        ans += nums[i];
    }
    sort(nums, nums + n, greater<int>());

    for (uint32_t dem = 0; dem < n - 9; dem += 10) {
        ans -= nums[dem];
    }        
    std::cout << ans << "";
    return 0;
}