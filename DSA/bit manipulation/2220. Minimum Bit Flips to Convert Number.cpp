#include <math.h>
#include <iostream>
#include <bitset>
#include <vector>

std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
    int currXOR = 0, last = nums.size() - 1;
    int add, maxK = std::pow(2, maximumBit);
    std::vector<int> ans(last + 1);

    for (int num : nums) currXOR ^= num;

    while (last >= 0)
    {
        int k = 0;
        for (int i = 0; i < 32; i++)
        {
            if (!(currXOR & (1 << i))) {
                add = std::pow(2, i);
                if (k + add < maxK) k += add;
                else break;
            }
        }
        // ans.push_back(k);
        ans[nums.size() - 1 - last] = k;
        // log(currXOR) log((std::bitset<4>(currXOR))) log(k) log((std::bitset<4>(currXOR))) logl(last);           
        currXOR ^= nums[last];
        last--; 
    }
    return ans;    
}

int main() {
    std::vector<int> nums = {0, 1, 1, 3}; 
    int maximumBit = 2;
    auto ans = getMaximumXor(nums, maximumBit);
    log(ans); // [0,3,2,3]
}