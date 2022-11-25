/**
 *	author: Lăng Trọng Đạt
 *	create: 25-11-2022 20:38:15
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ull unsigned long long

static const int LIM = 1e5 + 5;
int nums[LIM];
bool isUse[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI3.INP", "r", stdin);
    freopen("./BAI3.OUT", "w", stdout);
    #endif

    uint64_t n, k, ans = 0;
    std::cin >> n >> k;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    sort(nums, nums + n);
    for (int i = n - 1; i > 0; i--) {
        if (isUse[i]) continue;
        int ind = upper_bound(nums, nums + i, nums[i] - k + 1) - nums - 1;        
        while (ind >= 0 && isUse[ind]) ind--;
        if (ind < 0) break;
        ans += (uint64_t)nums[i];
        isUse[i] = true;
        isUse[ind] = true;
    }
    for (int i = 0; i < n; i++)
        if (!isUse[i]) ans += (uint64_t)nums[i];
    std::cout << ans << "";
    return 0;
}