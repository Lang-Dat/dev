/**
 *	author: Lang Dat
 *	create: 20-10-2022 17:36:07
**/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./BAI2.INP", "r", stdin);
    freopen("./BAI2.OUT", "w", stdout);

    int best = 0;
    std::vector<int> nums;
    char tmp;
    
    while (std::cin >> tmp) {
        int num = tmp - '0';
        if (0 <= num && num <= 9) {
            nums.push_back(num);
        }
    }

    for (int i = 1, prev = -1; i <= 4; i++) {
        int ind = max_element(nums.begin() + prev + 1, nums.end() - 4 + i) - nums.begin();
        best = best * 10 + nums[ind];
        prev = ind;
    }
    std::cout << best;
    return 0;
}