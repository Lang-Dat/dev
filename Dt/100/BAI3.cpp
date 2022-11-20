/**
 *	author: Lang Dat
 *	create: 18-11-2022 39:09:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

static const int LIM = 3 * 1e5 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);
    #endif

    int n, r, ans = 0;
    std::cin >> n >> r;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(nums + i + 1, nums + n, nums[i] + r + 1) - nums;
        ans += n - ind;
    }
    std::cout << ans << "";
    return 0;
}