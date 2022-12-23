/**
 *	author: Lang Dat
 *	create: 13.10.2022 05.42.18
**/
#include <iostream>

#define ull unsigned long long
const int LIM = 5 * 1e5 + 5;
const ull MOD = 1e18;
int nums[LIM];

inline ull multi(ull a, ull b) {
    return ((ull)a * (ull)b) % MOD;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./NORMA.INP", "r", stdin);
    freopen("./NORMA.OUT", "w", stdout);

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    ull sum = 0;
    for (int i = 0; i < n; i++) {
        sum += multi(nums[i],nums[i]);
        for (int j = i + 1, max = nums[i], min = nums[i], L = 2; j < n; j++, L++) {
            max = std::max(nums[j], max);
            min = std::min(nums[j], min);
            sum += multi(multi(max, min), L);
        }
    }
    ull m = 1e9;
    std::cout << sum % m;
    return 0;
}