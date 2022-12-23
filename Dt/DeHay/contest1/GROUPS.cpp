/**
 *	author: Lang Dat
 *	create: 15.10.2022 31.45.16
**/
#include <iostream>
#include <algorithm>
using namespace std;

const int LIM = 1e5 + 5;
int nums[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./GROUPS.INP", "r", stdin);
    freopen("./GROUPS.OUT", "w", stdout);

    int n, tmp, k, count = 0;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        nums[i] = std::abs(tmp);
    }
    sort(nums, nums + n);
    for (int i = 0; i < n; count++) {
        int next = upper_bound(nums + i + 1, nums + n, nums[i] + k) - nums;
        i = next;
    }

    std::cout << count;
    return 0;
}