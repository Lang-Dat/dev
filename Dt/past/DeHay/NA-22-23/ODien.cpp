/**
 *	author: Lang Dat
 *	create: 23-10-2022 07:14:15
**/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./ODien.INP", "r", stdin);
    freopen("./ODien.OUT", "w", stdout);

    int n, m, count = 0, tmp;
    std::cin >> n >> m;
    int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        nums[i] = tmp-1;
    }
    std::sort(nums, nums + n, std::greater<int>());
    nums[0]++;
    for (int i = 0; i < n && m > 0; i++, count++)
        m -= nums[i];
    if (m > 0) std::cout << -1;
    else std::cout << count;


    return 0;
}