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

    int n, tmp, k;
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        nums[i] = std::abs(tmp);
    }
    sort(nums, nums + n);
    for (int i = 0; i < n; i++) 
        std::cout << nums[i] << " ";
    dbm("\n")
    for (int i = 0; i < n; i++) {
        int itr = lower_bound(nums + i + 1, nums + n, nums[i] + k, [](int a, int b) -> bool {
            return a < b;
        }) - nums;
        db(i, nums[i], nums[i]+k, nums[itr], itr)
    }

    return 0;
}