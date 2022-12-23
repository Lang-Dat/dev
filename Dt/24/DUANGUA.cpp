/**
 *	author: Lăng Trọng Đạt
 *	create: 12-12-2022 46:30:20
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
    freopen("./DUANGUA.INP", "r", stdin);
    freopen("./DUANGUA.OUT", "w", stdout);
    #endif

    int n, k, ans = 0;
    std::cin >> k >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    sort(nums, nums + n, greater<int>());
        
    for (int i = 0; k > 0 ; i += 2, k--) {
        ans += nums[i] * nums[i+1];
    } 

    std::cout << ans << "";
    return 0;
}