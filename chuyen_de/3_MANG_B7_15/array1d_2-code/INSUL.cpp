/**
 *	author: Lăng Trọng Đạt
 *	create: 21-12-2022 25:37:19
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
    freopen("./INSUL.INP", "r", stdin);
    freopen("./INSUL.OUT", "w", stdout);
    #endif

    int n;
    int64_t sum = 0;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        sum += nums[i];
    }
    sort(nums, nums + n);

    for (int l = 0, r = n - 1; l < r; l++, r--)
        sum += nums[r] - nums[l];
    std::cout << sum << "";

    return 0;
}