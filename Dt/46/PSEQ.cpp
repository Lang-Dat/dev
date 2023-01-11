#pragma GCC optimize("O2")
#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("./PSEQ.INP", "r", stdin);
    freopen("./PSEQ.OUT", "w", stdout);

    int64_t n, k, tmp, currSum = 0, res = 0;
    std::unordered_map<int64_t, int64_t> prevSum;
    std::cin >> n >> k;
    while (n--)
    {   
        std::cin >> tmp;
        currSum += tmp;
        if (currSum == k) res++;
        if (prevSum.count(currSum - k))
            res += prevSum[currSum-k];
        prevSum[currSum]++;
    }
    
    std::cout << res;
    return 0;
}