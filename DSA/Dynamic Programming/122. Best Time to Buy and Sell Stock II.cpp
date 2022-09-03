// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    bool canBuy = true;
    int sum = 0, prevPrice;

    for (int i = 0; i < prices.size() - 1; i++)
    {
        if (!canBuy && prices[i] > prevPrice)
        {
            sum += prices[i];
            prevPrice = prices[i];
            canBuy = true;
            continue;
            // log(prevPrice);
        }
        while (canBuy && i < prices.size() - 1) 
        {
            if (prices[i] < prices[i+1]) {
                prevPrice = prices[i];
                sum -= prices[i];
                canBuy = false;
                // log(prevPrice);
            }
            else /* prices[i] > prices[i+1] */
                i++;
        }
    }

    return sum;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n);

    for (int i = 0; i < nums.size(); i++) std::cin >> nums[i];

    std::cout << (maxProfit(nums));
}