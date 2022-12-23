/**
 *	author: Lăng Trọng Đạt
 *	create: 24-11-2022 02:11:08
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ull unsigned long long


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI4.INP", "r", stdin);
    freopen("./BAI4_trau.OUT", "w", stdout);
    #endif

    int n, minn = INT32_MAX, maxx = INT32_MIN, ans = INT32_MAX;
    std::cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
        minn = min(minn, nums[i]);
        maxx = max(maxx, nums[i]);
    }
    
    for (int i = 0; i < n; i++) {
        bool haveMax = false, haveMin = false;
        for (int j = i; j < n; j++) {
            if (nums[j] == minn) haveMin = true;
            if (nums[j] == maxx) haveMax = true;
            if (haveMax && haveMin) {
                ans = min(ans, j - i + 1);
            }
        }
    }
    std::cout << ans << "";
    return 0;
}