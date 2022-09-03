// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int maxProfit = 0, maxRigth = INT32_MIN;

    for (int i = prices.size() - 2; i >= 0; i--)
    {
        if (prices[i+1] > maxRigth) maxRigth = prices[i+1];
        if (maxRigth - prices[i] > maxProfit) maxProfit = maxRigth - prices[i];
    }
    return maxProfit;
}

int main()
{
    // std::vector<int> nums {0, 0, 0, 0, 0};
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++) std::cin >> nums[i];

    std::cout << (maxProfit(nums));
}