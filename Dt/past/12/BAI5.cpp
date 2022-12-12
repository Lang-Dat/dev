/**
 *	author: Lăng Trọng Đạt
 *	create: 04-12-2022 22:43:10
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./BAI5.INP", "r", stdin);
    freopen("./BAI5.OUT", "w", stdout);
    #endif

    int n, k, start;
    std::cin >> n >> k >> start;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    start = (start - 1) % n;
    int ans = 0;
    for (int i = start; i < start + k; i++) {
        ans += nums[i%n];
    }
    std::cout << ans << "";
    return 0;
}