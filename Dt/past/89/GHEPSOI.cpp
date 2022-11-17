/**
 *	author: Lang Dat
 *	create: 05-11-2022 58:54:20
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 4 2 8 3 7
// 2 3 4 7 8   (sap xep lai)
// 4 5 7 8     (ghep 2 voi 3 tong chi phi la 0 + 2 + 3 = 5)
// 8 7 9       (ghep 4 voi 5 tong chi phi la 5 + 4 + 5 = 14)
// 15 9        (ghep 8 voi 7 tong chi phi la 14 + 8 + 7 = 29)
// 24          (ghep 15 voi 9 tong chi phi la 29 + 15 + 9 = 53)
static const int LIM = 2*1e5;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./GHEPSOI.INP", "r", stdin);
    freopen("./GHEPSOI.OUT", "w", stdout);
    #endif
    
    int n, ans = 0;
    std::cin >> n;
    std::vector<int> nums(n, -1);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    sort(nums.begin(), nums.begin() + n, greater<int>());
    while (nums.size() > 1) {
        int tmp = nums[nums.size() - 1] + nums[nums.size() - 2];
        nums.pop_back();
        nums.pop_back();
        ans += tmp;
        int ind = lower_bound(nums.begin(), nums.end(), tmp, greater<int>()) - nums.begin();
        nums.insert(nums.begin() + ind, tmp);
    }
    std::cout << ans << "";
    return 0;
}