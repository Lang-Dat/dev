/**
 *	author: Lang Dat
 *	create: 20-10-2022 55:18:07
**/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./Dongnhat.INP", "r", stdin);
    freopen("./Dongnhat.OUT", "w", stdout);

    int n, prev, l = 1, r = 1, start = 1, best = 1;
    std::cin >> n;
    int nums[n];
    for (int i = 1; i <= n; i++) {
        std::cin >> nums[i];
    }
    
    for (int i = 2; i <= n; i++) {
        if (nums[i] != nums[i-1])
            start = i;

        if (i - start > best) {
            best = i - start;
            l = start;
            prev = nums[i-1];
        }
    }
    std::cout << l << " " << l + best << "\n";
    for (int i = 0; i < best + 1; i++)
        std::cout << prev << " ";
    return 0;
}