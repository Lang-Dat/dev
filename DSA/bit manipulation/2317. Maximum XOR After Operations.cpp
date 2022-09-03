// https://leetcode.com/problems/maximum-xor-after-operations/
#include <math.h>
#include <iostream>
#include <bitset>
#include <vector>

int maximumXOR(std::vector<int>& nums) {
    std::vector<bool> table(17, false);
    int ans = 0;
    for (int num : nums)
    {
        for (int i = 0; i < 17; i++)
        {
            if (num & (1 << i)) {
                table[i] = true;
            }
        }
    }
    for (int i = 0; i < 17; i++)
        if (table[i])
            ans += std::pow(2, i);

    return ans;
}

int main() {
    freopen("random test.txt", "r", stdin);
    int max = 0, n;
    while (std::cin >> n)
    {
        if (n > max) max = n;
    }
    log(max);
    // std::vector<int> nums = {3, 2, 4, 6};
    // int ans = maximumXOR(nums);
    // log(ans); 
    // int n = 6;
    // int x = ~(1 << 2); 
    // n &= x;
    // log((std::bitset<4>(x)));
    // log((std::bitset<4>(n)));
}