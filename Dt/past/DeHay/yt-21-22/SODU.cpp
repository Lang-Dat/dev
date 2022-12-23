/**
 *	author: Lang Dat
 *	create: 15.10.2022 17.48.15
**/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int LIM = 2*1e5 + 5;
int nums_tmp[LIM];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./SODU.INP", "r", stdin);
    freopen("./SODU.OUT", "w", stdout);

    int n, best = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums_tmp[i];
    }
    
    sort(nums_tmp, nums_tmp + n, greater<int>());
    std::vector<int> nums;
    nums.reserve(2*1e5);
    nums.push_back(nums_tmp[0]);
    for (int i = 1; i < n; i++) {
        if (nums_tmp[i] != nums_tmp[i-1]) nums.push_back(nums_tmp[i]); 
    }   
    n = nums.size();
    for (int i = 0; i < n && best < nums[i]; i++) {
        for (int j = i + 1; j < n && best < nums[j]; j++) {
            best = max(best, nums[i] % nums[j]);
        }
    }
    std::cout << best;
    return 0;
}