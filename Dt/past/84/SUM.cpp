/**
 *	author: Lang Dat
 *	create: 01-11-2022 03:45:19
**/
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned long long

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SUM.INP", "r", stdin);
    freopen("./SUM.OUT", "w", stdout);

    ull n, lon = 0, nho = 0, k;
    std::cin >> n >> k;
    ull nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    sort(nums, nums + n);
    // db(k, n)
    for (int l = 0, r = n - 1; l < n - k; l++, r--) {
        nho += nums[l];
        lon += nums[r];
    }

    std::cout << lon << " " << nho;
    return 0;
}