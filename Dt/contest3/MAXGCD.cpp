/**
 *	author: Lăng Trọng Đạt
 *	create: 26-11-2022 36:34:21
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const int LIM = 2005;
int nums[LIM], prefix[LIM], suffix[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./MAXGCD.INP", "r", stdin);
    freopen("./MAXGCD.OUT", "w", stdout);
    #endif

    int n, ans = 0;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    for (int l = 0, r = n - 1; l < n; l++, r--) {
        for (int i = 0; i < l; i++) {
            prefix[l] = max(prefix[l], __gcd(nums[l], nums[i]));
        }
        for (int i = n - 1; i > r; i--) {
            suffix[r] = max(suffix[r], __gcd(nums[r], nums[i]));
        } 
    }

    for (int i = 0; i < n; i++) {
        ans = max(suffix[i+1] + prefix[i], ans);
    }

    std::cout << ans << "";

    return 0;
}