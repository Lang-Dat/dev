// https://leetcode.com/problems/maximum-product-subarray/
#include <iostream>
#include <vector>
#include <algorithm>

#define log(x) std::cout << x << " ";

int maxProduct(std::vector<int>& nums) {
    int currMin = 1, currMax = 1;
    int max = *(std::max_element(nums.begin(), nums.end()));
    for (int num : nums) {
        if (num == 0) {
            currMin = 1;
            currMax = 1;
        }
        else {
            int temp = currMax * num;
            currMax = std::max(num * currMin, std::max(num * currMax, num));
            currMin = std::min(num * currMin, std::min(temp, num));
            if (currMax > max) max = currMax;
        }
    }

    return max;
}
int main()
{
    // freopen("big input.txt", "r", stdin);
    // int n;
    // std::cin >> n;
    std::vector<int> nums = {2,-5,-2,-4,3};
    // for (int i = 0; i < n; i++) std::cin >> nums[i];

    std::cout << (maxProduct(nums));
}