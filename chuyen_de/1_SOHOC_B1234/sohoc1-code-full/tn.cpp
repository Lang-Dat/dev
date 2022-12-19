/**
 *	author: Lăng Trọng Đạt
 *	create: 08-12-2022 10:16:08
**/
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("./tn.INP", "r", stdin);
    freopen("./tn.OUT", "w", stdout);
    #endif

    uint64_t n,  lcm;
    std::cin >> n;
    uint64_t nums[n];
    std::cin >> nums[0];
    lcm = nums[0];
    for (int i = 1; i < n; i++) {
        std::cin >> nums[i];
        lcm = lcm*nums[i]/__gcd(nums[i], lcm);
    }
    
    std::cout << lcm << "\n";
    for (uint64_t i : nums)
        std::cout << lcm / i << " ";
    return 0;
}