/**
 *	author: Lang Dat
 *	create: 26-10-2022 17:04:16
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
    freopen("./BAI1.INP", "r", stdin);
    freopen("./BAI1.OUT", "w", stdout);

    int n;
    std::cin >> n;
    //int nums[n];
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    
    sort(nums, nums + n, greater<int>());

    int count = 1, max_cnt = nums[0];
    for (int i = 1; i < n; i++) {
        if (max_cnt == 0) break;
        max_cnt = min(max_cnt - 1, nums[i]);
        count++;
    }   
    std::cout << count << "";
    return 0;
}